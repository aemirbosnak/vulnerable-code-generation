//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_NUM_COINS 6
#define MAX_VALUE_COINS 5

typedef struct {
    int value;
    char name[MAX_LENGTH];
} Coin;

int compare(const void *a, const void *b) {
    Coin *coinA = (Coin *) a;
    Coin *coinB = (Coin *) b;

    return coinA->value - coinB->value;
}

int main() {
    int numCoins, i, j, numSelectedCoins;
    Coin coins[MAX_NUM_COINS];
    int sum = 0;
    int target = 63;

    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    for (i = 0; i < numCoins; i++) {
        printf("Enter the value and name of coin %d: ", i + 1);
        scanf("%d %s", &coins[i].value, coins[i].name);
    }

    qsort(coins, numCoins, sizeof(Coin), compare);

    for (numSelectedCoins = 0, i = 0; i < numCoins && sum < target; i++) {
        if (coins[i].value <= target) {
            sum += coins[i].value;
            numSelectedCoins++;
        }
    }

    if (sum == target) {
        printf("The minimum number of coins required is: %d\n", numSelectedCoins);
    } else {
        printf("It is not possible to make change for %d cents.\n", target);
    }

    return 0;
}