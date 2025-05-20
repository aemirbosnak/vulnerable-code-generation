//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_COINS 10

// define the array that holds the coin denominations
int coins[MAX_COINS] = {1, 5, 10, 25};
int coin_count[MAX_COINS] = {0};
int total_coins = 0;
int total_amount = 0;

void compute_min_coin_count(int amount, int index)
{
    // base case - if the amount is zero or we have no more coins to consider
    if (amount == 0 || index == -1)
        return;

    // compute the maximum number of coins we can get for the current type of coin
    int max_count = amount / coins[index];

    // consider all possible coin counts for the current denomination
    for (int count = max_count; count >= 0; count--)
    {
        // compute the remaining amount
        int remaining_amount = amount - (count * coins[index]);

        // if we have found a solution, update the total count of coins
        if (remaining_amount == 0)
        {
            coin_count[index] = count;
            total_coins = total_coins + count;
            total_amount = total_amount + (count * coins[index]);
            break;
        }
        else if (remaining_amount < 0)
        {
            // if the remaining amount is negative, try with lower coin count
            continue;
        }
        else
        {
            // otherwise, try with lower coin denominations
            coin_count[index] = count;
            total_coins = total_coins + count;
            total_amount = total_amount + (count * coins[index]);

            compute_min_coin_count(remaining_amount, index - 1);

            // rollback the count
            coin_count[index] = 0;
            total_coins = total_coins - count;
            total_amount = total_amount - (count * coins[index]);
        }
    }
}

int main()
{
    int amount;

    printf("Enter the amount:\n");
    scanf("%d", &amount);

    compute_min_coin_count(amount, 3);

    printf("Total number of coins: %d\n", total_coins);
    printf("Total amount: %d\n", total_amount);

    for (int i = 0; i < 4; i++)
    {
        printf("%d cents: %d\n", coins[i], coin_count[i]);
    }

    return 0;
}