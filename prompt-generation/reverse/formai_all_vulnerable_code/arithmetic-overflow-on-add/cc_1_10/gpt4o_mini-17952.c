//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>

#define MAX_COINS 10

// Function prototype declarations
int minCoins(int coins[], int numCoins, int amount);
void printCoinUsage(int coins[], int numCoins, int amount, int *coinCount);

// Main function to start the journey
int main() {
    // Behold! Our dazzling array of coins
    int coins[MAX_COINS] = {1, 5, 10, 25};
    int numCoins = 4; // The valiant number of different coins we have
    int amount;

    // The grand question! How much money do we need to change?
    printf("Enter the amount to change: ");
    scanf("%d", &amount);

    printf("\nLet's see the magic of coins in action!\n");
    
    // Call for action! Compute the minimum coins required
    int result = minCoins(coins, numCoins, amount);
    
    // If we got an answer, let’s celebrate!
    if (result != -1) {
        printf("\nMinimum coins required: %d\n", result);
        int coinCount[MAX_COINS] = {0}; // Let's track our coin usage
        printCoinUsage(coins, numCoins, amount, coinCount);
        printf("\nCoin Composition: \n");
        
        for (int i = 0; i < numCoins; i++) {
            if (coinCount[i] > 0) {
                printf("Coin %d: %d times\n", coins[i], coinCount[i]);
            }
        }
    } else {
        // A sad trombone, if we have no way to give change
        printf("Oh no! Change for %d can't be made with the available coins.\n", amount);
    }

    return 0;
}

// This function computes the minimum coins needed, like a wizard crafting spells
int minCoins(int coins[], int numCoins, int amount) {
    // Array to store the minimum coins needed for each value
    int dp[amount + 1];
    
    // Initialize the dp array with infinity
    for (int i = 0; i <= amount; i++) {
        dp[i] = amount + 1; // A number larger than any possible coin count
    }
    
    // Base case: 0 coins needed to make change for 0
    dp[0] = 0;

    // Traverse through each coin
    for (int i = 0; i < numCoins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            // If using this coin is better, update our dp array
            if (dp[j - coins[i]] + 1 < dp[j]) {
                dp[j] = dp[j - coins[i]] + 1;
            }
        }
    }

    // If we can make the 'amount', return it; otherwise, return -1
    return (dp[amount] > amount) ? -1 : dp[amount];
}

// A fun little function to print out how many coins of each type we've used
void printCoinUsage(int coins[], int numCoins, int amount, int *coinCount) {
    // While we still have amount to account for...
    for (int i = 0; amount > 0 && i < numCoins; i++) {
        while (amount >= coins[i]) { // As long as we can use this coin
            amount -= coins[i]; // Take that coin!
            coinCount[i]++; // Count it as used
        }
    }
}