//Falcon2-11B DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

// Function to sort the array elements
void bucketSort(int arr[], int n, int max_size)
{
    // Initialize array for each bucket
    int *bucket = (int*)malloc(n * sizeof(int));

    // Initialize bucket array with zeros
    for (int i = 0; i < n; i++)
        bucket[i] = 0;

    // Create buckets
    for (int i = 0; i < max_size; i++)
    {
        int count = 0;
        int start = 0;
        int end = i;

        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] > i)
                end = mid - 1;
            else
            {
                bucket[i] += 1;
                start = mid + 1;
                count++;
            }
        }

        // If there are elements to be sorted in this bucket
        if (count > 0)
        {
            start = 0;
            end = count - 1;

            // Sort elements in this bucket
            while (start <= end)
            {
                int mid = (start + end) / 2;
                int temp = arr[mid];
                arr[mid] = arr[start];
                start++;

                arr[mid] = temp;
            }
        }
    }

    free(bucket);
}

int main()
{
    int n, i, arr[1000];

    // Take input
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int max_size = arr[n - 1];

    // Sort the array using bucket sort
    bucketSort(arr, n, max_size);

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}