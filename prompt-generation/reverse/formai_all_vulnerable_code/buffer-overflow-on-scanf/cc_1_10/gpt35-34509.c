//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: peaceful
/*
   Title: Greedy Algorithm Example - Coin Change Problem
   Description: This program makes use of a greedy approach to solve the coin change problem, where given a set of coins and a total value, the task is to find the minimum number of coins required to make that amount of change.

   Approach:
   1) Sort the array of coins in descending order
   2) Iterate through the coins array and subtract as many coins as possible from the total value
   3) Continue until the total value becomes 0

*/

#include <stdio.h>

// Function to sort the coins array in descending order
void sortCoins(int coins[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (coins[i] < coins[j])
            {
                temp = coins[i];
                coins[i] = coins[j];
                coins[j] = temp;
            }
        }
    }
}

int main()
{
    int totalValue, numCoins, i;
    int coins[10] = { 50, 25, 10, 5, 1 };
    int coinCount[10] = { 0 };

    printf("\nEnter the total value (in cents): ");
    scanf("%d", &totalValue);

    // Sort the coins array in descending order
    sortCoins(coins, 5);

    // Iterate through the coins array and subtract as many coins as possible from the total value
    for (i = 0; i < 5; i++)
    {
        if (totalValue == 0)
            break;

        if (totalValue >= coins[i])
        {
            numCoins = totalValue / coins[i];
            coinCount[i] = numCoins;
            totalValue = totalValue - (numCoins * coins[i]);
        }
    }

    printf("\nThe minimum number of coins required to make the change is: ");
    for (i = 0; i < 5; i++)
    {
        if (coinCount[i] != 0)
            printf("\n%d cents: %d", coins[i], coinCount[i]);
    }

    printf("\n");

    return 0;
}