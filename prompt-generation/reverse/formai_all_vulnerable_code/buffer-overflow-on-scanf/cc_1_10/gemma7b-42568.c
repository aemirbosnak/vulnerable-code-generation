//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main()
{
    int n, i, j, k, greed;
    int coins[MAX_SIZE];
    int bag[MAX_SIZE];

    printf("Enter the number of players: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number of coins you have: ");
        scanf("%d", &coins[i]);
    }

    printf("Enter the total number of coins: ");
    scanf("%d", &k);

    for (i = 0; i < n; i++)
    {
        bag[i] = 0;
    }

    for (i = 0; i < k; i++)
    {
        greed = 0;
        for (j = 0; j < n; j++)
        {
            if (coins[j] > greed)
            {
                greed = coins[j];
            }
        }

        for (j = 0; j < n; j++)
        {
            if (coins[j] == greed)
            {
                bag[j] = 1;
            }
        }

        k -= greed;
    }

    for (i = 0; i < n; i++)
    {
        if (bag[i] == 1)
        {
            printf("You have won the game! You have collected %d coins.\n", coins[i]);
        }
        else
        {
            printf("You have lost the game. You have collected %d coins.\n", coins[i]);
        }
    }

    return 0;
}