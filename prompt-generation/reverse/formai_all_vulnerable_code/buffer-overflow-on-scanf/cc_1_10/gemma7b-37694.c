//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void Greedy_Algorithms(int **arr, int n)
{
    int i, j, max_sum = 0, current_sum = 0, current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] > current_sum && current_size < MAX)
            {
                current_sum = arr[i][j];
                current_size = j + 1;
            }
        }
    }

    printf("Maximum Sum: %d\n", current_sum);
    printf("Maximum Size: %d\n", current_size);
}

int main()
{
    int **arr = NULL;
    int n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the items' weights and values: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            scanf("%d %d", &arr[i][j], &arr[i][j + 1]);
        }
    }

    Greedy_Algorithms(arr, n);

    return 0;
}