//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_AMOUNT 10000
#define NUM_COINS 5

typedef struct {
    int denomination;
    int count;
} Coin;

void print_coins(Coin coins[], int num_coins) {
    int i;
    for (i = 0; i < num_coins; i++) {
        printf("%d coin(s) of denomination %d\n", coins[i].count, coins[i].denomination);
    }
}

int main() {
    int amount;
    Coin coins[NUM_COINS];

    printf("Enter the amount:\n");
    scanf("%d", &amount);

    if (amount > MAX_AMOUNT) {
        printf("Amount too large!\n");
        return -1;
    }

    int i, remaining;
    for (i = 0; i < NUM_COINS; i++) {
        coins[i].denomination = (i + 1) * 5;
        coins[i].count = 0;
    }

    i = 0;
    while (amount > 0) {
        if (amount >= coins[i].denomination) {
            coins[i].count += amount / coins[i].denomination;
            amount %= coins[i].denomination;
        } else {
            i++;
        }
    }

    print_coins(coins, NUM_COINS);

    return 0;
}