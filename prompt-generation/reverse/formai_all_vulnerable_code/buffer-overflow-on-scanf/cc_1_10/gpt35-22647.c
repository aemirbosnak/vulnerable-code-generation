//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Function to sort using Bucket Sort
void BucketSort(int arr[], int n)
{
    // Create an array of empty buckets
    int bucket[10][10], bucket_count[10];
    int i, j, k, key;
    
    // Initialize all the buckets with zero elements
    for (i = 0; i < 10; i++)
        bucket_count[i] = 0;
    
    // Insert elements into their respective buckets
    for (i = 0; i < n; i++)
    {
        key = arr[i] / 10;
        bucket[key][bucket_count[key]++] = arr[i];
    }
    
    // Sort elements inside each bucket using Insertion Sort
    for (i = 0; i < 10; i++)
        for (j = 0; j < bucket_count[i]; j++)
            for (k = j+1; k < bucket_count[i]; k++)
                if (bucket[i][j] > bucket[i][k])
                {
                    // Swap the elements to sort them
                    int temp = bucket[i][j];
                    bucket[i][j] = bucket[i][k];
                    bucket[i][k] = temp;
                }

    // Merge all the sorted elements into the original array
    int index = 0;
    for (i = 0; i < 10; i++)
        for (j = 0; j < bucket_count[i]; j++)
            arr[index++] = bucket[i][j];
}

// Driver program to test the BucketSort function
int main()
{
    int i, n, arr[100];
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Initial array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    BucketSort(arr, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}