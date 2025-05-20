//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// function to swap two integers
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// recursive function to perform bucket sort on subarrays
void bucketSort(int arr[], int n, int max_val, int div_num)
{
    // create a 2D array of size 10 x n/10
    int buckets[10][n/10];
    int bucket_sizes[10] = {0};
    int i, j;

    // distribute the elements into buckets based on div_num
    for(i=0; i<n; i++)
    {
        int bucket_index = arr[i] / div_num;
        buckets[bucket_index][bucket_sizes[bucket_index]] = arr[i];
        bucket_sizes[bucket_index]++;
    }

    // sort each non-empty bucket recursively
    for(i=0; i<10; i++)
    {
        if(bucket_sizes[i] > 0 && div_num > 1)
        {
            bucketSort(buckets[i], bucket_sizes[i], max_val, div_num/10);
        }
    }

    // concatenate the sorted buckets
    int k=0;
    for(i=0; i<10; i++)
    {
        for(j=0; j<bucket_sizes[i]; j++)
        {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

// driver function to test bucketSort
int main()
{
    int arr[] = { 231, 432, 864, 343, 564, 786, 102, 765, 987, 354, 645, 987, 769, 100, 101 };
    int n = sizeof(arr) / sizeof(arr[0]), i;
    int max_val = arr[0];

    // find the maximum value in the array
    for(i=1; i<n; i++)
    {
        if(arr[i] > max_val)
        {
            max_val = arr[i];
        }
    }

    // perform bucket sort recursively
    bucketSort(arr, n, max_val, max_val/10);

    // print the sorted array
    printf("\nSorted array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}