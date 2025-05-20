//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 10

int n, m, i, j, k, max, pos, val;
int coin[MAX_COINS];
int dp[MAX_COINS + 1];

void init() {
    memset(dp, 0, sizeof(dp));
}

int main() {
    init();
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        scanf("%d", &coin[i]);
    }
    for (i = 0; i <= m; i++) {
        dp[i] = -1;
    }
    for (i = 0; i < n; i++) {
        for (j = m; j >= coin[i]; j--) {
            if (dp[j - coin[i]]!= -1) {
                dp[j] = dp[j - coin[i]] + 1;
            }
        }
    }
    max = 0;
    for (i = 0; i <= m; i++) {
        if (dp[i] > max) {
            max = dp[i];
            pos = i;
        }
    }
    printf("%d\n", max);
    for (i = m; i >= 0; i--) {
        if (dp[i] == max) {
            break;
        }
    }
    printf("%d\n", coin[i]);
    for (i = i - 1; i >= 0; i--) {
        if (dp[pos - coin[i]] == max - 1) {
            printf("%d ", coin[i]);
            pos -= coin[i];
        }
    }
    return 0;
}