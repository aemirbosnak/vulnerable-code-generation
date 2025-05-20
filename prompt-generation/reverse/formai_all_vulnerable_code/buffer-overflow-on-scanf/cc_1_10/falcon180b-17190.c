//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 6
#define MAX_VALUE 100

typedef struct {
    int value;
    char name[10];
} Coin;

Coin coins[MAX_COINS] = {
    {1, "Penny"},
    {5, "Nickel"},
    {10, "Dime"},
    {25, "Quarter"},
    {50, "Half Dollar"},
    {100, "Dollar"}
};

int main() {
    int numCoins, i;
    int targetValue = rand() % MAX_VALUE + 1;

    printf("You have %d cents. How many coins do you have?\n", targetValue);
    scanf("%d", &numCoins);

    int coinsUsed[MAX_COINS] = {0};
    int totalValue = 0;

    for (i = 0; i < numCoins; i++) {
        int coinValue = rand() % MAX_VALUE + 1;
        int coinIndex = -1;

        while (coinValue > 0 && coinIndex == -1) {
            coinIndex = rand() % MAX_COINS;
            if (coins[coinIndex].value <= coinValue) {
                totalValue += coins[coinIndex].value;
                coinsUsed[coinIndex]++;
                coinValue -= coins[coinIndex].value;
            }
        }
    }

    printf("You used %d %s.\n", coinsUsed[0], coins[0].name);
    for (i = 1; i < MAX_COINS; i++) {
        if (coinsUsed[i] > 0) {
            printf("You used %d %s.\n", coinsUsed[i], coins[i].name);
        }
    }

    return 0;
}