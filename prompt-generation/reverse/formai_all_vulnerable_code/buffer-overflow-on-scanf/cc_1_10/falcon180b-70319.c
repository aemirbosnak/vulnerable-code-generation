//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 10
#define MAX_VALUE 1000

typedef struct {
    int value;
    int count;
} Coin;

int cmp(const void *a, const void *b) {
    Coin *ca = (Coin *)a;
    Coin *cb = (Coin *)b;
    return (*ca).value - (*cb).value;
}

int getMinCoins(int value, Coin coins[], int numCoins) {
    qsort(coins, numCoins, sizeof(Coin), cmp);
    int minCoins = 0;
    for (int i = 0; i < numCoins; i++) {
        if (coins[i].value <= value) {
            value -= coins[i].value;
            minCoins += coins[i].count;
        } else {
            break;
        }
    }
    return minCoins;
}

int main() {
    int numCoins;
    printf("Enter the number of coins (up to %d): ", MAX_NUM_COINS);
    scanf("%d", &numCoins);

    Coin coins[MAX_NUM_COINS];
    printf("Enter the values and counts of the coins:\n");
    for (int i = 0; i < numCoins; i++) {
        int value, count;
        printf("Coin %d: ", i + 1);
        scanf("%d %d", &value, &count);
        coins[i].value = value;
        coins[i].count = count;
    }

    int value;
    printf("Enter the value to make change for: ");
    scanf("%d", &value);

    int minCoins = getMinCoins(value, coins, numCoins);
    printf("The minimum number of coins needed to make change for %d is %d.\n", value, minCoins);

    return 0;
}