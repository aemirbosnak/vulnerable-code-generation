//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void greedy_algorithm(int **arr, int n)
{
    int i, j, total = 0, current_size = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] && current_size < total)
            {
                current_size += arr[i][j];
                total++;
            }
        }
    }
    printf("Total number of items: %d\n", total);
    printf("Total weight: %d\n", current_size);
}

int main()
{
    int **arr = NULL;
    int n = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the item weights and values:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d %d", &arr[i][j], &arr[i][j + MAX]);
        }
    }

    greedy_algorithm(arr, n);

    return 0;
}