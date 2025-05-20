//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: medieval
#include <stdio.h>

#define MAX_COINS 10

int findMaxCoins(int coins[], int n)
{
    int maxCoins = 0;

    for (int i = 0; i < n; i++)
    {
        if (coins[i] > maxCoins)
        {
            maxCoins = coins[i];
        }
    }

    return maxCoins;
}

int main()
{
    int coins[MAX_COINS];
    int numCoins;

    printf("Welcome to the Greedy Algorithm for Coin Collection!\n");

    printf("How many coins are there?\n");
    scanf("%d", &numCoins);

    printf("Enter the value of each coin (separated by spaces):\n");

    for (int i = 0; i < numCoins; i++)
    {
        scanf("%d", &coins[i]);
    }

    int maxCoins = findMaxCoins(coins, numCoins);
    int totalCoins = 0;
    int coinCount = 0;

    printf("\nStarting coin collection...\n");

    while (totalCoins < maxCoins)
    {
        int currentMax = 0;
        int currentCoin = 0;

        for (int i = 0; i < numCoins; i++)
        {
            if (coins[i] > currentMax && coins[i] <= (maxCoins - totalCoins))
            {
                currentMax = coins[i];
                currentCoin = i;
            }
        }

        coinCount++;
        totalCoins += currentMax;
        coins[currentCoin] = 0;

        printf("Collected coin #%d with value %d. Total coins collected: %d\n",
               coinCount, currentMax, totalCoins);
    }

    printf("\nCoin collection complete! Total coins collected: %d\n", totalCoins);

    return 0;
}