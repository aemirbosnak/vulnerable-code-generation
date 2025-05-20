//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_VALUES 7

int main() {
    int coins[MAX_COINS] = {1, 5, 10, 25, 50, 100};
    int values[MAX_VALUES] = {1, 5, 10, 25, 50, 100, 200};
    int numCoins = 0;
    int numValues = 0;
    int i, j;

    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);
    printf("Enter the number of values: ");
    scanf("%d", &numValues);

    int coinValues[MAX_COINS] = {0};
    int valueCounts[MAX_VALUES] = {0};

    for (i = 0; i < numCoins; i++) {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coinValues[i]);
    }

    for (i = 0; i < numValues; i++) {
        printf("Enter the number of values for %d: ", values[i]);
        scanf("%d", &valueCounts[i]);
    }

    int totalCoins = 0;
    for (i = 0; i < numValues; i++) {
        int value = values[i];
        int count = valueCounts[i];
        while (count > 0 && value <= MAX_VALUES) {
            int coin = 0;
            for (j = 0; j < numCoins; j++) {
                if (coinValues[j] >= value) {
                    coin = j;
                    break;
                }
            }
            if (coin == 0) {
                break;
            }
            value -= coinValues[coin];
            totalCoins++;
            count--;
        }
    }

    printf("Total number of coins required: %d\n", totalCoins);

    return 0;
}