//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: medieval
#include <stdio.h>

#define MAX_SIZE 1000

void bucket_sort(int arr[], int n) {

    int i, j, max, min;
    int bucket[MAX_SIZE];

    // Find minimum and maximum values in the array
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

    // Calculate bucket size
    int bucket_size = (max - min) / n;

    // Initialize buckets
    for (i = 0; i < n; i++) {
        bucket[i] = 0;
    }

    // Place elements in buckets
    for (i = 0; i < n; i++) {
        j = (arr[i] - min) / bucket_size;
        bucket[j]++;
    }

    // Merge buckets
    int index = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < bucket[i]; j++) {
            arr[index++] = i * bucket_size + j * bucket_size;
        }
    }
}

int main() {

    int arr[] = { 1, 5, 3, 8, 2, 7, 4, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucket_sort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}