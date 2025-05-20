//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate minimum of three numbers
int min(int a, int b, int c){
    if(a < b && a < c){
        return a;
    }
    else if(b < a && b < c){
        return b;
    }
    else{
        return c;
    }
}

// Function to calculate levenshtein distance between two strings
int levenshteinDistance(char *str1, char *str2){
    int len1 = strlen(str1), len2 = strlen(str2);
    int dp[len1+1][len2+1]; // 2D array to store values
    
    // Initializing the first row and column
    for(int i=0;i<=len1;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=len2;j++){
        dp[0][j] = j;
    }
    
    // Finding minimum distance
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
            }
        }
    }
    
    // Returning the final result
    return dp[len1][len2];
}

// Main function
int main(){
    char str1[100], str2[100];
    printf("Enter string 1: ");
    scanf("%s", str1);
    printf("Enter string 2: ");
    scanf("%s", str2);
    int distance = levenshteinDistance(str1, str2);
    printf("The levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, distance);
    return 0;
}