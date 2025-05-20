//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_AMOUNT 10000 // Maximum amount of money
#define COIN_COUNT 5 // Number of distinct coin denominations

// Coin denominations array
int coins[COIN_COUNT] = {1, 5, 10, 25, 50};

// Function to find minimum number of coins required to make change for a given amount
int minCoins(int amount) {
    int count[COIN_COUNT] = {0}; // Initialize an array to store the number of coins of each denomination
    int i = COIN_COUNT - 1; // Initialize the index for the largest coin denomination

    // Keep adding the largest denomination coin as many times as possible until we reach the target amount
    while (amount > 0) {
        // If we have enough coins of the current denomination, add it to the change and move to the next denomination
        while (amount >= coins[i]) {
            amount -= coins[i];
            count[i]++;
        }
        // If we don't have enough coins of the current denomination, move to the next denomination
        i--;
        // If we have exhausted all the coin denominations, we cannot make change for the given amount
        if (i < 0) {
            printf("Cannot make change for amount %d\n", amount);
            exit(1);
        }
    }

    // Print the number of coins of each denomination required to make change for the given amount
    printf("Minimum number of coins to make change for amount %d:\n", amount);
    for (int j = 0; j < COIN_COUNT; j++) {
        printf("Denomination %d: %d coins\n", coins[j], count[j]);
    }

    // Return the total number of coins required to make change for the given amount
    return count[0];
}

// Main function
int main() {
    int amount; // Amount of money to make change for

    // Input the amount of money from the user
    printf("Enter the amount of money: ");
    scanf("%d", &amount);

    // Call the minCoins function to find the minimum number of coins required to make change for the given amount
    int numCoins = minCoins(amount);

    return 0;
}