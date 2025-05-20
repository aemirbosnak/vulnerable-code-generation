//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a coin
typedef struct {
    int denomination;
    int quantity;
} Coin;

// Function to compare coins based on denomination
int compare(const void *a, const void *b) {
    return ((Coin *)b)->denomination - ((Coin *)a)->denomination;  // Sort in descending order
}

// Function to perform the coin change using Greedy algorithm
void coinChange(int amount, Coin coins[], int numCoins) {
    int totalCoinsUsed = 0;
    printf("Coins needed for amount %d:\n", amount);

    for (int i = 0; i < numCoins; i++) {
        if (amount <= 0) {
            break;  // Exit if no amount left
        }
        int coinsNeeded = amount / coins[i].denomination;  // Maximum coins of current denomination
        int coinsToUse = (coinsNeeded < coins[i].quantity) ? coinsNeeded : coins[i].quantity;

        if (coinsToUse > 0) {
            totalCoinsUsed += coinsToUse;
            amount -= coinsToUse * coins[i].denomination;  // Deduct the value from amount
            printf("Use %d coin(s) of denomination %d\n", coinsToUse, coins[i].denomination);
        }
    }

    if (amount > 0) {
        printf("Unable to make the exact change for the amount left: %d\n", amount);
    } else {
        printf("Total coins used: %d\n", totalCoinsUsed);
    }
}

int main() {
    printf("Welcome to the Greedy Coin Change Problem Solver!\n");

    // Define available denominations and their quantities
    Coin coins[] = {
        {100, 5},  // 5 coins of 100
        {50, 2},   // 2 coins of 50
        {25, 10},  // 10 coins of 25
        {10, 0},   // 0 coins of 10
        {5, 20},   // 20 coins of 5
        {1, 30}    // 30 coins of 1
    };
    
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    // Sort coins based on denomination in descending order
    qsort(coins, numCoins, sizeof(Coin), compare);

    // Ask user for amount to be changed
    int amount;
    printf("Enter the amount you wish to change: ");
    scanf("%d", &amount);

    // Call the coin change function
    coinChange(amount, coins, numCoins);

    return 0;
}