//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int n, i, j, k, greedy_algorithm(int **arr, int n);
    int **arr = NULL;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the item weights and values: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    k = greedy_algorithm(arr, n);

    printf("The maximum profit is: %d", k);

    free(arr);

    return 0;
}

int greedy_algorithm(int **arr, int n)
{
    int i, j, total_weight = 0, total_profit = 0, current_profit = 0;
    int **ratio = NULL;

    ratio = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        ratio[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            ratio[i][j] = arr[i][j] / arr[i][0];
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (total_weight + arr[i][0] <= total_weight)
            {
                current_profit = ratio[i][j] * arr[i][0];
                if (current_profit > total_profit)
                {
                    total_profit = current_profit;
                    total_weight += arr[i][0];
                }
            }
        }
    }

    free(ratio);

    return total_profit;
}