//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define COIN_TYPES 4
#define MAX_AMOUNT 100

// Coin structures
typedef struct coin {
    int value;
    int count;
} coin_t;

// Function prototypes
void print_coins(coin_t coins[COIN_TYPES]);
int get_coins(coin_t coins[COIN_TYPES], int amount);

int main(void) {
    int amount;
    coin_t coins[COIN_TYPES] = {{1, 0}, {5, 0}, {10, 0}, {25, 0}};

    printf("Enter the amount of change: ");
    scanf("%d", &amount);

    if (amount > MAX_AMOUNT) {
        printf("Amount too large, please enter a value below %d.\n", MAX_AMOUNT);
        return 1;
    }

    get_coins(coins, amount);
    print_coins(coins);

    return 0;
}

// Function to print the coins and their counts
void print_coins(coin_t coins[COIN_TYPES]) {
    printf("\nMinimum coins to make change of %d cents:\n", coins[0].value * coins[0].count +
           coins[1].value * coins[1].count +
           coins[2].value * coins[2].count +
           coins[3].value * coins[3].count);

    for (int i = 0; i < COIN_TYPES; i++) {
        if (coins[i].count > 0)
            printf("%d cent coins: %d\n", coins[i].value, coins[i].count);
    }
}

// Function to calculate the minimum number of coins for a given amount
int get_coins(coin_t coins[COIN_TYPES], int amount) {
    int remaining_amount = amount;

    for (int i = COIN_TYPES - 1; i >= 0; i--) {
        while (remaining_amount >= coins[i].value) {
            coins[i].count++;
            remaining_amount -= coins[i].value;
        }
    }
}