//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int levenshtein_distance(char *s, char *t) {
    int m = strlen(s), n = strlen(t);
    int **dp = malloc(sizeof(int*) * (m + 1));
    for (int i = 0; i <= m; i++) {
        dp[i] = malloc(sizeof(int) * (n + 1));
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + fmin(fmin(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
            }
        }
    }
    int result = dp[m][n];
    for (int i = 0; i <= m; i++) {
        free(dp[i]);
    }
    free(dp);
    return result;
}

int main() {
    char s[100];
    char t[100];
    printf("Welcome to the Levenshtein Distance Calculator! Please enter two strings below:\n");
    printf("String 1: ");
    scanf("%s", s);
    printf("String 2: ");
    scanf("%s", t);
    printf("\nCalculating...\n");
    int distance = levenshtein_distance(s, t);
    printf("The Levenshtein Distance between '%s' and '%s' is: %d\n", s, t, distance);
    if (distance <= 5) {
        printf("Wow, '%s' and '%s' are practically twins!\n", s, t);
    } else if (distance <= 15) {
        printf("Hmm, it seems like '%s' and '%s' might be related somehow...\n", s, t);
    } else {
        printf("Are '%s' and '%s' even from the same planet?! That distance is out of this world!\n", s, t);
    }
    return 0;
}