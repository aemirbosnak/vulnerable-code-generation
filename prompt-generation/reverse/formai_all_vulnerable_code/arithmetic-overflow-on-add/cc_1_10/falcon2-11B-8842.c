//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Function to sort elements in a bucket
void bucketSort(int arr[], int n)
{
    // Number of buckets
    int bucket_size = 100;

    // Number of elements in each bucket
    int num_elements_per_bucket = n / bucket_size;

    // Create buckets
    int *buckets = (int *) malloc(bucket_size * sizeof(int));

    // Put elements in buckets
    int i;
    for (i = 0; i < n; i++)
    {
        buckets[(arr[i] / num_elements_per_bucket) % bucket_size]++;
    }

    // Sort elements in each bucket
    int j;
    for (i = 0; i < bucket_size; i++)
    {
        for (j = 0; j < num_elements_per_bucket; j++)
        {
            if (buckets[i] > j)
            {
                buckets[i]--;
                arr[buckets[i] * num_elements_per_bucket + j] = arr[i];
            }
        }
    }

    // Free memory
    free(buckets);
}

int main()
{
    int arr[] = {12, 3, 5, 7, 1, 9, 10, 6, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}