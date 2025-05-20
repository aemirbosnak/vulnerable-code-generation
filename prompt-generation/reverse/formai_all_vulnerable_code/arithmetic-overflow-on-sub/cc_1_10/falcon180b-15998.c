//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 10000

int main() {
    int numCoins, coinValues[MAX_COINS], i, j, k;
    char input[100];

    printf("Welcome to the Greedy Algorithm Coin Problem!\n");
    printf("Enter the number of coins you have: ");
    scanf("%d", &numCoins);

    // Initialize coin values
    for (i = 0; i < numCoins; i++) {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coinValues[i]);
    }

    // Sort coin values in descending order
    for (i = 0; i < numCoins - 1; i++) {
        for (j = i + 1; j < numCoins; j++) {
            if (coinValues[i] < coinValues[j]) {
                int temp = coinValues[i];
                coinValues[i] = coinValues[j];
                coinValues[j] = temp;
            }
        }
    }

    // Initialize the number of coins used to 0
    int coinsUsed = 0;

    // Initialize the maximum value that can be obtained using the current number of coins
    int maxValue = coinValues[0];

    // Iterate through the coin values and add them to the current total value
    for (i = 0; i < numCoins; i++) {
        // Initialize the number of coins used for the current value to 0
        int coinsUsedForValue = 0;

        // Check if the current coin value can be added to the current total value without exceeding the maximum value
        if (maxValue >= coinValues[i]) {
            // Add the current coin value to the current total value
            maxValue += coinValues[i];

            // Increment the number of coins used for the current value
            coinsUsedForValue++;

            // Update the maximum value that can be obtained using the current number of coins
            if (coinsUsedForValue > coinsUsed) {
                coinsUsed = coinsUsedForValue;
                maxValue = coinValues[i];
            }
        }
    }

    // Print the maximum value that can be obtained using the current number of coins
    printf("The maximum value that can be obtained using %d coins is %d.\n", numCoins, maxValue);

    return 0;
}