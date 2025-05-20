//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

void printCoins(int *coins, int size, int amount) {
    int *result = (int *)malloc(size * sizeof(int));
    int count = 0;

    // Greedy algorithm to calculate the minimum number of coins
    for (int i = 0; i < size; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            result[count++] = coins[i];
        }
    }

    // Display results
    if (amount == 0) {
        printf("Minimum coins used: %d\n", count);
        printf("Coins used: ");
        for (int j = 0; j < count; j++) {
            printf("%d ", result[j]);
        }
        printf("\n");
    } else {
        printf("It's not possible to form the given amount with the provided coins.\n");
    }

    free(result);
}

int main() {
    printf("===================================\n");
    printf(" Welcome to the Coin Change Solver!\n");
    printf("===================================\n");

    int n;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int *coins = (int *)malloc(n * sizeof(int));
    printf("Enter the coin denominations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    int amount;
    printf("Enter the amount of change needed: ");
    scanf("%d", &amount);

    // Sort the coins in descending order for a better greedy approach
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                int temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    printf("\nCalculating the minimum number of coins...\n");
    printCoins(coins, n, amount);

    free(coins);
    printf("===================================\n");
    printf(" Thank you for using the Coin Change Solver!\n");
    printf("===================================\n");

    return 0;
}