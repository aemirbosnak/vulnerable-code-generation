//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void bucketSort(int arr[], int n)
{
    int i, j, k, max, min, range, bucket[MAX_SIZE];

    // Find the minimum and maximum values in the array
    min = arr[0];
    max = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate the range and number of buckets
    range = max - min + 1;
    if (range <= 0) {
        range = 1;
    }
    k = n / range;
    if (k <= 0) {
        k = 1;
    }

    // Initialize the buckets
    for (i = 0; i < k; i++) {
        bucket[i] = -1;
    }

    // Sort the array
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range;
        if (bucket[j] == -1) {
            bucket[j] = i;
        } else {
            printf("Error: Duplicate value found in the array.\n");
            exit(0);
        }
    }

    // Place the elements in the sorted order
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / range;
        if (bucket[j] == -1) {
            printf("Error: Element not found in the array.\n");
            exit(0);
        }
        printf("%d ", arr[bucket[j]]);
        bucket[j] = -1;
    }
}

int main()
{
    int n, i;
    int arr[MAX_SIZE];

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    return 0;
}