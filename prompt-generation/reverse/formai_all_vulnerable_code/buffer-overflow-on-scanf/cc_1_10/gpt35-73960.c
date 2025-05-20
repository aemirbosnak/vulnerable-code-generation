//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int x, int y, int z) {
    return ((x < y) ? ((x < z) ? x : z) : ((y < z) ? y : z));
}

int levenshteinDistance(char *s1, char *s2) {

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int cost;

    int **dp = (int **) malloc(sizeof(int *) * (len1 + 1));

    for (int i = 0; i <= len1; i++)
        dp[i] = (int *) malloc(sizeof(int) * (len2 + 1));

    for (int i = 0; i <= len1; i++)
        dp[i][0] = i;

    for (int j = 0; j <= len2; j++)
        dp[0][j] = j;

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost);
        }
    }

    int distance = dp[len1][len2];

    for (int i = 0; i <= len1; i++)
        free(dp[i]);
    free(dp);

    return distance;
}

int main() {
    printf("Welcome to the futuristic Levenshtein Distance Calculator!\n\n");
    printf("Enter two strings:\n");

    char str1[100], str2[100];
    scanf("%s %s", str1, str2);

    int distance = levenshteinDistance(str1, str2);

    printf("\nThe Levenshtein distance between %s and %s is: %d\n\n", str1, str2, distance);

    return 0;
}