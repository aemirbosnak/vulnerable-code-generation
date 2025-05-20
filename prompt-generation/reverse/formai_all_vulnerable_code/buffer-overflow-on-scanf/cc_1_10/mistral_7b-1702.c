//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_AMOUNT 100000
#define COINS_NUM 6

typedef struct {
    int value;
    int count;
} Coin;

void initCoinArray(Coin *coins, int amount) {
    for (int i = 0; i < COINS_NUM; ++i) {
        coins[i].value = i + 1;
        coins[i].count = 0;
    }
}

void makeChange(Coin *coins, int amount) {
    for (int i = COINS_NUM - 1; i >= 0 && amount > 0; --i) {
        int numCoins = amount / coins[i].value;
        if (numCoins > 0) {
            coins[i].count += numCoins;
            amount -= numCoins * coins[i].value;
        }
    }
}

void printChange(Coin *coins) {
    for (int i = 0; i < COINS_NUM; ++i) {
        if (coins[i].count > 0) {
            printf("%d coin(s) of denomination %d\n", coins[i].count, coins[i].value);
        }
    }
}

int main() {
    Coin coins[COINS_NUM];
    int m;

    printf("Enter the total amount of money: ");
    scanf("%d", &m);

    if (m > MAX_AMOUNT) {
        printf("Amount too large! Maximum amount is %d.\n", MAX_AMOUNT);
        return 1;
    }

    initCoinArray(coins, m);

    printf("Making change for %d:\n", m);
    makeChange(coins, m);
    printChange(coins);

    return 0;
}

/* Bonus: For an added challenge, try to implement the change-making problem with infinite supply of coins. */