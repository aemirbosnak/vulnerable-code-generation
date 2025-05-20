//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define COIN_COUNT 5
#define MAX_AMOUNT 100

typedef struct coin {
    int value;
    int count;
} coin_t;

coin_t coins[COIN_COUNT] = {
    {1, 0},
    {5, 0},
    {10, 0},
    {25, 0},
    {50, 0}
};

void print_coins(void) {
    int i;
    printf("Coins:\n");
    for (i = 0; i < COIN_COUNT; i++) {
        printf("%d cent(s) = %d\n", coins[i].value, coins[i].count);
    }
}

void coin_change(int amount) {
    int i = COIN_COUNT - 1;

    while (amount > 0 && i >= 0) {
        if (amount >= coins[i].value) {
            coins[i].count += amount / coins[i].value;
            amount %= coins[i].value;
        } else {
            i--;
        }
    }
}

int main() {
    int target, change;

    printf("Enter the target amount:\n");
    scanf("%d", &target);

    if (target > MAX_AMOUNT) {
        printf("Amount out of range.\n");
        return 1;
    }

    printf("Enter the coins denominations (in cents):\n");
    for (int i = 0; i < COIN_COUNT; i++) {
        scanf("%d", &coins[i].value);
    }

    printf("\nTarget amount: %d cents\n", target);

    coin_change(target);
    print_coins();

    printf("\nMinimum number of coins required:\n");
    change = 0;
    for (int i = 0; i < COIN_COUNT; i++) {
        change += coins[i].count;
        printf("%d coins of %d cents\n", coins[i].count, coins[i].value);
    }

    printf("= %d coins\n", change);

    return 0;
}