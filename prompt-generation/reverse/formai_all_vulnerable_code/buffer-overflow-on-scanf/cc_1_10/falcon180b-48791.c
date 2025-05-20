//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_COINS 100
#define MAX_VALUE 1000000

int main() {
    int num_coins[MAX_NUM_COINS];
    int num_coins_used = 0;
    int num_values[MAX_NUM_COINS];
    int num_values_used = 0;
    int num_coins_total = 0;
    int num_values_total = 0;

    printf("Enter the number of coin denominations:\n");
    scanf("%d", &num_coins_total);

    printf("Enter the coin denominations:\n");
    for (int i = 0; i < num_coins_total; i++) {
        scanf("%d", &num_coins[i]);
        num_values[i] = num_coins[i];
        num_coins_used += num_coins[i];
        num_values_used += num_coins[i];
    }

    printf("Enter the total value to be represented:\n");
    scanf("%d", &num_values_total);

    int num_coins_left = num_coins_total - 1;
    int num_values_left = num_values_total;

    while (num_coins_left >= 0 && num_values_left > 0) {
        int min_coin_value = MAX_VALUE;
        int min_coin_index = -1;
        for (int i = num_coins_left; i >= 0; i--) {
            if (num_coins[i] <= num_values_left && num_values[i] < min_coin_value) {
                min_coin_value = num_values[i];
                min_coin_index = i;
            }
        }
        if (min_coin_index == -1) {
            printf("No valid coin denominations left.\n");
            exit(1);
        }
        num_coins_left--;
        num_values_left -= min_coin_value;
        num_coins_used -= num_coins[min_coin_index];
        num_values_used -= min_coin_value;
    }

    printf("Number of coins used: %d\n", num_coins_used);
    printf("Number of coin denominations used: %d\n", num_coins_total - num_coins_left);
    printf("Total value represented: %d\n", num_values_total);

    return 0;
}