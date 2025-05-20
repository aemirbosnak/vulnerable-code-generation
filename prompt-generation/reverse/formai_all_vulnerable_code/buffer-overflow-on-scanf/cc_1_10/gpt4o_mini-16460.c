//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: modular
#include <stdio.h>

#define MAX_COINS 100

// Function to get the list of coin denominations from the user
void getCoinDenominations(int *coins, int *numCoins) {
    printf("Enter the number of different coin denominations: ");
    scanf("%d", numCoins);
    
    printf("Enter the coin denominations:\n");
    for (int i = 0; i < *numCoins; i++) {
        printf("Coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }
}

// Function to calculate the minimum number of coins for a given amount
void calculateChange(int amount, int *coins, int numCoins, int *coinCount) {
    // Sort coins in descending order for greedy approach
    for (int i = 0; i < numCoins - 1; i++) {
        for (int j = 0; j < numCoins - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    // Calculate the change using the greedy method
    for (int i = 0; i < numCoins; i++) {
        if (amount <= 0) {
            break; // If amount becomes zero or negative, we are done
        }
        coinCount[i] = amount / coins[i]; // Maximum coins of this denomination
        amount -= coinCount[i] * coins[i]; // Decrease amount by the total value of those coins
    }
}

// Function to display the result of the change calculation
void displayChange(int *coins, int *coinCount, int numCoins) {
    printf("The minimum number of coins needed for the change:\n");
    for (int i = 0; i < numCoins; i++) {
        if (coinCount[i] > 0) {
            printf("%d coins of denomination %d\n", coinCount[i], coins[i]);
        }
    }
}

// Main function
int main() {
    int coins[MAX_COINS];
    int numCoins;
    int coinCount[MAX_COINS] = {0};

    int amount;
    printf("Enter the amount for which change is to be calculated: ");
    scanf("%d", &amount);

    // Get coin denominations
    getCoinDenominations(coins, &numCoins);

    // Calculate the change
    calculateChange(amount, coins, numCoins, coinCount);

    // Display the result
    displayChange(coins, coinCount, numCoins);

    return 0;
}