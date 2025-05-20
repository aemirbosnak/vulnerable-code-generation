//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 100

// Function to compare two values for qsort
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a); // Sort in descending order
}

// Function to find the minimum number of coins
void findMinCoins(int coins[], int numCoins, int amount) {
    int totalCoins = 0;
    int i;

    // Array to store the number of each coin used
    int count[MAX_COINS] = {0};

    // Iterate through the coin denominations
    for (i = 0; i < numCoins; i++) {
        while (amount >= coins[i]) { // While we can use this coin
            amount -= coins[i];      // Reduce amount by coin value
            totalCoins++;            // Increment total coins used
            count[i]++;              // Increment count of this coin
        }
    }

    // Output the results
    printf("Minimum number of coins needed: %d\n", totalCoins);
    printf("Coins used:\n");
    for (i = 0; i < numCoins; i++) {
        if (count[i] > 0) {
            printf("Coin %d: %d times\n", coins[i], count[i]);
        }
    }
}

int main() {
    int coins[MAX_COINS];
    int numCoins, amount, i;

    // Input number of coin denominations
    printf("Enter the number of different coin denominations: ");
    if (scanf("%d", &numCoins) != 1 || numCoins <= 0 || numCoins > MAX_COINS) {
        fprintf(stderr, "Invalid number of coin denominations.\n");
        return EXIT_FAILURE;
    }

    // Input coin denominations
    printf("Enter the coin denominations:\n");
    for (i = 0; i < numCoins; i++) {
        if (scanf("%d", &coins[i]) != 1 || coins[i] <= 0) {
            fprintf(stderr, "Invalid coin denomination.\n");
            return EXIT_FAILURE;
        }
    }

    // Input the amount for which change is required
    printf("Enter the amount to change: ");
    if (scanf("%d", &amount) != 1 || amount < 0) {
        fprintf(stderr, "Invalid amount.\n");
        return EXIT_FAILURE;
    }

    // Sort the coin denominations in descending order for the greedy approach
    qsort(coins, numCoins, sizeof(int), compare);

    // Call the function to find the minimum coins
    findMinCoins(coins, numCoins, amount);

    return EXIT_SUCCESS;
}