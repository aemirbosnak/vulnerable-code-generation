//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_AMOUNT 10000
#define NUM_COINS 5

typedef struct {
    int value;
    int count;
} Coin;

void print_coins(Coin coins[], int num_coins, int amount) {
    int i;
    printf("Coins used to make %d:\n", amount);
    for (i = 0; i < num_coins; i++) {
        if (coins[i].count > 0) {
            printf("%d coin(s) of value %d\n", coins[i].count, coins[i].value);
            amount -= coins[i].value * coins[i].count;
        }
    }
    if (amount != 0) {
        printf("Unable to make %d using given coins.\n", amount);
    }
}

void greedy_coin_change(int amount) {
    Coin coins[NUM_COINS] = {{1, 0}, {5, 0}, {10, 0}, {25, 0}, {50, 0}};
    int i, num_coins = 0;

    for (i = NUM_COINS - 1; i >= 0 && amount > 0; i--) {
        if (amount >= coins[i].value) {
            coins[i].count++;
            amount -= coins[i].value;
            num_coins++;
        }
    }

    print_coins(coins, NUM_COINS, amount);
}

int main() {
    int amount;

    printf("Enter the amount to be made:\n");
    scanf("%d", &amount);

    if (amount > MAX_AMOUNT) {
        printf("Amount too large. Maximum amount is %d.\n", MAX_AMOUNT);
        return 1;
    }

    greedy_coin_change(amount);

    return 0;
}