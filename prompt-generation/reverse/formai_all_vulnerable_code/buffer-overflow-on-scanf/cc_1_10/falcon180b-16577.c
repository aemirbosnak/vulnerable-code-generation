//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 5
#define MAX_VALUE 1000

// Function to find the minimum number of coins required to make a given value
int findMinCoins(int value, int coins[], int n) {
    int i, j, minCoins;

    // Initialize minimum number of coins to a large value
    minCoins = MAX_VALUE;

    // Try all possible combinations of coins
    for (i = 0; i <= value; i++) {
        for (j = 0; j < n; j++) {
            if (coins[j] <= i) {
                // If a coin is smaller than or equal to the current value,
                // update the minimum number of coins required
                if (i == value) {
                    minCoins = 1;
                } else if ((i + coins[j]) - value < minCoins) {
                    minCoins = (i + coins[j]) - value;
                }
            }
        }
    }

    // Return the minimum number of coins required
    return minCoins;
}

int main() {
    int value, coins[MAX_COINS], n, i;

    // Get the value to be made
    printf("Enter the value to be made: ");
    scanf("%d", &value);

    // Get the number of coins available
    printf("Enter the number of coins available: ");
    scanf("%d", &n);

    // Get the values of the coins
    printf("Enter the values of the coins:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Find the minimum number of coins required to make the given value
    int minCoins = findMinCoins(value, coins, n);

    // Print the minimum number of coins required
    printf("Minimum number of coins required: %d\n", minCoins);

    return 0;
}