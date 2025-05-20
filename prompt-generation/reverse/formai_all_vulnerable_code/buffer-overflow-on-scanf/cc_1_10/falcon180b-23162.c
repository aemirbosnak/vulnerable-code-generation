//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 5

typedef struct {
    int value;
    char name[10];
} Coin;

void initCoins(Coin coins[]) {
    strcpy(coins[0].name, "Penny");
    coins[0].value = 1;

    strcpy(coins[1].name, "Nickel");
    coins[1].value = 5;

    strcpy(coins[2].name, "Dime");
    coins[2].value = 10;

    strcpy(coins[3].name, "Quarter");
    coins[3].value = 25;

    strcpy(coins[4].name, "Dollar");
    coins[4].value = 100;
}

int main() {
    int n;
    printf("Enter the amount of change to be made: ");
    scanf("%d", &n);

    Coin coins[MAX_COINS];
    initCoins(coins);

    int i = 0;
    while (n > 0) {
        if (i >= MAX_COINS) {
            printf("Not enough coins to make change.\n");
            return 0;
        }

        if (coins[i].value <= n) {
            n -= coins[i].value;
            printf("Using %s (%d cents).\n", coins[i].name, coins[i].value);
        } else {
            i++;
        }
    }

    printf("Change made successfully.\n");
    return 0;
}