//Code Llama-13B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: safe
/*
 * Levenshtein Distance Calculator
 * A safe C program to calculate the Levenshtein distance between two strings.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100

int min(int a, int b) {
    return (a < b) ? a : b;
}

int levenshtein_distance(char *s1, char *s2) {
    int i, j, m = strlen(s1), n = strlen(s2);
    int dp[MAX_LEN][MAX_LEN];

    for (i = 0; i <= m; i++)
        dp[i][0] = i;

    for (j = 0; j <= n; j++)
        dp[0][j] = j;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
        }
    }

    return dp[m][n];
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];
    int distance;

    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

    distance = levenshtein_distance(s1, s2);

    printf("Levenshtein distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}