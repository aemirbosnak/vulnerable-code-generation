//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 6

typedef struct {
    int value;
    char *name;
} Coin;

Coin coins[MAX_NUM_COINS] = {
    {1, "Penny"},
    {5, "Nickel"},
    {10, "Dime"},
    {25, "Quarter"},
    {50, "Half Dollar"},
    {100, "Dollar"}
};

int main() {
    int num_coins;
    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    int total_value = 0;
    int coin_values[MAX_NUM_COINS] = {0};

    for (int i = 0; i < num_coins; i++) {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coin_values[i]);
        total_value += coin_values[i];
    }

    int num_coins_used = 0;
    int coins_used[MAX_NUM_COINS] = {0};

    for (int i = 0; i < num_coins; i++) {
        for (int j = 0; j < MAX_NUM_COINS; j++) {
            if (coins[j].value == coin_values[i]) {
                coins_used[j]++;
                num_coins_used++;
                break;
            }
        }
    }

    printf("Total value: $%d\n", total_value);
    printf("Number of coins used: %d\n", num_coins_used);

    for (int i = 0; i < MAX_NUM_COINS; i++) {
        if (coins_used[i] > 0) {
            printf("%d %s used.\n", coins_used[i], coins[i].name);
        }
    }

    return 0;
}