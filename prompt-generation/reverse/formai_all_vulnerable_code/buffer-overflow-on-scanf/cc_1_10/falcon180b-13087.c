//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int value;
    int index;
} Coin;

void initialize(Coin coins[], int numCoins) {
    for (int i = 0; i < numCoins; i++) {
        coins[i].value = i + 1;
        coins[i].index = i;
    }
}

void printCoins(Coin coins[], int numCoins) {
    for (int i = 0; i < numCoins; i++) {
        printf("%d ", coins[i].value);
    }
    printf("\n");
}

int main() {
    int numCoins;
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);

    Coin coins[MAX_SIZE];
    initialize(coins, numCoins);

    int target = 0;
    while (target <= 0) {
        printf("Enter the target value: ");
        scanf("%d", &target);
    }

    int result = makeChange(coins, numCoins, target);

    if (result == 0) {
        printf("No solution found.\n");
    } else {
        printf("Minimum number of coins required: %d\n", result);
    }

    return 0;
}

int makeChange(Coin coins[], int numCoins, int target) {
    int memo[MAX_SIZE][MAX_SIZE] = {0}; // Initialize memoization table

    for (int i = 0; i < numCoins; i++) {
        if (coins[i].value <= target) {
            memo[i][0] = 1;
        }
    }

    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < numCoins; j++) {
            if (coins[j].value <= i) {
                memo[j][i] = memo[j][i-1] + memo[j+1][i-coins[j].value];
            }
        }
    }

    return memo[0][target];
}