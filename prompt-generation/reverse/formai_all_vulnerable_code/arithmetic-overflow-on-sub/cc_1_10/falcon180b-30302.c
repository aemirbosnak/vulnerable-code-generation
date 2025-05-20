//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 6
#define MAX_VALUE 1000

int coinValues[MAX_COINS] = {1, 5, 10, 25, 50, 100};
int numCoins;
int maxValue;
int memo[MAX_VALUE + 1][MAX_COINS + 1];

int greedyAlgorithm(int value, int lastCoin) {
    if (value == 0) {
        return 0;
    }
    if (value < 0) {
        return -1;
    }
    if (lastCoin >= numCoins) {
        return -1;
    }

    if (memo[value][lastCoin]!= -1) {
        return memo[value][lastCoin];
    }

    int result = -1;
    for (int i = 0; i <= lastCoin; i++) {
        if (value >= coinValues[i]) {
            int subResult = greedyAlgorithm(value - coinValues[i], i);
            if (subResult!= -1) {
                result = subResult + 1;
                break;
            }
        }
    }

    memo[value][lastCoin] = result;
    return result;
}

int main() {
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    printf("Enter the maximum value: ");
    scanf("%d", &maxValue);

    for (int i = 0; i <= maxValue; i++) {
        for (int j = 0; j <= numCoins; j++) {
            memo[i][j] = -1;
        }
    }

    int minCoins = greedyAlgorithm(maxValue, numCoins - 1);
    if (minCoins == -1) {
        printf("No combination of coins found.\n");
    } else {
        printf("Minimum number of coins required: %d\n", minCoins);
    }

    return 0;
}