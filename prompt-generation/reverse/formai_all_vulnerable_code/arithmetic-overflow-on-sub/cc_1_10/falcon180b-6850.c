//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_ITEMS 5
#define MAX_VALUE 100

int main() {
    int n, m, max_value, i, j;
    int value[MAX_ITEMS], weight[MAX_ITEMS];
    int dp[MAX_ITEMS][MAX_VALUE + 1];
    int knap[MAX_ITEMS];
    int w;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the value of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the maximum weight limit: ");
    scanf("%d", &max_value);

    for (i = 0; i < n; i++) {
        for (j = 0; j <= max_value; j++) {
            dp[i][j] = 0;
        }
    }

    printf("Enter the number of coins:\n");
    scanf("%d", &m);

    printf("Enter the value of each coin:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &knap[i]);
    }

    w = 0;
    for (i = 0; i < n; i++) {
        for (j = max_value; j >= weight[i]; j--) {
            if (dp[i][j] < dp[i][j - weight[i]] + value[i]) {
                dp[i][j] = dp[i][j - weight[i]] + value[i];
            }
        }
    }

    printf("The maximum value that can be obtained is: %d\n", dp[n - 1][max_value]);

    return 0;
}