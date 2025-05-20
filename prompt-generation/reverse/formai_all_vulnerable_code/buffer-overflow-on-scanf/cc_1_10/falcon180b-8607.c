//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COINS 6
#define MAX_VALUES 20
#define MAX_COIN_VALUE 100
#define MAX_VALUE 1000

// Function to find the minimum number of coins required to form a given value
int findMinCoins(int values[], int n, int coins[]) {
    int i, j, minCoins = 0;

    // Initialize the coins array with 0s
    for (i = 0; i <= MAX_COIN_VALUE; i++) {
        coins[i] = 0;
    }

    // Initialize the minimum number of coins required to form a given value
    for (i = 0; i <= MAX_VALUE; i++) {
        minCoins += i;
    }

    // Iterate through the values array and update the coins array
    for (i = 0; i < n; i++) {
        for (j = values[i]; j <= MAX_VALUE; j++) {
            if (j - values[i] > 0) {
                coins[j] += coins[j - values[i]];
            }
        }
    }

    // Return the minimum number of coins required to form a given value
    return minCoins;
}

int main() {
    int values[MAX_VALUES], coins[MAX_COIN_VALUE + 1], n, i, j, minCoins;

    // Input the number of values
    printf("Enter the number of values: ");
    scanf("%d", &n);

    // Input the values
    printf("Enter the values:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Find the minimum number of coins required to form the given values
    minCoins = findMinCoins(values, n, coins);

    // Output the minimum number of coins required to form the given values
    printf("The minimum number of coins required to form the given values is: %d\n", minCoins);

    return 0;
}