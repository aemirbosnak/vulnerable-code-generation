//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_COINS 6

typedef struct {
    int value;
    int index;
} Coin;

Coin coins[] = {
    {1, 0},
    {5, 1},
    {10, 2},
    {25, 3},
    {50, 4},
    {100, 5}
};

int make_change(int amount, int index, int *coins_used, int coins_used_size) {
    if (amount == 0) {
        return 1;
    }
    if (index >= MAX_COINS) {
        return 0;
    }
    int i;
    for (i = index; i < MAX_COINS; i++) {
        if (amount >= coins[i].value) {
            coins_used[coins_used_size] = coins[i].value;
            if (make_change(amount - coins[i].value, i + 1, coins_used, coins_used_size + 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int amount;
    printf("Enter amount: ");
    scanf("%d", &amount);
    int coins_used[MAX_COINS];
    int coins_used_size = 0;
    if (make_change(amount, 0, coins_used, coins_used_size)) {
        printf("Coins used: ");
        for (int i = 0; i < coins_used_size; i++) {
            printf("%d ", coins_used[i]);
        }
        printf("\n");
    } else {
        printf("Cannot make change\n");
    }
    return 0;
}