//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_COINS 6

// Function to find the minimum number of coins required to make a given amount
int findMinimumCoins(int amount, int coins[], int numCoins) {
    int i, j;
    for (i = 0; i < numCoins; i++) {
        if (coins[i] <= amount) {
            for (j = i + 1; j < numCoins; j++) {
                if (coins[j] <= amount) {
                    amount -= coins[j];
                }
            }
            return i + 1;
        }
    }
    return 0;
}

// Function to print the array of coins
void printCoins(int coins[], int numCoins) {
    int i;
    for (i = 0; i < numCoins; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");
}

// Function to generate a random array of coins
void generateRandomCoins(int coins[], int numCoins) {
    int i;
    for (i = 0; i < numCoins; i++) {
        coins[i] = rand() % 101; // Generate a random coin between 1 and 100
    }
}

int main() {
    int coins[MAX_NUM_COINS]; // Array to store the coins
    int numCoins; // Number of coins in the array
    int amount; // Amount to make change for
    int minCoins; // Minimum number of coins required to make the amount

    // Get the number of coins from the user
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    // Generate a random array of coins
    generateRandomCoins(coins, numCoins);

    // Print the array of coins
    printf("Array of coins:\n");
    printCoins(coins, numCoins);

    // Get the amount to make change for from the user
    printf("Enter the amount to make change for: ");
    scanf("%d", &amount);

    // Find the minimum number of coins required to make the amount
    minCoins = findMinimumCoins(amount, coins, numCoins);

    // Print the result
    if (minCoins == 0) {
        printf("No coins can make %d.\n", amount);
    } else {
        printf("%d can be made with %d coins:\n", amount, minCoins);
        printCoins(coins, minCoins);
    }

    return 0;
}