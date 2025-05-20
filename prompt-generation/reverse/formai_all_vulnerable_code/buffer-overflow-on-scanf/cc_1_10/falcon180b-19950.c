//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NUM_COINS 100
#define MAX_COIN_VALUE 500

int main() {
    int num_coins[MAX_NUM_COINS];
    int num_coins_used = 0;
    int coin_values[MAX_NUM_COINS];
    int num_coins_values = 0;
    int target = 0;

    // Input the number of coins
    printf("Enter the number of coins: ");
    scanf("%d", &num_coins_values);

    // Input the values of the coins
    printf("Enter the values of the coins:\n");
    for (int i = 0; i < num_coins_values; i++) {
        scanf("%d", &coin_values[i]);
    }

    // Sort the coins in descending order
    for (int i = 0; i < num_coins_values - 1; i++) {
        for (int j = i + 1; j < num_coins_values; j++) {
            if (coin_values[i] < coin_values[j]) {
                int temp = coin_values[i];
                coin_values[i] = coin_values[j];
                coin_values[j] = temp;
            }
        }
    }

    // Get the target value
    printf("Enter the target value: ");
    scanf("%d", &target);

    // Use a greedy algorithm to find the minimum number of coins to reach the target
    for (int i = num_coins_values - 1; i >= 0; i--) {
        if (coin_values[i] <= target) {
            num_coins[num_coins_used++] = i;
            target -= coin_values[i];
        }
    }

    // Print the result
    printf("Minimum number of coins used: %d\n", num_coins_used);
    printf("Coins used: ");
    for (int i = 0; i < num_coins_used; i++) {
        printf("%d ", num_coins[i]);
    }
    printf("\n");

    return 0;
}