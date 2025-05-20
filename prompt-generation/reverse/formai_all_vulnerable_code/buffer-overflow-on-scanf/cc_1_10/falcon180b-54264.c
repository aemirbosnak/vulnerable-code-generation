//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 5

typedef struct {
    int value;
    int index;
} Coin;

int main() {
    int numCoins, i, j, maxValue, sum = 0;
    Coin coins[MAX_NUM_COINS];

    // Initialize coins
    coins[0].value = 1;
    coins[0].index = 0;
    coins[1].value = 5;
    coins[1].index = 1;
    coins[2].value = 10;
    coins[2].index = 2;
    coins[3].value = 25;
    coins[3].index = 3;
    coins[4].value = 50;
    coins[4].index = 4;

    // Sort coins in descending order
    for (i = 0; i < MAX_NUM_COINS - 1; i++) {
        for (j = i + 1; j < MAX_NUM_COINS; j++) {
            if (coins[i].value < coins[j].value) {
                Coin temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    printf("Enter the amount to be changed: ");
    scanf("%d", &numCoins);

    // Greedy algorithm to find the minimum number of coins
    maxValue = coins[0].value;
    for (i = 0; i < MAX_NUM_COINS; i++) {
        if (coins[i].value <= numCoins) {
            sum += coins[i].value;
            numCoins -= coins[i].value;
        }
    }

    printf("Minimum number of coins required: %d\n", sum);

    return 0;
}