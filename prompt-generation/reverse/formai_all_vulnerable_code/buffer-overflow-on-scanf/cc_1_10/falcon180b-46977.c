//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_COIN_TYPES 100
#define MAX_COINS 10000

struct coin {
    int value;
    int count;
};

int main() {
    int n, m, i, j;
    struct coin coins[MAX_COIN_TYPES];
    int dp[MAX_COIN_TYPES][MAX_COINS + 1];

    // read input
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i].value);
        coins[i].count = 0;
    }

    // initialize dynamic programming table
    for (i = 0; i <= m; i++) {
        for (j = 0; j < n; j++) {
            dp[j][i] = 0;
        }
    }

    // fill dynamic programming table
    for (i = 0; i < n; i++) {
        dp[i][coins[i].value] = 1;
    }

    for (i = 1; i <= m; i++) {
        for (j = 0; j < n; j++) {
            if (dp[j][i]) {
                for (int k = 0; k < n; k++) {
                    if (k!= j) {
                        dp[k][i] = (dp[k][i] + dp[j][i - coins[j].value]) % 1000000007;
                    }
                }
            }
        }
    }

    // print result
    printf("%d\n", dp[0][m]);

    return 0;
}