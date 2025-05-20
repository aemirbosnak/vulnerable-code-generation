//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 10
#define INF 1000000

// Function to find minimum number of coins to make change
int minCoins(int makeChange, int coins[], int n) {
    int table[n + 1];

    // Base case
    for (int i = 0; i <= makeChange; i++) {
        table[i] = i;
    }

    // Coins array is empty
    if (n == 0) {
        return makeChange;
    }

    // Initialize first row with infinite values
    for (int j = 1; j <= makeChange; j++) {
        table[j] = INF;
    }

    // Fill the rest of the table using the minimum number of coins
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= makeChange; j++) {
            if (j >= coins[i - 1]) {
                table[j] = min(table[j], table[j - coins[i - 1]] + 1);
            }
        }
    }

    return table[makeChange];
}

// Utility function to find the minimum of two integers
int min(int x, int y) {
    return (x < y) ? x : y;
}

// Driver code to test above functions
int main() {
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);
    int makeChange = 31;

    printf("Minimum number of coins to make change %d is %d\n", makeChange, minCoins(makeChange, coins, n));

    return 0;
}