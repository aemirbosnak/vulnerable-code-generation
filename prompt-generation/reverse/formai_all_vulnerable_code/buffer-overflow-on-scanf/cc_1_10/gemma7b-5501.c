//Gemma-7B DATASET v1.0 Category: Benchmarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 1000

void quicksort(int arr[], int n);

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}

void quicksort(int arr[], int n)
{
    if (n <= 1)
    {
        return;
    }

    int partitionIndex = partition(arr, n);

    quicksort(arr, partitionIndex);
    quicksort(arr + partitionIndex, n - partitionIndex);
}

int partition(int arr[], int n)
{
    int pivot = arr[n - 1];
    int i = 0;

    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int partitionIndex = i + 1;

    return partitionIndex;
}