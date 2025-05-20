//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#define MAX_AMOUNT 10000
#define COIN_COUNT 5

typedef struct {
    int value;
    int count;
} Coin;

Coin coins[COIN_COUNT] = {
    {1, 0},
    {5, 0},
    {10, 0},
    {25, 0},
    {50, 0}
};

void print_coins(Coin coins[]) {
    for (int i = 0; i < COIN_COUNT; i++) {
        printf("%d coin(s) of value %d\n", coins[i].count, coins[i].value);
    }
}

void coin_change(int amount) {
    int remaining = amount;

    for (int i = COIN_COUNT - 1; i >= 0; i--) {
        while (remaining >= coins[i].value) {
            coins[i].count++;
            remaining -= coins[i].value;
        }
    }
}

int main() {
    int target;
    printf("Enter the amount:\n");
    scanf("%d", &target);

    if (target > MAX_AMOUNT) {
        printf("Amount exceeds the limit.\n");
        return 1;
    }

    coin_change(target);
    printf("The minimum number of coins required to make %d cents are:\n", target);
    print_coins(coins);

    return 0;
}