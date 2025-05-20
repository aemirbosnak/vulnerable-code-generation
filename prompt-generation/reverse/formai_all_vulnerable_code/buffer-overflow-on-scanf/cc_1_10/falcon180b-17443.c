//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 100
#define MAX_COIN_VALUE 100

// Function to find the minimum number of coins required to make a given amount
int findMinimumCoins(int amount, int coins[], int numCoins) {
    int i, j;
    for (i = 0; i < numCoins; i++) {
        if (coins[i] <= amount) {
            amount -= coins[i];
        } else {
            break;
        }
    }
    if (amount == 0) {
        return numCoins;
    } else {
        return numCoins + 1;
    }
}

int main() {
    int numCoins, i;
    int coins[MAX_NUM_COINS];
    int values[MAX_NUM_COINS];

    // Input the number of coins
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    // Input the values of the coins
    printf("Enter the values of the coins:\n");
    for (i = 0; i < numCoins; i++) {
        scanf("%d", &values[i]);
    }

    // Sort the coins in decreasing order of value
    for (i = 0; i < numCoins - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < numCoins; j++) {
            if (values[j] > values[minIndex]) {
                minIndex = j;
            }
        }
        int temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }

    // Input the amount to be made
    printf("Enter the amount to be made: ");
    int amount;
    scanf("%d", &amount);

    // Find the minimum number of coins required to make the amount
    int minCoins = findMinimumCoins(amount, values, numCoins);

    // Output the result
    printf("Minimum number of coins required: %d\n", minCoins);

    return 0;
}