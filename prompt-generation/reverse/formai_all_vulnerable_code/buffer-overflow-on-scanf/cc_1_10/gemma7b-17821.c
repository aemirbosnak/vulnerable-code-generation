//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void heapify(int **arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int i1 = 2 * i + 1;
        int i2 = 2 * i + 2;

        if (i1 < n && arr[i1] > arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[i1];
            arr[i1] = temp;
        }

        if (i2 < n && arr[i2] > arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[i2];
            arr[i2] = temp;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int **arr = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (int *)malloc(MAX * sizeof(int));
    }

    printf("Enter the node data: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    heapify(arr, n);

    printf("The sorted node data is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}