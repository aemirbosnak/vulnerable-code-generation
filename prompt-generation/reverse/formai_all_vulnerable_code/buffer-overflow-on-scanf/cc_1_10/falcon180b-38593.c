//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NUM_COINS 1000
#define MAX_NUM_ITEMS 1000
#define INF 1000000000

int n, m;
int val[MAX_NUM_ITEMS];
int wt[MAX_NUM_ITEMS];
int dp[MAX_NUM_ITEMS][MAX_NUM_COINS];
int min_wt[MAX_NUM_ITEMS];
int min_val[MAX_NUM_ITEMS];

void knapSack(int idx, int w, int c) {
    if (idx == 0) {
        return;
    }
    if (wt[idx - 1] > w) {
        knapSack(idx - 1, w, c);
    } else {
        if (dp[idx - 1][c - wt[idx - 1]] + val[idx - 1] > dp[idx - 1][c]) {
            dp[idx - 1][c] = dp[idx - 1][c - wt[idx - 1]] + val[idx - 1];
            min_wt[idx - 1] = c;
            min_val[idx - 1] = val[idx - 1];
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }
    for (int i = 0; i < n; i++) {
        knapSack(i, m, m);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i][m]!= INF) {
            ans += min_val[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}