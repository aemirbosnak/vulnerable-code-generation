//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: funny
#include<stdio.h>
#include<stdlib.h>

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int bucketSort(int arr[], int size)
{
    int i, j, temp;
    int min, max, bucket[size+1];

    // find the minimum and maximum elements
    min = arr[0];
    max = arr[0];
    for (i = 1; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }

    // create buckets to store elements
    for (i = 0; i <= max; i++)
        bucket[i] = 0;

    // put elements into appropriate buckets
    for (i = 0; i < size; i++)
    {
        if (arr[i] < min)
            bucket[min]++;
        else if (arr[i] > max)
            bucket[arr[i]]++;
    }

    // sort each bucket and place elements back into array
    for (i = min; i <= max; i++)
    {
        temp = i;
        while (bucket[temp]--)
            arr[bucket[temp]] = temp;
    }

    // print the sorted array
    printArray(arr, size);
    return 0;
}

int main()
{
    int arr[] = { 12, 5, 9, 1, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("\nSorted Array: ");
    printArray(arr, n);

    return 0;
}