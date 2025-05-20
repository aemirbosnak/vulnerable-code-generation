//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: grateful
#include <stdio.h>

void coinChange(int amount, int coins[], int no_of_coins)
{
    int coinUsed[20], coinCount = 0;
    for (int i = 0; i < no_of_coins; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            coinUsed[coinCount++] = coins[i];
        }
    }
    printf("\nSelected coins are: ");
    for (int i = 0; i < coinCount; i++)
    {
        printf("%d ", coinUsed[i]);
    }
    printf("\n");
}

int main()
{
    int amount, no_of_coins, coins[20];
    printf("\nEnter the amount: ");
    scanf("%d", &amount);

    printf("\nEnter the number of coins: ");
    scanf("%d", &no_of_coins);

    printf("\nEnter the value of each coin: ");
    for (int i = 0; i < no_of_coins; i++)
    {
        scanf("%d", &coins[i]);
    }
    // Sorting coins in descending order using Bubble Sort
    for (int i = 0; i < no_of_coins - 1; i++)
    {
        for (int j = 0; j < no_of_coins - i - 1; j++)
        {
            if (coins[j] < coins[j + 1])
            {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }
    coinChange(amount, coins, no_of_coins);
    return 0;
}