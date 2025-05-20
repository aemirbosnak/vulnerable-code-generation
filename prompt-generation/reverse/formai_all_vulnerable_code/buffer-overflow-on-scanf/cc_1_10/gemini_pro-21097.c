//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers
int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

// Function to find the minimum number of coins needed to make change for a given amount
int min_coins(int coins[], int n, int amount) {
    // Sort the coins in decreasing order
    qsort(coins, n, sizeof(int), compare);

    // Initialize the number of coins needed to 0
    int num_coins = 0;

    // Iterate over the coins in decreasing order
    for (int i = 0; i < n; i++) {
        // While the amount is greater than or equal to the current coin, add the current coin to the amount and increment the number of coins needed
        while (amount >= coins[i]) {
            amount -= coins[i];
            num_coins++;
        }
    }

    // Return the number of coins needed
    return num_coins;
}

// Main function
int main() {
    // Get the number of coins and the amount
    int n, amount;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Get the coins
    int coins[n];
    printf("Enter the coins: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Find the minimum number of coins needed
    int num_coins = min_coins(coins, n, amount);

    // Print the minimum number of coins needed
    printf("The minimum number of coins needed is: %d\n", num_coins);

    return 0;
}