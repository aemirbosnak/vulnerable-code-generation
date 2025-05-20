//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: realistic
#include <stdio.h>

void printCoins(int coins[], int coinCount, int amount) {
    printf("To make change for %d, use the following coins:\n", amount);
    for (int i = 0; i < coinCount; i++) {
        if (coins[i] > 0) {
            printf("%d x %d cents\n", coins[i], i + 1); // Coin denomination is index + 1
        }
    }
}

int minimumCoins(int denominations[], int denomCount, int amount) {
    int coins[denomCount]; // Array to hold the count of each coin used
    for (int i = 0; i < denomCount; i++) {
        coins[i] = 0; // Initialize coins count to 0
    }

    for (int i = denomCount - 1; i >= 0; i--) {
        while (amount >= (i + 1)) { // Coin denomination is index + 1
            amount -= (i + 1); // Deduct the coin value from the amount
            coins[i]++; // Increment the count of this coin
        }
    }

    if (amount > 0) {
        printf("It is not possible to make change for the given amount with the provided denominations.\n");
        return -1; // Indicate failure
    }

    printCoins(coins, denomCount, amount); // Output the coins used
    return 0; // Indicate success
}

int main() {
    int denominations[] = {1, 2, 5, 10, 25}; // Coin denominations: 1, 2, 5, 10, 25 cents
    int denomCount = sizeof(denominations) / sizeof(denominations[0]); // Number of denominations

    int amount;

    printf("Enter the amount of change needed (in cents): ");
    scanf("%d", &amount);

    if (amount < 0) {
        printf("Please enter a non-negative amount.\n");
        return 1; // Exit with error code
    }

    int result = minimumCoins(denominations, denomCount, amount);
  
    if (result == 0) {
        printf("Change successfully computed.\n");
    }

    return 0; // Program executed successfully
}