//Gemma-7B DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void sort(int **arr, int n, int i)
{
    int j, k, minIndex, temp;

    if (i >= n - 1)
    {
        return;
    }

    for (j = i + 1; j < n; j++)
    {
        minIndex = i;
        for (k = j; k < n; k++)
        {
            if (arr[k] < arr[minIndex])
            {
                minIndex = k;
            }
        }

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;

        sort(arr, n, minIndex);
    }
}

int main()
{
    int n, i, j, arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, n, 0);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}