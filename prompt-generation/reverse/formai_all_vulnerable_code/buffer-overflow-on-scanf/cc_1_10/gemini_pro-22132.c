//GEMINI-pro DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *str1, *str2;
    int len1, len2, i, j, cost, minCost;
    int **dp;

    printf("Enter first string: ");
    str1 = malloc(sizeof(char) * 100);
    scanf("%s", str1);

    printf("Enter second string: ");
    str2 = malloc(sizeof(char) * 100);
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    dp = (int **)malloc(sizeof(int *) * (len1 + 1));
    for (i = 0; i <= len1; i++) {
        dp[i] = (int *)malloc(sizeof(int) * (len2 + 1));
    }

    for (i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }

    for (j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }

    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }

    minCost = dp[len1][len2];

    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d\n", str1, str2, minCost);

    for (i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);
    free(str1);
    free(str2);

    return 0;
}

int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}