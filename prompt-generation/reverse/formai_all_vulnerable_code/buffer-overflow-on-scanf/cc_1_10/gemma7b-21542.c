//Gemma-7B DATASET v1.0 Category: Sorting ; Style: excited
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortByHeight(int **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((*arr[i]) > (*arr[j]))
            {
                swap(&(*arr[i]), &(*arr[j]));
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", (*arr[i]));
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(sizeof(int));
    }

    printf("Enter the elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    sortByHeight(arr, n);

    return 0;
}