//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 6

// Function to find the minimum number of coins required to make a given amount
int findMinimumCoins(int amount, int *coins, int coinCount) {
    int i, j;
    int minCoins = amount;

    // Loop through all possible combinations of coins
    for (i = 0; i < coinCount; i++) {
        for (j = i; j < coinCount; j++) {
            // If the combination of coins is less than the current minimum, update the minimum
            if ((coins[i] + coins[j]) < minCoins) {
                minCoins = coins[i] + coins[j];
            }
        }
    }

    return minCoins;
}

int main() {
    int i, j, k;
    int amount, coinCount, coins[MAX_COINS];

    // Get the amount of money to be made
    printf("Enter the amount of money to be made: ");
    scanf("%d", &amount);

    // Generate random coins
    srand(time(NULL));
    for (i = 0; i < MAX_COINS; i++) {
        coins[i] = rand() % 100 + 1;
    }

    // Sort the coins in descending order
    for (i = 0; i < MAX_COINS - 1; i++) {
        for (j = i + 1; j < MAX_COINS; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    // Find the minimum number of coins required to make the given amount
    coinCount = findMinimumCoins(amount, coins, MAX_COINS);

    // Print the result
    printf("Minimum number of coins required: %d\n", coinCount);
    printf("Coins used: ");
    for (i = 0; i < coinCount; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    return 0;
}