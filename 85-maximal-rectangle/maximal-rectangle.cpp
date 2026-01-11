class Solution {
private:
int largest(vector<int> &height){
    int ans=0;
    int idx=0;
    stack<int> st;
    int n=height.size();
    for(int i=0;i<n;i++){
        while(!st.empty() && height[st.top()]>height[i]){
            idx=st.top();
            st.pop();
            if(!st.empty()){
                ans=max(ans,height[idx]*(i-st.top()-1));
            }else{
                ans=max(ans,height[idx]*i);
            }
        }
        st.push(i);
    }
    while(!st.empty()){
        idx=st.top();
        st.pop();
        if(!st.empty()){
            ans=max(ans,height[idx]*(n-st.top()-1));
        }else{
            ans=max(ans,height[idx]*n);
        }
    }
    return ans;
}
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int> height(c,0);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]=='0'){
                    height[j]=0;
                }else{
                    height[j]+=1;
                }
            }
            ans=max(ans,largest(height));
        }
        return ans;
    }
};