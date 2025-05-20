//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: mathematical
#include <stdio.h>

// Function to print the optimal solution
void printSolution(int coins[], int n, int amount)
{
    int i, j, count, total_count = 0, usedCoins[n];

    // Traverse through all coins
    for (i = n - 1; i >= 0; i--) {
        count = 0;
        // Find the maximum number of current coin that can be used
        while (amount >= coins[i]) {
            usedCoins[count++] = coins[i];
            amount -= coins[i];
        }
        // Update total count and print the used denomination(s)
        printf("%d coins of denomination %d\n", count, coins[i]);
        total_count += count;
    }
    // Print the optimal solution
    printf("Minimum number of coins required: %d\n", total_count);
}

// Function that implements the Greedy Algorithm
void coinChange(int coins[], int n, int amount)
{
    // Sort the coins by descending order of their denominations
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (coins[i] < coins[j]) {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }

    printSolution(coins, n, amount);
}

// Driver code
int main()
{
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000 };
    int n = sizeof(coins) / sizeof(coins[0]);

    int amount = 4321;

    printf("Coins available: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\nAmount to be changed: %d\n", amount);

    // Call the coinChange function
    coinChange(coins, n, amount);

    return 0;
}