//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_COIN_TYPES 10
#define MAX_COINS 100
#define MAX_CHANGE 1000

int coin_count(int m, int coins[], int n) {
    int count = 0;
    int i = 0;
    int coin;

    for (m; m > 0; m -= coin) {
        for (i = 0; i < n; i++) {
            if (coins[i] <= m) {
                coin = coins[i];
                count += m / coin;
                m = m % coin;
                break;
            }
        }
    }

    return count;
}

int main() {
    int change;
    int coins[MAX_COINS];

    printf("Enter the amount of change: ");
    scanf("%d", &change);

    printf("Enter up to %d types of coins, enter 0 when done: \n", MAX_COIN_TYPES);

    int i = 0;
    int coin;

    while (i < MAX_COIN_TYPES) {
        printf("Type %d: ", i + 1);
        scanf("%d", &coin);

        if (coin == 0) break;

        coins[i++] = coin;
    }

    int count = coin_count(change, coins, i);
    printf("Minimum number of coins to make change is %d.\n", count);

    return 0;
}