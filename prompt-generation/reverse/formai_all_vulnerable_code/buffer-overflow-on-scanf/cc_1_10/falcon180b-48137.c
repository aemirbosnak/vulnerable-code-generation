//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 100
#define MAX_VALUE 1000

int main() {
    int numCoins[MAX_NUM_COINS];
    int numCoinsUsed = 0;
    int numCoinsTotal = 0;
    int i, j, numValues = 0;
    int values[MAX_NUM_COINS];
    int maxValue = 0;

    printf("Enter the number of coins: ");
    scanf("%d", &numCoinsTotal);

    printf("Enter the values of the coins:\n");
    for (i = 0; i < numCoinsTotal; i++) {
        scanf("%d", &values[i]);
        if (values[i] > maxValue) {
            maxValue = values[i];
        }
    }

    printf("Enter the number of coins to make change: ");
    scanf("%d", &numValues);

    printf("Enter the values of the coins to use:\n");
    for (i = 0; i < numValues; i++) {
        scanf("%d", &numCoins[i]);
    }

    // Sort the coins in descending order
    for (i = 0; i < numValues; i++) {
        for (j = i + 1; j < numValues; j++) {
            if (numCoins[i] < numCoins[j]) {
                int temp = numCoins[i];
                numCoins[i] = numCoins[j];
                numCoins[j] = temp;
            }
        }
    }

    // Initialize the number of coins used to the smallest coin
    numCoinsUsed = numCoins[0];

    // Use the smallest coins to make change
    for (i = 0; i < numValues; i++) {
        while (numCoins[i] <= numValues - numCoinsUsed) {
            numCoins[i] += numValues - numCoinsUsed;
            numCoinsUsed += numCoins[i];
        }
    }

    printf("Number of coins used: %d\n", numCoinsUsed);

    return 0;
}