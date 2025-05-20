//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>

#define MAX_COINS 100
#define MAX_DENOMINATIONS 10

// Function to display the coins used
void displayCoins(int coins[], int coinCount) {
    printf("You received:\n");
    for (int i = 0; i < coinCount; i++) {
        if (coins[i] > 0) {
            printf("-> %d coins of denomination %d\n", coins[i], i + 1);
        }
    }
}

// Greedy algorithm function to make change
void makeChange(int denominations[], int numDenominations, int amount) {
    int coins[MAX_COINS] = {0}; // To store the count of coins for each denomination
    int currentAmount = amount;

    // Start making change
    for (int i = numDenominations - 1; i >= 0; i--) {
        while (currentAmount >= denominations[i]) {
            currentAmount -= denominations[i];
            coins[i]++;
        }
    }

    // If there is any remaining amount that couldn't be made
    if (currentAmount > 0) {
        printf("Oops! We couldn't make change for the remaining amount: %d.\n", currentAmount);
    } else {
        displayCoins(coins, numDenominations);
    }
}

int main() {
    int denominations[MAX_DENOMINATIONS] = {1, 5, 10, 25}; // US coin denominations
    int amount;

    printf("Welcome to the Joyful Change Maker!\n");
    printf("Let's make some change! What amount would you like to change?\n");
    printf("Please enter a positive integer amount in cents: ");
    
    if(scanf("%d", &amount) != 1 || amount < 0) {
        printf("Oops! That wasn't a valid positive integer.\n");
        return 1; // Exit the program if input is invalid
    }

    printf("Hooray! Let's make change for %d cents using our cheerful denominations!\n", amount);
    makeChange(denominations, sizeof(denominations) / sizeof(denominations[0]), amount);

    printf("Thank you for using the Joyful Change Maker! Have a wonderful day!\n");
    return 0;
}