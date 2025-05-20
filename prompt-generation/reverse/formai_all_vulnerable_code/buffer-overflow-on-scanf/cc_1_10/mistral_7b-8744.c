//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 10000 // Maximum amount
#define NUM_COINS 5      // Number of coins

// Struct to represent coin denominations and their quantities
typedef struct {
    int value;
    int count;
} Coin;

// Function to print the minimum number of coins required
// to make a given amount using given denominations
void printMinCoins(int amount, Coin coins[]) {
    int i, numCoins = 0;
    int coinsArray[NUM_COINS] = {0};

    for (i = 0; amount > 0; i = 0) {
        // Find the coin that can be used maximum times
        for (int j = 0; j < NUM_COINS; j++) {
            if (coins[j].count > 0 && amount >= coins[j].value) {
                coinsArray[numCoins++] = j;
                coins[j].count--;
                amount -= coins[j].value;
                i = 1; // Break inner loop
            }
        }
    }

    printf("Minimum number of coins required: %d\n", numCoins);
    printf("Coins used:\n");

    // Print the coins used in the order they were used
    for (int i = numCoins - 1; i >= 0; i--) {
        printf("%d coin(s) of denomination %d\n", coinsArray[i] + 1, coins[coinsArray[i]].value);
    }
}

// Function to initialize coin denominations and their quantities
void initializeCoins(Coin coins[]) {
    for (int i = 0; i < NUM_COINS; i++) {
        coins[i].value = i + 1;
        coins[i].count = 10;
    }
}

int main() {
    Coin coins[NUM_COINS];
    int amount;

    initializeCoins(coins); // Initialize coin denominations and their quantities

    printf("Enter the amount:\n");
    scanf("%d", &amount);

    if (amount > MAX_AMOUNT) {
        printf("Amount should be less than or equal to %d\n", MAX_AMOUNT);
        return 1;
    }

    printMinCoins(amount, coins); // Print the minimum number of coins required

    return 0;
}