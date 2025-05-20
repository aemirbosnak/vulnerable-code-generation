//Gemma-7B DATASET v1.0 Category: Sorting ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((*arr)[i] > (*arr)[j])
            {
                int temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
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
    }

    return 0;
}