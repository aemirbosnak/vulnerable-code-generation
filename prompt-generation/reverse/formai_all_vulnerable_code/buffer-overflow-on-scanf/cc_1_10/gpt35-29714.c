//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucketSort(int arr[], int n) 
{
    int i, j;
    int count[BUCKET_SIZE] = {0};
    int *bucket = (int*)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) 
    {
        count[arr[i]]++;
    }

    for (i = 1; i < BUCKET_SIZE; i++) 
    {
        count[i] += count[i-1];
    }

    for (i = n - 1; i >= 0; i--) 
    {
        bucket[--count[arr[i]]] = arr[i];
    }

    for (i = 0, j = 0; i < n; i++, j++) 
    {
        arr[i] = bucket[i];
    }

    free(bucket);
}

int main()
{
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements of array:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: \t");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted Array: \t\t");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}