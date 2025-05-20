//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// Function to find the minimum coin change required
int minCoinChange(int coins[], int numCoins, int maxDenom, int amount) {
    int i, j;
    int min_coins = 0;

    // Initialize the table
    int table[amount + 1];
    for (i = 0; i <= amount; i++) {
        table[i] = 9999;
    }

    // Initialize the minimum coins required to make a change of 0
    table[0] = 0;

    // Fill in the table
    for (i = 1; i <= amount; i++) {
        for (j = 0; j < numCoins; j++) {
            if (i >= coins[j]) {
                if (table[i - coins[j]] + 1 < table[i]) {
                    table[i] = table[i - coins[j]] + 1;
                }
            }
        }
    }

    return table[amount];
}

int main() {
    int coins[] = { 1, 2, 5, 10, 20 };
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int maxDenom = coins[numCoins - 1];
    int amount;

    printf("Enter the amount of money: ");
    scanf("%d", &amount);

    // Call the function to find the minimum coin change required
    int minCoins = minCoinChange(coins, numCoins, maxDenom, amount);

    printf("Minimum coins required to make a change of %d: %d\n", amount, minCoins);

    return 0;
}