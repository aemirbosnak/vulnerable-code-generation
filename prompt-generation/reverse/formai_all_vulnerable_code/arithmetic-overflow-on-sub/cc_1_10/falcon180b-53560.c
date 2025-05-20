//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 5
#define MAX_VALUES 100

int main() {
    int numValues, i;
    int values[MAX_VALUES];
    int coins[MAX_COINS];
    int numCoins;
    int totalValue = 0;

    // Get the number of values from the user
    printf("Enter the number of values: ");
    scanf("%d", &numValues);

    // Get the values from the user
    printf("Enter the values:\n");
    for (i = 0; i < numValues; i++) {
        scanf("%d", &values[i]);
        totalValue += values[i];
    }

    // Get the number of coins from the user
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    // Get the values of the coins from the user
    printf("Enter the values of the coins:\n");
    for (i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }

    // Sort the coins in descending order
    for (i = 0; i < numCoins - 1; i++) {
        for (int j = i + 1; j < numCoins; j++) {
            if (coins[j] > coins[i]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    // Greedy algorithm to find the minimum number of coins to make the total value
    int numCoinsUsed = 0;
    for (int j = numCoins - 1; j >= 0; j--) {
        if (totalValue - coins[j] >= 0) {
            totalValue -= coins[j];
            numCoinsUsed++;
        }
    }

    printf("Total value: %d\n", totalValue);
    printf("Number of coins used: %d\n", numCoinsUsed);

    return 0;
}