//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int n, m, i, j, k, len, max_len, start;
    char str[MAX_SIZE], pattern[MAX_SIZE];
    int dp[MAX_SIZE][MAX_SIZE];

    // Read input string
    printf("Enter the input string: ");
    scanf("%s", str);
    n = strlen(str);

    // Read pattern string
    printf("Enter the pattern string: ");
    scanf("%s", pattern);
    m = strlen(pattern);

    // Initialize dynamic programming table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    // Compute length of longest common suffix
    for (i = n - 1, j = m - 1; i >= 0 && j >= 0; i--, j--) {
        if (str[i] == pattern[j]) {
            dp[i][j] = 1;
            len = j;
        } else {
            break;
        }
    }

    // Compute length of longest common suffix
    max_len = dp[n - 1][m - 1];
    start = n - max_len;

    // Print longest common suffix
    printf("Longest common suffix: ");
    for (i = start; i < n; i++) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}