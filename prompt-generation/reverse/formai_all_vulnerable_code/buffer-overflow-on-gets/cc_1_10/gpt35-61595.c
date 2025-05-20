//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: high level of detail
#include<stdio.h>
#include<string.h>

// Function to find the minimum of three numbers
int min(int a, int b, int c){
    if(a<b){
        if(a<c)
            return a;
        else
            return c;
    }
    else{
        if(b<c)
            return b;
        else
            return c;
    }
}

// Function to calculate the Levenshtein Distance
int levenshtein_distance(char* str1, char* str2){
    int m = strlen(str1);
    int n = strlen(str2);
    int mat[m+1][n+1];
    
    // initializing the matrix
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0)
                mat[i][j] = j;
            else if(j==0)
                mat[i][j] = i;
            else if(str1[i-1]==str2[j-1])
                mat[i][j] = mat[i-1][j-1];
            else
                mat[i][j] = 1 + min(mat[i][j-1], mat[i-1][j], mat[i-1][j-1]);
        }
    }
    
    return mat[m][n];
}

int main(){
    char str1[50], str2[50];
    printf("Enter the first string: ");
    gets(str1);
    printf("Enter the second string: ");
    gets(str2);
    int distance = levenshtein_distance(str1, str2);
    printf("The Levenshtein Distance between '%s' and '%s' is %d", str1, str2, distance);
    return 0;   
}