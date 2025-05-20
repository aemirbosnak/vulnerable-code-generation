//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_COINS 100
#define MAX_VALUES 100

int main() {
    int n, i, j;
    int coins[MAX_COINS], values[MAX_VALUES];
    int max_val, min_coins;

    srand(time(NULL));

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    printf("Enter the values of coins:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    printf("Enter the values of items:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    max_val = values[0];
    min_coins = INT_MAX;

    for (i = 0; i < n; i++) {
        int coins_used = 0;
        int j = 0;
        while (coins_used < values[i]) {
            if (coins_used + coins[j] <= values[i]) {
                coins_used += coins[j];
            } else {
                j++;
            }
        }
        if (min_coins > coins_used) {
            min_coins = coins_used;
        }
    }

    printf("The minimum number of coins required is: %d\n", min_coins);

    return 0;
}