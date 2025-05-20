//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m, i, j, k, max_profit = 0;
    int **dp, **prev;
    int *candidates, size;

    // Read input
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the number of knapsacks: %d\n", m);
    for (i = 0; i < m; i++) {
        printf("Enter the capacity of knapsack %d: ", i);
        scanf("%d", &candidates[i]);
    }

    printf("Enter the number of items: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &candidates[i]);
    }

    printf("Enter the number of knapsacks: %d\n", m);
    for (i = 0; i < m; i++) {
        printf("Enter the capacity of knapsack %d: ", i);
        scanf("%d", &candidates[n+i]);
    }

    // Initialize dynamic programming arrays
    dp = (int **)malloc(m * sizeof(int *));
    prev = (int **)malloc(m * sizeof(int *));
    for (i = 0; i < m; i++) {
        dp[i] = (int *)malloc((n+m) * sizeof(int));
        prev[i] = (int *)malloc((n+m) * sizeof(int));
    }

    // Initialize dynamic programming arrays
    for (i = 0; i < m; i++) {
        for (j = 0; j < n+m; j++) {
            dp[i][j] = INT_MIN;
        }
    }

    // Fill in base cases
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (candidates[j] <= candidates[n+i]) {
                dp[i][j] = candidates[j];
            }
        }
    }

    // Iterate through items and knapsacks
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (dp[j][i-1]!= INT_MIN) {
                max_profit = dp[j][i-1] + candidates[n+j];
                for (k = 0; k < i; k++) {
                    if (dp[j][k]!= INT_MIN && dp[j][k] + candidates[n+j] > max_profit) {
                        max_profit = dp[j][k] + candidates[n+j];
                        prev[j][i] = k;
                    }
                }
                dp[j][i] = max_profit;
            }
        }
    }

    // Print solution
    printf("The maximum profit is: %d\n", dp[0][n]);

    // Free memory
    for (i = 0; i < m; i++) {
        free(dp[i]);
        free(prev[i]);
    }
    free(dp);
    free(prev);
    free(candidates);

    return 0;
}