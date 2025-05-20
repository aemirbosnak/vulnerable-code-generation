//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: retro
#include <stdio.h>

void printCoins(int coins[], int coinCount, int amount) {
    int coinUsed[coinCount];  // Array to track how many of each coin we use
    int totalCoins = 0;       // Total number of coins used
    int i;

    // Initialize coin usage to zero
    for (i = 0; i < coinCount; i++) {
        coinUsed[i] = 0;
    }

    // Start from the largest coin and go downwards
    for (i = coinCount - 1; i >= 0; i--) {
        while (amount >= coins[i]) {
            amount -= coins[i];      // Reduce amount
            coinUsed[i]++;          // Increment count of this coin
            totalCoins++;           // Increment total coins used
        }
    }

    // Print the result
    printf("Total coins used: %d\n", totalCoins);
    printf("Coins used:\n");
    for (i = 0; i < coinCount; i++) {
        if (coinUsed[i] > 0) {
            printf("Coin of %d: %d times\n", coins[i], coinUsed[i]);
        }
    }
}

int main() {
    int coins[] = {1, 5, 10, 25}; // Available coins (cents)
    int coinCount = sizeof(coins) / sizeof(coins[0]);
    int amount;

    printf("Welcome to the Retro Coin Change Calculator!\n");
    printf("Enter the amount of money (in cents): ");
    scanf("%d", &amount);

    if (amount < 0) {
        printf("You entered a negative amount! Please enter a positive value.\n");
        return 1; // Exit with an error code
    }

    printf("\nCalculating the minimal number of coins for %d cents...\n", amount);
    printCoins(coins, coinCount, amount);

    printf("\nThank you for using the Retro Coin Change Calculator!\n");
    return 0; // Program executed successfully
}