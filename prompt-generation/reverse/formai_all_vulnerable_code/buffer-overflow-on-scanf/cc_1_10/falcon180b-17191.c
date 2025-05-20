//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_VALUES 100

// Function to find the minimum number of coins required to make a given amount
int findMinimumCoins(int values[], int n, int coins[], int numCoins) {
    int i, j, minCoins = MAX_VALUES;
    for (i = 0; i < numCoins; i++) {
        for (j = 0; j < n; j++) {
            if (values[j] == coins[i]) {
                return 1;
            }
        }
    }
    for (i = 0; i < numCoins; i++) {
        for (j = 0; j < n; j++) {
            if (values[j] > coins[i]) {
                continue;
            }
            int k;
            for (k = i + 1; k < numCoins; k++) {
                if (values[j] - coins[i] == coins[k]) {
                    return 1 + findMinimumCoins(values, n - 1, coins, numCoins - 1);
                }
            }
        }
    }
    return minCoins;
}

int main() {
    int values[MAX_VALUES], coins[MAX_COINS], numCoins, n;
    printf("Enter the number of values: ");
    scanf("%d", &n);
    printf("Enter the values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }
    printf("Enter the number of coins: ");
    scanf("%d", &numCoins);
    printf("Enter the coins: ");
    for (int i = 0; i < numCoins; i++) {
        scanf("%d", &coins[i]);
    }
    int minCoins = findMinimumCoins(values, n, coins, numCoins);
    if (minCoins == MAX_VALUES) {
        printf("No solution exists.\n");
    } else {
        printf("Minimum number of coins required: %d\n", minCoins);
    }
    return 0;
}