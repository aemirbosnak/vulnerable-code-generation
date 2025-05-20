//Gemma-7B DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int n)
{
    int i, j, k, min, temp;

    if (n <= 1)
    {
        return;
    }

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    sort(arr, n - 1);
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
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    sort(arr, n);

    printf("Sorted array:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}