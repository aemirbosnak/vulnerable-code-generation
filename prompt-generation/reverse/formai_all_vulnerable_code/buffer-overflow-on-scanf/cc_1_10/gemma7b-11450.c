//Gemma-7B DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int n)
{
    if (n <= 1)
    {
        return;
    }
    int i = 0, j = 0, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*arr[i] > *arr[j])
            {
                int temp = *arr[i];
                *arr[i] = *arr[j];
                *arr[j] = temp;
                count++;
            }
        }
    }
    printf("Number of swaps: %d\n", count);
    sort(arr, n - 1);
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    sort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}