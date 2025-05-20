//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: detailed
#include <stdio.h>
#include <string.h>

// Function to calculate minimum of three values
int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}

// Function to calculate Levenshtein Distance
int levenshteinDistance(char *s1, char *s2, int len1, int len2)
{
    // Create a 2D array to store subproblems
    int dp[len1 + 1][len2 + 1];
    
    // Fill the first row and column with base cases
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }
    
    // Fill the rest of the array
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // If the last characters match, no operation is required
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Find minimum of insert, delete and replace operations
                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }
    
    // Return the final value in the array
    return dp[len1][len2];
}

int main() {
    char s1[100], s2[100];
    printf("Enter first string: ");
    gets(s1);
    printf("Enter second string: ");
    gets(s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dist = levenshteinDistance(s1, s2, len1, len2);
    printf("Levenshtein Distance between \"%s\" and \"%s\" is %d", s1, s2, dist);
    return 0;
}