//MISTRAL-7B DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

int min(int a, int b, int c) {
    return (a <= b) ? ((a <= c) ? a : c) : ((b <= c) ? b : c);
}

int levenshtein_distance(char *str1, char *str2, int m, int n) {
    int cost;
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;

            else if (j == 0)
                dp[i][j] = i;

            else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }

            else {
                cost = 1;

                dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int m, n;

    printf("Enter first string: ");
    scanf("%s", str1);
    m = strlen(str1);

    printf("Enter second string: ");
    scanf("%s", str2);
    n = strlen(str2);

    printf("Levenshtein Distance: %d\n", levenshtein_distance(str1, str2, m, n));

    return 0;
}