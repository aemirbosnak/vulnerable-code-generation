//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: satisfied
#include <stdio.h>

// Function to find the minimum number of coins needed to make change
int minCoins(int coins[], int numCoins, int amount) {
    int count = 0;
    
    // Iterate over the available coins from largest to smallest
    for (int i = numCoins - 1; i >= 0; i--) {
        // While the current coin can be used to reduce the amount
        while (amount >= coins[i]) {
            amount -= coins[i]; // Subtract the coin value from the amount
            count++; // Increase the count of coins used
        }
    }
    
    // If amount is not zero, that means change cannot be made completely
    if (amount > 0) {
        printf("Cannot make change for the amount using given denominations.\n");
        return -1; // Indicate failure
    }
    
    return count; // Successfully made change, return count of coins
}

// Main function to demonstrate the greedy algorithm for coin change
int main() {
    int coins[] = {1, 5, 10, 25}; // Available coin denominations (in cents)
    int numCoins = sizeof(coins) / sizeof(coins[0]); // Number of coin types
    int amount; // Amount to make change for
    
    // User input for the amount
    printf("Enter the amount in cents: ");
    scanf("%d", &amount);
    
    // Checking for positive amount
    if (amount < 0) {
        printf("Please enter a non-negative amount.\n");
        return 1; // Exit with error status
    }
    
    // Call the minCoins function to find the result
    int result = minCoins(coins, numCoins, amount);
    
    // If result is valid, print the result
    if (result != -1) {
        printf("Minimum number of coins needed: %d\n", result);
    }

    return 0; // Normal exit
}