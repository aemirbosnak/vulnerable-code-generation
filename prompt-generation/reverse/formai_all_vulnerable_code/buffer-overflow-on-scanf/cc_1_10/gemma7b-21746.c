//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, my_coins = 0, total_coins = 0, round_num = 0;

    // Initializing the game parameters
    printf("Enter the number of players: ");
    scanf("%d", &n);

    // Allocating memory for the coins
    int *coins = (int *)malloc(n * sizeof(int));

    // Distribute coins among the players
    printf("Enter the number of coins each player has: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
        my_coins += coins[i];
    }

    // Calculating the total number of coins
    total_coins = my_coins;

    // Commencing the rounds
    while (total_coins > 0)
    {
        round_num++;

        // Determining the round winner
        int winner = -1;
        for (i = 0; i < n; i++)
        {
            if (coins[i] > coins[winner])
            {
                winner = i;
            }
        }

        // Collecting the winnings
        coins[winner] += coins[winner] / 2;
        total_coins -= coins[winner] / 2;

        // Printing the round results
        printf("Round %d: ", round_num);
        for (i = 0; i < n; i++)
        {
            printf("%d ", coins[i]);
        }
        printf("\n");
    }

    // Finalizing the game
    printf("Game Over! The final score is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", coins[i]);
    }

    return 0;
}