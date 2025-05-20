//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_COINS 1000

int main()
{
    int n, i, j, k, m, sum = 0;
    int dp[MAX_COINS + 1] = {0};
    int coins[MAX_COINS];
    int num_coins = 0;

    // Input the number of coins
    printf("Enter the number of coins: ");
    scanf("%d", &n);

    // Input the value of each coin
    for(i = 0; i < n; i++)
    {
        printf("Enter the value of coin %d: ", i+1);
        scanf("%d", &coins[i]);
    }

    // Initialize the dp array
    for(i = 0; i <= MAX_COINS; i++)
    {
        dp[i] = -1;
    }

    // Start with the smallest coin
    m = 0;
    for(i = 0; i <= MAX_COINS; i++)
    {
        if(dp[i] == -1)
        {
            dp[i] = 1;
            num_coins++;
        }
        else if(dp[i] == 1 && coins[m] > coins[i])
        {
            dp[i] = 1;
            num_coins++;
        }
    }

    // Greedy algorithm to find the minimum number of coins
    for(i = 1; i <= MAX_COINS; i++)
    {
        if(dp[i] == -1)
        {
            for(j = 0; j < num_coins; j++)
            {
                if(coins[j] <= i)
                {
                    dp[i] = dp[i-coins[j]] + 1;
                    break;
                }
            }
        }
    }

    // Print the number of coins required
    printf("Minimum number of coins required: %d\n", dp[MAX_COINS]);

    return 0;
}