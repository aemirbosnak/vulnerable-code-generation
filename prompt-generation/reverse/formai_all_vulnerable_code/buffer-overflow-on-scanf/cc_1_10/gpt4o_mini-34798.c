//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a coin denomination
typedef struct {
    int value; // Value of the coin
    int quantity; // Number of coins available
} Coin;

// Function to perform the greedy algorithm for making change
void makeChange(int amount, Coin coins[], int numCoins) {
    // Array to store the number of each coin denomination used
    int coinCount[numCoins];
    for (int i = 0; i < numCoins; i++) {
        coinCount[i] = 0; // Initialize the count array
    }

    // Process the amount with a greedy strategy
    for (int i = 0; i < numCoins; i++) {
        while (amount >= coins[i].value && coins[i].quantity > 0) {
            amount -= coins[i].value; // Deduct coin value from the amount
            coins[i].quantity--; // Decrease the availability of the coin
            coinCount[i]++; // Increase the count of coins used
        }
    }

    // If any amount remains, we couldn't make the change
    if (amount > 0) {
        printf("Cannot make change for the given amount using the provided coins.\n");
    } else {
        printf("Change made successfully! Here is the breakdown of coins:\n");
        for (int i = 0; i < numCoins; i++) {
            if (coinCount[i] > 0) {
                printf("Coin of %d: %d\n", coins[i].value, coinCount[i]);
            }
        }
    }
}

// Function to display the available coins
void displayCoins(Coin coins[], int numCoins) {
    printf("Available coins:\n");
    for (int i = 0; i < numCoins; i++) {
        printf("Coin value: %d, Quantity: %d\n", coins[i].value, coins[i].quantity);
    }
}

// Main function
int main() {
    // Define the coin denominations and their quantities
    Coin coins[] = {
        {25, 5}, // 5 quarters
        {10, 5}, // 5 dimes
        {5, 5},  // 5 nickels
        {1, 5}   // 5 pennies
    };
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    
    // Display the available coins
    displayCoins(coins, numCoins);

    // Enter the amount for which change is required
    int amount;
    printf("Enter the amount for which you want to make change: ");
    scanf("%d", &amount);
    
    // Make change for the given amount
    makeChange(amount, coins, numCoins);

    return 0;
}