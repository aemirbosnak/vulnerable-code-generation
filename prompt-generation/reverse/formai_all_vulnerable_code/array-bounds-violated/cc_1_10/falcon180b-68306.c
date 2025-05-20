//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 100
#define MAX_VALUES 100
#define MAX_SIZE 100

typedef struct {
    int value;
    int size;
} Item;

Item items[MAX_SIZE];
int n, m, i, j, k;
int dp[MAX_COINS + 1][MAX_SIZE + 1];

void init() {
    memset(dp, 0, sizeof(dp));
}

int max(int a, int b) {
    return a > b? a : b;
}

void knapSack(int w, int n) {
    for (i = 0; i <= w; i++) {
        for (j = 0; j <= n; j++) {
            if (j == 0 || i == 0)
                dp[i][j] = 0;
            else if (items[j - 1].size <= i)
                dp[i][j] = max(dp[i][j - 1], dp[i - items[j - 1].size][j - 1] + items[j - 1].value);
            else
                dp[i][j] = dp[i][j - 1];
        }
    }
    printf("Maximum value that can be obtained: %d\n", dp[w][n]);
}

int main() {
    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter item values and sizes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].size);
    }

    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &m);

    knapSack(m, n);

    return 0;
}