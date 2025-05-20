//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include<stdio.h>

/* Function to sort an array in ascending order */
void ascendingSort(int arr[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

/* Function to find the minimum coins needed */
void findMinimumCoins(int coins[], int n, int amount)
{
    int i, j, count = 0;
    int change[n];

    for (i = 0; i < n; i++)
    {
        change[i] = 0; // Initializing all elements with 0
    }

    /* Sorting the coins in descending order */
    ascendingSort(coins, n);

    /* Counting the minimum coins needed to make change */
    for (i = 0; i < n; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            change[i]++;
            count++;
        }
    }

    /* Printing the minimum coins and the denominations used */
    printf("Minimum coins required to make change: %d\n", count);
    printf("Denominations used:\n");
    for (i = 0; i < n; i++)
    {
        if (change[i] != 0)
        {
            printf("%d coin(s) of denomination %d\n", change[i], coins[i]);
        }
    }
}

/* Main function */
int main()
{
    int n, amount, i;

    /* Reading the number of denominations */
    printf("Enter the number of denominations: ");
    scanf("%d", &n);

    int coins[n];

    /* Reading the denominations */
    printf("Enter the denominations: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    /* Reading the amount for which change is needed */
    printf("Enter the amount for which change is needed: ");
    scanf("%d", &amount);

    /* Finding the minimum coins needed for change */
    findMinimumCoins(coins, n, amount);

    return 0;
}