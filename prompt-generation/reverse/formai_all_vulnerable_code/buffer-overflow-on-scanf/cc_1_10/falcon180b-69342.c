//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_N 100000

int main() {
    int n, i, j, k, pos, max_pos;
    int *coins = (int*)malloc(sizeof(int) * MAX_N);
    int *dp = (int*)malloc(sizeof(int) * MAX_N);
    int *prev = (int*)malloc(sizeof(int) * MAX_N);

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the value of coin %d: ", i);
        scanf("%d", &coins[i]);
    }

    srand(time(NULL));
    for (i = 0; i < n; i++) {
        dp[i] = rand() % coins[i];
    }

    max_pos = 0;

    for (i = 1; i < n; i++) {
        pos = 0;
        for (j = 0; j < i; j++) {
            if (dp[j] + coins[i] > dp[pos]) {
                pos = j;
            }
        }
        dp[i] = dp[pos] + coins[i];
        if (dp[i] > dp[max_pos]) {
            max_pos = i;
        }
    }

    printf("The maximum value that can be obtained is %d\n", dp[max_pos]);

    for (i = n - 1; i >= 0; i--) {
        if (dp[max_pos] - dp[i] == coins[i]) {
            prev[max_pos] = i;
            max_pos = i;
        }
    }

    printf("The coins used are: ");
    for (i = max_pos; i >= 0; i = prev[i]) {
        printf("%d ", i);
    }

    return 0;
}