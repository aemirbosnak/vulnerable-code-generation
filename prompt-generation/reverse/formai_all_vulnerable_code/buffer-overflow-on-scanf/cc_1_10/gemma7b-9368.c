//Gemma-7B DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void sort(int **arr, int n)
{
    int i, j, k, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if ((*arr)[i] > (*arr)[j])
            {
                temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i, *arr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(&arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}