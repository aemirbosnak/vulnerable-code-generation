//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Bucket sort function
void bucketSort(float arr[], int n)
{
    // Create n buckets
    int i, j;
    int count[n];
    for (i = 0; i < n; i++) 
        count[i] = 0;

    // Add elements to the appropriate bucket
    for (i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        count[bucketIndex]++;
    }

    // Sort elements within each bucket
    for (i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        float bucket[count[bucketIndex]];

        for (j = 0; j < count[bucketIndex]; j++)
            bucket[j] = 0;

        count[bucketIndex] = 0;

        for (j = 0; j < n; j++) {
            if (floor(n * arr[j]) == bucketIndex) {
                bucket[count[bucketIndex]] = arr[j];
                count[bucketIndex]++;
            }
        }

        for (j = 0; j < count[bucketIndex]; j++)
            arr[count[bucketIndex]] = bucket[j];
    }
}

int main()
{
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
        scanf("%f", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%f ", arr[i]);

    return 0;
}