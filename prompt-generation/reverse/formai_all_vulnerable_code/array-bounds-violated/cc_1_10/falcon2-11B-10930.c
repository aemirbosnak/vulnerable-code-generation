//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to find the minimum number of coins required to make change
int findMinCoins(int amount, int coins[], int num_coins) {
    int i, j, min_coins = 0;
    int dp[amount + 1];

    // Initialize the dynamic programming array
    for (i = 0; i <= amount; i++) {
        dp[i] = amount + 1;
    }

    // Iterate through each coin
    for (i = num_coins - 1; i >= 0; i--) {
        int min_value = amount;

        // Iterate through each amount from 0 to amount
        for (j = 0; j <= amount; j++) {
            if (j < coins[i]) {
                min_value = min_value > dp[j + coins[i]]? dp[j + coins[i]] : min_value;
            } else {
                min_value = min_value > dp[j]? dp[j] : min_value;
            }
        }

        // Update the minimum number of coins required
        if (min_value == amount) {
            min_coins++;
        }
        dp[amount] = min_value;
    }

    return min_coins;
}

int main() {
    int amount = 5;
    int coins[] = {1, 3, 5};
    int num_coins = sizeof(coins) / sizeof(coins[0]);

    // Find the minimum number of coins required to make change
    int min_coins = findMinCoins(amount, coins, num_coins);

    // Print the result
    printf("Minimum number of coins required: %d\n", min_coins);

    return 0;
}