//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {
    int i, j, max, min, range, size, *count;
    int *bucket[MAX_SIZE];

    // Find the maximum and minimum values in the array
    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the range and size of each bucket
    range = max - min + 1;
    size = range / n;

    // Create an array of pointers to each bucket
    for (i = 0; i < n; i++) {
        bucket[i] = (int *) malloc(size * sizeof(int));
    }

    // Count the number of elements in each bucket
    count = (int *) malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / size;
        bucket[j][count[j]++] = arr[i];
    }

    // Copy the elements back into the original array
    for (i = 0; i < n; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[i * size + j] = bucket[i][j];
        }
    }

    // Free the memory used by the buckets and count array
    for (i = 0; i < n; i++) {
        free(bucket[i]);
    }
    free(count);
}

int main() {
    int arr[] = { 3, 2, 8, 1, 7, 5, 6, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucket_sort(arr, n);

    printf("After sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}