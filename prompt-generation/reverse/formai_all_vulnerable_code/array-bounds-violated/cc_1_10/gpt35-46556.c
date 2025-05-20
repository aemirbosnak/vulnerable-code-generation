//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int min(int x, int y, int z) {
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int LevenshteinDistance(char *s1, char *s2, int len1, int len2) {
    int i, j, cost;
    int dp[len1 + 1][len2 + 1];

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                cost = 1;
                dp[i][j] = min(dp[i - 1][j - 1] + cost,
                               dp[i - 1][j] + cost,
                               dp[i][j - 1] + cost);
            }
        }
    }

    return dp[len1][len2];
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1, len2, result;

    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    len1 = strlen(str1) - 1;
    str1[len1] = '\0';

    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);
    len2 = strlen(str2) - 1;
    str2[len2] = '\0';

    result = LevenshteinDistance(str1, str2, len1, len2);

    printf("The Levenshtein Distance between '%s' and '%s' is %d.\n",
           str1, str2, result);

    return 0;
}