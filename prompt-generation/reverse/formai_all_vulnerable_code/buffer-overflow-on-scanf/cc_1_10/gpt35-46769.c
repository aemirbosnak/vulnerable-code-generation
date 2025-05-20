//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to find the minimum of three numbers 
int min(int a, int b, int c) {
    if (a < b && a < c) return a;
    if (b < a && b < c) return b;
    return c;
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(char *str1, char *str2) {

    // Length of strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Create dynamic programming table
    int dp[len1+1][len2+1];

    // Initialize first row and column of the table
    for(int i=0; i<=len1; i++) dp[i][0] = i;
    for(int j=0; j<=len2; j++) dp[0][j] = j;

    // Calculate distance using dynamic programming
    for(int i=1; i<=len1; i++) {
        for(int j=1; j<=len2; j++) {
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]);
        }
    }

    // Return the Levenshtein Distance
    return dp[len1][len2];
}

int main () {

    // Take two strings as input
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    // Calculate the Levenshtein Distance and print the result
    int distance = levenshteinDistance(str1, str2);
    printf("The Levenshtein Distance between \"%s\" and \"%s\" is %d", str1, str2, distance);

    return 0;
}