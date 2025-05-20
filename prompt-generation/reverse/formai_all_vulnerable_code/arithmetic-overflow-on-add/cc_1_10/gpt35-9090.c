//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>

/* Bucket Sort Function */
void bucketSort(float arr[], int n)
{
    // Create n Buckets
    int i, j, idx;
    int* cnt = (int*)calloc(n, sizeof(int));
    float* bucket = (float*)calloc(n, sizeof(float));

    // Mapping values to the appropriate bucket
    for (i = 0; i < n; i++) {
        idx = (int)(arr[i] * n);
        bucket[idx] += arr[i];
        cnt[idx]++;
    }

    // Sorting each bucket using insertion sort
    int k = 0;
    for (i = 0; i < n; i++) {
        if (cnt[i]) {
            for (j = 0; j < cnt[i]; j++) {
                arr[k++] = bucket[i] / cnt[i];
            }
        }
    }

    // Deallocating memory
    free(cnt);
    free(bucket);
}

/* Main Function */
int main()
{
    // Initializing the Array to be Sorted
    float arr[] = { 0.6, 0.9, 0.1, 0.8, 0.3, 0.7, 0.2, 0.4, 0.5, 0.05 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Applying Bucket Sort
    bucketSort(arr, n);

    // Displaying the Sorted Array
    printf("The Sorted Array is: ");
    for (int i = 0; i < n; i++) {
        printf("%0.2f ", arr[i]);
    }

    return 0;
}