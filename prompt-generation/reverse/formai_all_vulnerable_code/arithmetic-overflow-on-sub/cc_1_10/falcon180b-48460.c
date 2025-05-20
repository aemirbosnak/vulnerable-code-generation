//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COINS 1000000

int main() {
    int n;
    int *coins = (int *) malloc(sizeof(int) * MAX_COINS);
    int num_coins = 1;

    printf("Enter the number of coins: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount of change: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid amount of change.\n");
        exit(1);
    }

    int *change = (int *) malloc(sizeof(int) * n);
    int change_index = 0;

    for (int i = num_coins - 1; i >= 0; i--) {
        while (n >= coins[i]) {
            n -= coins[i];
            change[change_index++] = coins[i];
        }
    }

    printf("Minimum number of coins required: %d\n", num_coins);
    printf("Coins used: ");

    for (int i = 0; i < num_coins; i++) {
        printf("%d ", coins[i]);
    }

    printf("\n");

    free(coins);
    free(change);

    return 0;
}