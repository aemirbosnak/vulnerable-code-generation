//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

int bucket_sort(int arr[], int size) {
    int i, n = 0;
    int buckets[MAX_SIZE];
    int max = arr[0], min = arr[0];

    // Find the range of the elements in the array
    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Calculate the number of buckets
    int range = max - min + 1;
    int bucket_size = range / MAX_SIZE;

    // Initialize the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = 0;
    }

    // Add the elements to the buckets
    for (i = 0; i < size; i++) {
        int bucket_index = (arr[i] - min) / bucket_size;
        buckets[bucket_index]++;
    }

    // Add the elements back to the array
    for (i = 0; i < MAX_SIZE; i++) {
        n += buckets[i];
    }
    for (i = 0; i < MAX_SIZE; i++) {
        n -= buckets[i];
        if (n >= 0) {
            arr[n + i * bucket_size] = i * bucket_size + min;
        }
    }

    return 0;
}

int main() {
    int arr[] = { 10, 5, 20, 30, 40, 15, 50 };
    int size = sizeof(arr) / sizeof(arr[0]);

    bucket_sort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}