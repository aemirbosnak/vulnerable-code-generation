//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of coins in the collection
#define MAX_COINS 100

// Define the maximum denomination of a coin
#define MAX_DENOMINATION 100

// Declare the array of coins
int coins[MAX_COINS];

// Function to sort the coins in descending order
void sortCoins(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
}

// Function to find the maximum value of coins that can be collected
int maxCoins(int n) {
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        if (coins[i] <= maxValue) {
            break;
        }
        maxValue += coins[i];
    }
    return maxValue;
}

int main() {
    // Get the number of coins in the collection
    int n;
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    // Get the denominations of the coins
    printf("Enter the denominations of the coins: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Sort the coins in descending order
    sortCoins(n);

    // Find the maximum value of coins that can be collected
    int maxValue = maxCoins(n);

    // Print the maximum value
    printf("The maximum value of coins that can be collected is: %d\n", maxValue);

    return 0;
}