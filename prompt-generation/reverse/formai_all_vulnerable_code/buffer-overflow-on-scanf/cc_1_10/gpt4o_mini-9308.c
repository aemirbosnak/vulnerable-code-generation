//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>

#define MAX_COINS 100
#define MAX_AMOUNT 10000

// Function to find the minimum number of coins for a given amount
int minCoins(int coins[], int numCoins, int amount) {
    int count = 0;
    
    // Sort coins in descending order
    for (int i = 0; i < numCoins; i++) {
        for (int j = i + 1; j < numCoins; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    // Iterate over the sorted list of coins
    for (int i = 0; i < numCoins; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }

    // If we still have remaining amount, it means it's not possible
    if (amount > 0) {
        printf("Change cannot be made for the remaining amount: %d\n", amount);
        return -1; // Indicating failure
    }

    return count;
}

int main() {
    int coins[MAX_COINS];
    int numCoins, amount;

    printf("Enter the number of different coin denominations: ");
    scanf("%d", &numCoins);
    
    printf("Enter the coin denominations (space-separated): ");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount to change: ");
    scanf("%d", &amount);

    int result = minCoins(coins, numCoins, amount);
    
    if (result != -1) {
        printf("Minimum number of coins needed: %d\n", result);
    }

    return 0;
}