//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, k, total = 0, min_diff = MAX;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            k = 0;
            while (k < MAX)
            {
                if (arr[i][k] + arr[j][k] < min_diff)
                {
                    min_diff = arr[i][k] + arr[j][k];
                }
                k++;
            }
        }
    }

    printf("The minimum difference is: %d", min_diff);
}

int main()
{
    int n, i, j;
    int **arr;

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

    greedy_algorithm(arr, n);

    return 0;
}