//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

// Function to calculate the minimum of three numbers
int min(int a, int b, int c){
    if(a<b && a<c)
        return a;
    else if(b<c)
        return b; 
    else
        return c;
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(char *str1, char *str2){

    // lengths of two strings
    int m = strlen(str1);
    int n = strlen(str2);
    
    // Matrix to store the distances between substrings
    int dist[m+1][n+1];

    // Initializing the first row and first column of the matrix
    for(int i=0; i<=m; i++)
        dist[i][0]=i;
    for(int j=0; j<=n; j++)
        dist[0][j]=j;

    // Filling the matrix row by row
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(str1[i-1]==str2[j-1])
                dist[i][j]=dist[i-1][j-1];
            else{
                int ins = dist[i][j-1];
                int del = dist[i-1][j];
                int sub = dist[i-1][j-1];
                dist[i][j] = 1+min(ins, del, sub);
            }
        }
    }
    return dist[m][n];
}

// Main Function
int main(void){
    char str1[100], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    int ans = levenshteinDistance(str1, str2);

    printf("\nLevenshtein Distance between \"%s\" and \"%s\" is: %d", str1, str2, ans);

    return 0;
}