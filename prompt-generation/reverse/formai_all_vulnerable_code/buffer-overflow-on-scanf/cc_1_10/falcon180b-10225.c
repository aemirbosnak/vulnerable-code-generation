//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NUM_COINS 1000

int num_coins = 0;
int coins[] = {1, 5, 10, 25};
int dp[MAX_NUM_COINS+1];

// Initialize the dp table
void init() {
    for (int i = 0; i <= MAX_NUM_COINS; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
}

// Print the dp table
void print_dp() {
    for (int i = 0; i <= MAX_NUM_COINS; i++) {
        printf("%d ", dp[i]);
    }
    printf("\n");
}

// Greedy algorithm to find the minimum number of coins required to make a given sum
int greedy_algorithm(int sum) {
    int i, j;
    for (i = num_coins - 1; i >= 0; i--) {
        if (coins[i] <= sum) {
            dp[sum] = 1 + dp[sum - coins[i]];
            if (dp[sum] == 1) {
                num_coins--;
            }
            break;
        }
    }
    return dp[sum];
}

int main() {
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    num_coins = n;
    for (int i = 0; i < num_coins; i++) {
        printf("Enter coin %d: ", i+1);
        scanf("%d", &coins[i]);
    }
    printf("Enter the sum: ");
    scanf("%d", &n);
    init();
    int min_coins = greedy_algorithm(n);
    printf("Minimum number of coins required: %d\n", min_coins);
    print_dp();
    return 0;
}