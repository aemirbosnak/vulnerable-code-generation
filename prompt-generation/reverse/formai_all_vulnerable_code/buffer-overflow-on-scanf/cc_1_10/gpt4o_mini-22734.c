//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include <stdio.h>

// Function to find the minimum number of coins
void findMinimumCoins(int coins[], int n, int amount) {
    int coinCount = 0; // Variable to count the number of coins used
    int i;

    // Array to hold the number of each coin used
    int coinsUsed[n];

    // Iterate through the coin denominations from highest to lowest
    for (i = 0; i < n; i++) {
        // Keep using the coin until we can't use it anymore
        while (amount >= coins[i]) {
            amount -= coins[i]; // Reduce amount by coin value
            coinsUsed[coinCount] = coins[i]; // Store the used coin
            coinCount++; // Increase coin count
        }
    }

    // Display the results
    printf("Minimum number of coins: %d\n", coinCount);
    printf("Coins used:\n");
    for (i = 0; i < coinCount; i++) {
        printf("%d ", coinsUsed[i]);
    }
    printf("\n");
}

int main() {
    // Define the available coin denominations
    int coins[] = {25, 10, 5, 1}; // Example coins: quarters, dimes, nickels, and pennies
    int n = sizeof(coins) / sizeof(coins[0]); // Number of different denominations

    int amount; // Variable to hold the amount for change

    // Ask the user for input
    printf("Enter the amount for which you want to make change: ");
    scanf("%d", &amount);

    // Validate input
    if (amount < 0) {
        printf("Amount cannot be negative!\n");
        return 1; // Exit with error status
    }

    // Call the function to find the minimum coins
    findMinimumCoins(coins, n, amount);

    return 0; // Successful execution
}