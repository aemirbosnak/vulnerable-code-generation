//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_COINS 100

int main() {
    int numCoins[MAX_NUM_COINS];
    int numCoinsCount;
    int coinValue[MAX_NUM_COINS];
    int numCoinsToMake;
    int i, j;

    // Initialize numCoins with valid coin values
    numCoins[0] = 1;
    numCoins[1] = 5;
    numCoins[2] = 10;
    numCoins[3] = 25;
    numCoinsCount = 4;

    // Prompt user for amount to make
    printf("Enter amount to make: ");
    scanf("%d", &numCoinsToMake);

    // Initialize coinValue array
    for (i = 0; i < numCoinsCount; i++) {
        coinValue[i] = 0;
    }

    // Initialize numCoins array with 0 coins
    for (i = 0; i < numCoinsCount; i++) {
        numCoins[i] = 0;
    }

    // Greedily make change
    for (i = numCoinsCount - 1; i >= 0; i--) {
        while (numCoinsToMake >= numCoins[i]) {
            numCoinsToMake -= numCoins[i];
            coinValue[i]++;
        }
    }

    // Print result
    printf("Number of coins: ");
    for (i = 0; i < numCoinsCount; i++) {
        for (j = 0; j < coinValue[i]; j++) {
            printf("%d ", numCoins[i]);
        }
    }

    return 0;
}