//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 1000
#define MAX_VALUES 1000

int main() {
    int n, m, i, j;
    int dp[MAX_COINS + 1][MAX_VALUES + 1];
    int coins[MAX_COINS];
    int values[MAX_VALUES];

    printf("Enter the number of coins available: ");
    scanf("%d", &n);

    printf("Enter the number of values to be made: ");
    scanf("%d", &m);

    // Initialize coins and values arrays
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    for (i = 0; i < m; i++) {
        scanf("%d", &values[i]);
    }

    // Initialize dynamic programming table
    for (i = 0; i <= m; i++) {
        dp[0][i] = 1;
    }

    for (i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (coins[i-1] <= j) {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Print the number of ways to make each value
    for (i = 0; i < m; i++) {
        printf("The number of ways to make %d is %d\n", values[i], dp[n][i]);
    }

    return 0;
}