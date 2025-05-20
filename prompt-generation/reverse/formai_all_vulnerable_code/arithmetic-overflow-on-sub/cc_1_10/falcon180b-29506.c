//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 1000000
#define MAX_VALUE 1000000

struct coin {
    int value;
    int index;
};

void sortCoins(struct coin *coins, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coins[i].value > coins[j].value) {
                struct coin temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
}

int greedyAlgorithm(struct coin *coins, int n) {
    int totalValue = 0;
    int coinsUsed = 0;
    int lastIndex = -1;

    sortCoins(coins, n);

    for (int i = 0; i < n; i++) {
        if (coins[i].value <= MAX_VALUE) {
            totalValue += coins[i].value;
            coinsUsed++;
        } else {
            break;
        }
    }

    return coinsUsed;
}

int main() {
    struct coin coins[MAX_COINS];
    int n;

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the values of the coins:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i].value);
        coins[i].index = i;
    }

    int coinsUsed = greedyAlgorithm(coins, n);
    printf("The minimum number of coins used is: %d\n", coinsUsed);

    return 0;
}