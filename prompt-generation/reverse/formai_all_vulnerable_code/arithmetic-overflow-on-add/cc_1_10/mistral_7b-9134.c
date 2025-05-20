//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_COINS_COUNT 100
#define MIN_CHANGE 0

typedef struct Coin {
    int value;
    int count;
} Coin;

void print_coins(Coin coins[], int n) {
    printf("Coins: [");
    for (int i = 0; i < n; ++i) {
        printf("%d(%d)", coins[i].value, coins[i].count);
        if (i != n - 1)
            printf(", ");
    }
    printf("]\n");
}

int coin_changing(int coins[], int coin_count, int target) {
    Coin min_coins[MAX_COINS_COUNT];
    int n = 0;

    for (int i = 0; i < coin_count; ++i) {
        if (coins[i] > target)
            continue;

        for (int j = 0; j < n; ++j) {
            if (coins[i] < min_coins[j].value) {
                min_coins[n] = (Coin){coins[i], 1};
                ++n;
                break;
            }
            if (coins[i] == min_coins[j].value) {
                min_coins[j].count += 1;
                break;
            }
        }

        if (n > 0 && coins[i] == min_coins[n - 1].value) {
            min_coins[n - 1].count += 1;
            --n;
        } else {
            ++n;
        }
    }

    int change = target;
    for (int i = 0; i < n; ++i) {
        change -= min_coins[i].value * min_coins[i].count;
        if (change < MIN_CHANGE)
            return -1;
    }

    if (change != 0)
        return -1;

    print_coins(min_coins, n);
    return n;
}

int main(void) {
    int coins[] = {1, 2, 3, 5};
    int coin_count = sizeof(coins) / sizeof(int);
    int target = 10;

    int result = coin_changing(coins, coin_count, target);

    if (result < 0)
        printf("Cannot make change for %d\n", target);

    return 0;
}