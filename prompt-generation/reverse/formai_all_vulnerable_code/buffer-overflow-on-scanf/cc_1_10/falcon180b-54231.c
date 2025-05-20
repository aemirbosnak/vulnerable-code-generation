//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_VALUE 100

int coins[MAX_COINS] = {1, 5, 10, 25, 50, 100};
int num_coins = MAX_COINS;

void print_coins() {
    printf("Coins: ");
    for (int i = 0; i < num_coins; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");
}

int main() {
    int target_value;

    printf("Enter the target value: ");
    scanf("%d", &target_value);

    if (target_value > MAX_VALUE) {
        printf("Target value is too high.\n");
        return 1;
    }

    int i = num_coins - 1;
    while (i >= 0 && coins[i] > target_value) {
        i--;
    }

    if (i == -1) {
        printf("No coins can make up the target value.\n");
        return 1;
    }

    int num_coins_used = 0;
    while (num_coins_used < num_coins) {
        if (coins[i] <= target_value) {
            target_value -= coins[i];
            num_coins_used++;
        } else {
            i--;
        }
    }

    printf("Minimum number of coins: %d\n", num_coins_used);
    print_coins();

    return 0;
}