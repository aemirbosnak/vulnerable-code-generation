//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void greedy_algo(int **arr, int n)
{
    int i, j, max_sum = 0, current_sum = 0, current_size = 0;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            if (arr[i][j] > current_sum)
            {
                current_sum = arr[i][j];
                current_size = j;
            }
        }
    }

    printf("Maximum sum: %d\n", current_sum);
    printf("Size of the subarray: %d\n", current_size);
}

int main()
{
    int n, i, j, **arr;

    printf("Enter the number of test cases: ");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter the elements of the array: ");
        for (j = 0; j < MAX; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    greedy_algo(arr, n);

    return 0;
}