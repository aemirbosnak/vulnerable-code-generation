//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void quicksort(int arr[], int n);

int main()
{
    int i, n, arr[MAX];

    printf("Enter the number of elements:");
    scanf("%d", &n);

    printf("Enter the elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, n);

    printf("The sorted array is:");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

void quicksort(int arr[], int n)
{
    int i, j, pivot, partitioned = 0;

    if (n <= 1)
    {
        return;
    }

    pivot = arr[0];

    for (i = 1; i < n; i++)
    {
        if (arr[i] < pivot)
        {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            partitioned++;
        }
    }

    quicksort(arr, partitioned);
    quicksort(arr + partitioned, n - partitioned);
}