//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_COINS 6
#define MAX_VALUE 1000

int coins[MAX_COINS] = {1, 5, 10, 25, 50, 100};
int nCoins;
int memo[MAX_VALUE + 1][MAX_COINS + 1];

int greedyAlgorithm(int value, int coinsLeft)
{
    if (value == 0)
        return 0;
    if (coinsLeft == 0)
        return INT_MAX;
    if (value < 0)
        return INT_MAX;
    if (memo[value][coinsLeft]!= -1)
        return memo[value][coinsLeft];
    int minCoins = INT_MAX;
    for (int i = 0; i < nCoins; i++)
    {
        int newValue = value - coins[i];
        int newCoinsLeft = coinsLeft - 1;
        int coinsUsed = 1 + greedyAlgorithm(newValue, newCoinsLeft);
        if (coinsUsed < minCoins)
            minCoins = coinsUsed;
    }
    memo[value][coinsLeft] = minCoins;
    return minCoins;
}

int main()
{
    printf("Enter the number of coins: ");
    scanf("%d", &nCoins);
    for (int i = 0; i < nCoins; i++)
    {
        printf("Enter the value of coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }
    int value;
    printf("Enter the value to change: ");
    scanf("%d", &value);
    int coinsUsed = greedyAlgorithm(value, nCoins);
    printf("The minimum number of coins used is: %d\n", coinsUsed);
    return 0;
}