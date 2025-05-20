//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int min(int x, int y, int z)
{
    if (x < y && x < z) {
        return x;
    } else if (y < z) {
        return y;
    } else {
        return z;
    }
}

int levenshtein_distance(char *s1, char *s2, int len1, int len2)
{
    int i, j, cost;
    int dp[len1 + 1][len2 + 1];

    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                cost = 1;
                dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + cost);
            }
        }
    }

    return dp[len1][len2];
}

int main()
{
    char s1[MAX_LENGTH], s2[MAX_LENGTH];
    int len1, len2, distance;

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    len1 = strlen(s1);
    len2 = strlen(s2);

    distance = levenshtein_distance(s1, s2, len1, len2);

    printf("Levenshtein Distance between %s and %s is %d\n", s1, s2, distance);

    return 0;
}