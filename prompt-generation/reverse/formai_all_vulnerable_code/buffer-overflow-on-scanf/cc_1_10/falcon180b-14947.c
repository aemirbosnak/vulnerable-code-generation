//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_COINS 1000

int main() {
    int numCoins[MAX_NUM_COINS];
    int numCoinsCount = 0;
    int numCoinsIndex = 0;
    int numCoinsValue[MAX_NUM_COINS];
    int numCoinsDenomination[MAX_NUM_COINS];
    int numCoinsQuantity[MAX_NUM_COINS];
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int sum;
    int change;
    int index;
    int quantity;
    int denomination;
    int value;
    int minDenomination;
    int minValue;
    int minQuantity;
    int minIndex;
    int flag;

    printf("Enter the number of coins: ");
    scanf("%d", &numCoinsCount);

    printf("Enter the denomination, value, and quantity of each coin:\n");

    for (i = 0; i < numCoinsCount; i++) {
        printf("Denomination: ");
        scanf("%d", &numCoinsDenomination[i]);
        printf("Value: ");
        scanf("%d", &numCoinsValue[i]);
        printf("Quantity: ");
        scanf("%d", &numCoinsQuantity[i]);
        numCoins[numCoinsIndex++] = numCoinsDenomination[i];
    }

    numCoins[numCoinsIndex++] = 0;

    for (i = 0; i < numCoinsCount; i++) {
        numCoinsValue[i] /= numCoinsQuantity[i];
    }

    for (i = 0; i < numCoinsCount; i++) {
        minDenomination = numCoinsDenomination[i];
        minValue = numCoinsValue[i];
        minQuantity = numCoinsQuantity[i];
        minIndex = i;

        for (j = i + 1; j < numCoinsCount; j++) {
            if (numCoinsValue[j] > minValue) {
                minValue = numCoinsValue[j];
                minDenomination = numCoinsDenomination[j];
                minQuantity = numCoinsQuantity[j];
                minIndex = j;
            }
        }

        for (j = 0; j < minQuantity; j++) {
            numCoins[numCoinsIndex++] = minDenomination;
        }
    }

    printf("\nMinimum number of coins required to make change: %d\n", numCoinsIndex - 1);

    return 0;
}