//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 6
#define MAX_QUANTITY 10

int main() {
    int coins[MAX_COINS] = { 1, 5, 10, 25, 50, 100 };
    int quantity[MAX_QUANTITY] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000 };
    int nCoins = sizeof(coins) / sizeof(coins[0]);
    int nQuantities = sizeof(quantity) / sizeof(quantity[0]);
    int i, j, k;

    // Initialize the solution matrix
    int solution[nCoins][nQuantities];
    for (i = 0; i < nCoins; i++) {
        for (j = 0; j < nQuantities; j++) {
            solution[i][j] = 0;
        }
    }

    // Find the minimum number of coins required for each quantity
    for (i = 0; i < nQuantities; i++) {
        int minCoins = MAX_COINS;
        for (j = 0; j < nCoins; j++) {
            if (quantity[i] % coins[j] == 0) {
                int numCoins = quantity[i] / coins[j];
                if (numCoins < minCoins) {
                    minCoins = numCoins;
                }
            }
        }
        // Store the minimum number of coins in the solution matrix
        solution[0][i] = minCoins;
    }

    // Fill the rest of the solution matrix using dynamic programming
    for (i = 1; i < nCoins; i++) {
        for (j = 0; j < nQuantities; j++) {
            int k = i - 1;
            solution[i][j] = solution[i][j - coins[k]] + 1;
        }
    }

    // Print the solution matrix
    printf("Quantity\t");
    for (i = 0; i < nCoins; i++) {
        printf("%d\t", coins[i]);
    }
    printf("\n");
    for (i = 0; i < nQuantities; i++) {
        printf("%d\t", quantity[i]);
        for (j = 0; j < nCoins; j++) {
            printf("%d\t", solution[j][i]);
        }
        printf("\n");
    }

    return 0;
}