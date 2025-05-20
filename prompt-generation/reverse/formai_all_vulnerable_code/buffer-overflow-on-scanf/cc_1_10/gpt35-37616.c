//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b, int c) {
    return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int levenshtein(char *s1, char *s2) {
    int len1 = strlen(s1), len2 = strlen(s2);
    int **dp = (int **) malloc((len1 + 1) * sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        dp[i] = (int *) malloc((len2 + 1) * sizeof(int));
    }

    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    int result = dp[len1][len2];
    for (int i = 0; i <= len1; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}

int main() {
    char s1[255], s2[255];
    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);
    int distance = levenshtein(s1, s2);
    printf("The Levenshtein distance between \"%s\" and \"%s\" is %d.\n", s1, s2, distance);
    return 0;
}