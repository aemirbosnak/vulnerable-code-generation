//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_COIN_TYPES 10

// structure to hold coin type and number of coins
typedef struct {
    int coin_type;
    int num_coins;
} CoinType;

// function to compare two coin types based on their value
int compare(const void *a, const void *b) {
    CoinType *coin1 = (CoinType *)a;
    CoinType *coin2 = (CoinType *)b;

    if (coin1->coin_type > coin2->coin_type) {
        return 1;
    } else if (coin1->coin_type < coin2->coin_type) {
        return -1;
    } else {
        return 0;
    }
}

// function to find the minimum number of coins required to make a given amount
int min_coins(int amount, int *coin_types, int num_coin_types) {
    CoinType *coins = (CoinType *)malloc(num_coin_types * sizeof(CoinType));

    for (int i = 0; i < num_coin_types; i++) {
        coins[i].coin_type = coin_types[i];
        coins[i].num_coins = 0;
    }

    // sort the coin types in descending order of value
    qsort(coins, num_coin_types, sizeof(CoinType), compare);

    int min_coins = 0;
    int remaining_amount = amount;

    for (int i = 0; i < num_coin_types; i++) {
        while (remaining_amount >= coins[i].coin_type && coins[i].num_coins < MAX_N) {
            remaining_amount -= coins[i].coin_type;
            coins[i].num_coins++;
            min_coins++;
        }
    }

    free(coins);

    return min_coins;
}

int main() {
    int n, m;
    int coin_types[MAX_COIN_TYPES];
    int num_coin_types = 0;

    printf("Enter the number of coin types: ");
    scanf("%d", &n);

    printf("Enter the coin types (in ascending order of value): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coin_types[i]);
        num_coin_types++;
    }

    printf("Enter the amount to be paid: ");
    scanf("%d", &m);

    int min_coins_required = min_coins(m, coin_types, num_coin_types);

    printf("The minimum number of coins required to pay %d is %d.\n", m, min_coins_required);

    return 0;
}