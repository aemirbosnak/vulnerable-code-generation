//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algo(int **arr, int n)
{
    int i, j, k, max_sum = 0, current_sum = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (arr[i][j] + arr[j][k] + arr[k][i] > max_sum)
                {
                    max_sum = arr[i][j] + arr[j][k] + arr[k][i];
                }
            }
        }
    }

    printf("The maximum sum is: %d\n", max_sum);
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algo(arr, n);

    return 0;
}