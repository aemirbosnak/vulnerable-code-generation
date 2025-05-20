//Gemma-7B DATASET v1.0 Category: Sorting ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void sort(int **arr, int n)
{
    int i, j, key, tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((*arr[i]) > (*arr[j]))
            {
                key = *arr[i];
                *arr[i] = *arr[j];
                *arr[j] = key;
            }
        }
    }
}

int main()
{
    int n, i;
    int **arr;

    printf("Enter the number of elements:");
    scanf("%d", &n);

    arr = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", (arr[i]));
    }

    sort(arr, n);

    printf("Sorted elements:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}