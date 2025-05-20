//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_COINS 6
#define MAX_AMOUNT 1000

struct coin {
    int value;
    char *name;
};

struct coin coins[MAX_COINS] = {
    {1, "Penny"},
    {5, "Nickel"},
    {10, "Dime"},
    {25, "Quarter"},
    {50, "Half Dollar"},
    {100, "Dollar"}
};

int main() {
    int amount;
    int coins_used = 0;
    int i = 0;
    int j = MAX_COINS - 1;
    int coin_value;
    int min_coins;
    int change;
    int remaining_amount;
    char *coin_name;

    printf("Enter the amount: ");
    scanf("%d", &amount);

    remaining_amount = amount;

    while (remaining_amount > 0) {
        min_coins = MAX_COINS;
        for (i = 0; i <= j; i++) {
            coin_value = coins[i].value;
            if (remaining_amount >= coin_value) {
                if (min_coins > 1) {
                    if (remaining_amount - coin_value < coins[i + 1].value) {
                        min_coins = 1;
                    }
                } else {
                    min_coins = 1;
                }
            }
        }

        if (min_coins == MAX_COINS) {
            printf("Cannot make change for %d cents\n", amount);
            return 0;
        }

        coin_value = coins[j].value;
        change = remaining_amount - coin_value;
        remaining_amount = coin_value;

        if (min_coins == 1) {
            coin_name = coins[j].name;
            printf("Using %d %s\n", coins[j].value, coin_name);
            coins_used++;
        } else {
            coin_name = coins[j - 1].name;
            printf("Using %d %s\n", coins[j - 1].value, coin_name);
            coins_used += min_coins;
        }

        j -= min_coins;
    }

    printf("Total coins used: %d\n", coins_used);

    return 0;
}