//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int levenshtein_distance(char *s, char *t) {
    int n = strlen(s);
    int m = strlen(t);
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= m; ++j) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
    }

    return dp[n][m];
}

int main() {
    char s[100], t[100];
    printf("Enter String 1: ");
    scanf("%s", s);
    printf("Enter String 2: ");
    scanf("%s", t);

    int distance = levenshtein_distance(s, t);
    printf("Levenshtein Distance: %d\n", distance);

    return 0;
}