//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 1000
#define MAX_VALUES 1000

int main() {
    int n, m, i, j, k;
    int coins[MAX_COINS];
    int values[MAX_VALUES];
    int dp[MAX_COINS][MAX_VALUES];

    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the number of values: ");
    scanf("%d", &m);

    printf("Enter the values:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the coins:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (values[i] <= coins[j]) {
                dp[j][i] = coins[j];
            } else {
                dp[j][i] = 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (dp[i][j]!= 0) {
                printf("%d ", dp[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

    return 0;
}