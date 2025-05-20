//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>

#define MAX_COINS 100
#define MAX_DENOMINATIONS 10

// Function to calculate minimum coins needed
int minimumCoins(int denominations[], int numDenominations, int amount) {
    int coinCount = 0; // To keep track of the number of coins used
    int i;

    // To keep track of how many coins we have used for each denomination
    int coinsUsed[MAX_DENOMINATIONS] = {0};

    // Start the greedy approach - diving into the treasure chest
    printf("Searching for the least amount of coins to unveil the treasure...\n");
    
    for (i = 0; i < numDenominations; i++) {
        // While the remaining amount is greater than the coin value
        while (amount >= denominations[i]) {
            amount -= denominations[i]; // Take the coin
            coinCount++;                // Increment the coin count
            coinsUsed[i]++;             // Keep track of how many coins we've used
            printf("   Using a coin of %d, remaining amount: %d\n", denominations[i], amount);
        }
    }

    // If there's any amount left that cannot be made
    if (amount > 0) {
        printf("\nThe treasure remains shrouded in mystery, remaining amount: %d\n", amount);
        return -1; // Not possible to make change
    }

    printf("\nWe have successfully unveiled the treasure with minimum coins used: %d\n", coinCount);
    printf("Coins used distribution:\n");

    for (i = 0; i < numDenominations; i++) {
        if (coinsUsed[i] > 0) {
            printf("   %d coin(s) of %d denomination\n", coinsUsed[i], denominations[i]);
        }
    }
    
    return coinCount; // Return the total number of coins used
}

int main() {
    // The Winkling Whisper of the Denominations
    int denominations[MAX_DENOMINATIONS] = {25, 10, 5, 1}; // Representing quarters, dimes, nickels, and pennies
    int amount;
    
    // Welcome to the Great Coin Quest
    printf("Welcome to the Great Coin Quest!\n");
    printf("Please enter the amount you wish to change (in cents, e.g., 99): ");
    scanf("%d", &amount);

    // Call the function to get the minimum coins needed
    if (minimumCoins(denominations, 4, amount) == -1) {
        printf("Quest for change is failed, perhaps some magic is at play...\n");
    }

    return 0; // Exit gracefully
}