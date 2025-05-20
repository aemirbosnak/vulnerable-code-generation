//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_COINS 100

struct coin {
    int value;
    int index;
};

int main() {
    int num_coins;
    int total_value;
    struct coin coins[MAX_NUM_COINS];
    int num_coins_used;
    int i;

    printf("Enter the number of coins: ");
    scanf("%d", &num_coins);

    printf("Enter the values of the coins: ");
    for (i = 0; i < num_coins; i++) {
        coins[i].value = 0;
        scanf("%d", &coins[i].value);
    }

    printf("Enter the total value to be made: ");
    scanf("%d", &total_value);

    num_coins_used = 0;
    for (i = num_coins - 1; i >= 0; i--) {
        if (coins[i].value <= total_value) {
            total_value -= coins[i].value;
            coins[i].index = num_coins_used;
            num_coins_used++;
        }
    }

    if (total_value == 0) {
        printf("The total value can be made using the given coins.\n");
        for (i = 0; i < num_coins_used; i++) {
            printf("Coin %d with value %d was used.\n", coins[i].index, coins[i].value);
        }
    } else {
        printf("The total value cannot be made using the given coins.\n");
    }

    return 0;
}