//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum number of coins needed to change the given amount
int minCoins(int coins[], int n, int amount) {
    // Create a table to store the minimum number of coins needed to change
    // each amount from 1 to amount
    int table[amount + 1];

    // Initialize all table values to INT_MAX, except table[0] which is 0
    for (int i = 1; i <= amount; i++) {
        table[i] = INT_MAX;
    }
    table[0] = 0;

    // Iterate over all coins
    for (int i = 0; i < n; i++) {
        // Iterate over all amounts from the current coin value to the amount
        for (int j = coins[i]; j <= amount; j++) {
            // If it is possible to change the current amount using the current coin,
            // then update the table value for the current amount to the minimum of
            // the current table value and the table value for the current amount
            // minus the current coin value plus 1
            if (table[j - coins[i]] != INT_MAX) {
                table[j] = fmin(table[j], table[j - coins[i]] + 1);
            }
        }
    }

    // Return the minimum number of coins needed to change the given amount
    return table[amount] == INT_MAX ? -1 : table[amount];
}

// Driver code to test the minCoins function
int main() {
    // Define the coin denominations
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);

    // Get the amount to change
    int amount;
    printf("Enter the amount to change: ");
    scanf("%d", &amount);

    // Find the minimum number of coins needed to change the given amount
    int min_coins = minCoins(coins, n, amount);

    // Print the minimum number of coins needed to change the given amount
    if (min_coins == -1) {
        printf("It is not possible to change the given amount using the given coins\n");
    } else {
        printf("The minimum number of coins needed to change the given amount is %d\n", min_coins);
    }

    return 0;
}