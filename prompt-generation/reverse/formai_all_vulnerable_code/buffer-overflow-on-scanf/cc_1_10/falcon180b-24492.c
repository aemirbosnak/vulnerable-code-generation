//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_COINS 100

int main() {
    int numCoins[MAX_NUM_COINS];
    int numCoinsCount = 0;
    int numCoinsValue[MAX_NUM_COINS];
    int numCoinsValueCount = 0;
    int totalValue = 0;
    int numCoinsToMakeValue = 0;
    int i, j;

    printf("Enter the number of coins: ");
    scanf("%d", &numCoinsCount);

    for (i = 0; i < numCoinsCount; i++) {
        printf("Enter the value of coin %d: ", i+1);
        scanf("%d", &numCoinsValue[i]);
        totalValue += numCoinsValue[i];
    }

    printf("Enter the value to make: ");
    scanf("%d", &numCoinsToMakeValue);

    numCoins[0] = numCoinsValue[numCoinsValueCount-1];
    numCoinsValueCount--;

    while (numCoinsToMakeValue > 0 && numCoinsValueCount > 0) {
        for (i = 0; i < numCoinsValueCount; i++) {
            if (numCoinsValue[i] <= numCoinsToMakeValue) {
                numCoins[numCoinsCount] = numCoinsValue[i];
                numCoinsCount++;
                numCoinsToMakeValue -= numCoinsValue[i];
                break;
            }
        }
        if (numCoinsToMakeValue == 0) {
            break;
        }
        if (i == numCoinsValueCount-1) {
            numCoins[numCoinsCount] = numCoinsValue[0];
            numCoinsCount++;
            numCoinsValueCount--;
            numCoinsToMakeValue -= numCoinsValue[0];
        }
    }

    printf("Minimum number of coins required: %d\n", numCoinsCount);
    printf("Coins used: ");
    for (i = 0; i < numCoinsCount; i++) {
        printf("%d ", numCoins[i]);
    }
    printf("\n");

    return 0;
}