//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a coin
typedef struct {
    int value;
    int quantity;
} Coin;

// Function to find the minimum number of coins needed for a given amount
void findMinCoins(int amount, Coin coins[], int n) {
    // Array to store the minimum number of coins required for each amount
    int *minCoins = (int *)malloc((amount + 1) * sizeof(int));
    int *coinUsed = (int *)malloc((amount + 1) * sizeof(int));

    // Initialize the arrays
    for (int i = 0; i <= amount; i++) {
        minCoins[i] = amount + 1; // Set to a high number
        coinUsed[i] = -1; // -1 indicates no coin used
    }
    minCoins[0] = 0; // Zero coins needed for amount 0

    // Greedily find the minimum coins for all amounts up to the target amount
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j].quantity > 0 && coins[j].value <= i) {
                if (minCoins[i - coins[j].value] + 1 < minCoins[i]) {
                    minCoins[i] = minCoins[i - coins[j].value] + 1;
                    coinUsed[i] = j; // Store the coin index used
                }
            }
        }
    }

    // Print the coin count for the given amount
    if (minCoins[amount] == amount + 1) {
        printf("It is not possible to make the amount %d with the given coins.\n", amount);
    } else {
        printf("Minimum coins needed for amount %d: %d\n", amount, minCoins[amount]);
        printf("Coins used:\n");
        
        // Backtrack to find the coins used
        int currAmount = amount;
        while (currAmount > 0) {
            if (coinUsed[currAmount] == -1) break; // Break if no coins are left
            int coinIndex = coinUsed[currAmount];
            printf("Coin Value: %d\n", coins[coinIndex].value);
            coins[coinIndex].quantity--; // Decrement the quantity used
            currAmount -= coins[coinIndex].value; // Reduce current amount
        }
    }

    // Free allocated memory
    free(minCoins);
    free(coinUsed);
}

// Function to display available coins and their quantities
void displayCoins(Coin coins[], int n) {
    printf("Available coins and their quantities:\n");
    for (int i = 0; i < n; i++) {
        printf("Coin Value: %d, Quantity: %d\n", coins[i].value, coins[i].quantity);
    }
}

int main() {
    int n;

    // Prompt user for number of coin types
    printf("Enter the number of coin types: ");
    scanf("%d", &n);

    Coin *coins = (Coin *)malloc(n * sizeof(Coin));

    // Prompt user to input coin values and quantities
    for (int i = 0; i < n; i++) {
        printf("Enter value and quantity for coin %d: ", i + 1);
        scanf("%d %d", &coins[i].value, &coins[i].quantity);
    }

    // Display the available coins
    displayCoins(coins, n);

    int amount;
    // Prompt user for the total amount to make change for
    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);

    // Compute the minimum coins needed
    findMinCoins(amount, coins, n);

    // Free allocated memory
    free(coins);

    return 0;
}