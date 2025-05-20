//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algorithm(int **arr, int n)
{
    int i, j, k, total = 0, current_size = 0, maximum_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] > current_size)
            {
                current_size = arr[i][j];
                maximum_size = current_size;
            }
        }
    }

    total = maximum_size * n;

    printf("Total cost: %d", total);
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the item sizes: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}