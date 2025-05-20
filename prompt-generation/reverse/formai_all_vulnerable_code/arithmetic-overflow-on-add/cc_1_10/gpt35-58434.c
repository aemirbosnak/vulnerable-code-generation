//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

/* Bucket sort function to sort the array. */
void bucketSort(int arr[], int n)
{
    /* Finding maximum value from the input array */ 
    int maxVal = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    /* Creating an array of buckets */
    int* bucket = (int*)calloc(maxVal + 1, sizeof(int));

    /* Placing elements to their respective buckets */
    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;

    /* Merging the buckets to get the sorted array */
    int j = 0;
    for (int i = 0; i <= maxVal; i++)
    {
        while (bucket[i] > 0)
        {
            arr[j++] = i;
            bucket[i]--;
        }
    }

    /* Freeing the bucket array memory*/
    free(bucket);
}

/* Main driver code */
int main()
{
    int arr[] = { 23, 45, 78, 12, 67, 90, 11, 34, 56, 76 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    /* Sorting the array using bucket sort */
    bucketSort(arr, n);

    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}