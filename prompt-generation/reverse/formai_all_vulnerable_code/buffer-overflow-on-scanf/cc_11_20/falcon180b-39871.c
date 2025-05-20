//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 5
#define MAX_VALUES 10

int main() {
    int coins[MAX_COINS], values[MAX_VALUES], i, j;
    int n, m, k;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the number of values: ");
    scanf("%d", &m);
    printf("Enter the values:\n");
    for (i = 0; i < m; i++) {
        scanf("%d", &values[i]);
    }
    printf("Enter the number of coins:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("Enter the number of values to be selected: ");
    scanf("%d", &k);
    int max_value = 0;
    for (i = 0; i < k; i++) {
        max_value += values[i];
    }
    int dp[m + 1][n + 1];
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (values[i - 1] <= coins[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + values[i - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int selected_values[k];
    int selected_coins[k];
    int num_coins_selected = 0;
    int num_values_selected = 0;
    for (i = m - 1; i >= 0 && num_values_selected < k; i--) {
        if (dp[k][n] - dp[k][n - values[i]] == values[i]) {
            selected_values[num_values_selected++] = values[i];
            selected_coins[num_coins_selected++] = coins[n - 1];
            n -= values[i];
        }
    }
    if (num_values_selected < k) {
        printf("Not enough values to select.\n");
    } else {
        printf("Selected values:\n");
        for (i = 0; i < k; i++) {
            printf("%d ", selected_values[i]);
        }
        printf("\nSelected coins:\n");
        for (i = 0; i < k; i++) {
            printf("%d ", selected_coins[i]);
        }
    }
    return 0;
}