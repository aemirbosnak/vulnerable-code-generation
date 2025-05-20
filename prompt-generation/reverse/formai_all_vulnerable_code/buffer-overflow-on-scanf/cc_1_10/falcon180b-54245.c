//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

void initArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int i, j, min, max, range, *bucket;

    // Find range of elements in array
    min = arr[0];
    max = arr[0];
    for (i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Calculate range and number of buckets
    range = max - min + 1;
    bucket = (int *) malloc(range * sizeof(int));

    // Place elements in appropriate bucket
    for (i = 0; i < size; i++) {
        j = (arr[i] - min) / (max - min) * range;
        bucket[j]++;
    }

    // Concatenate buckets back into array
    i = 0;
    for (j = 0; j < range; j++) {
        while (bucket[j] > 0) {
            arr[i] = min + j;
            i++;
            bucket[j]--;
        }
    }

    free(bucket);
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get array size from user
    printf("Enter array size: ");
    scanf("%d", &size);

    // Initialize array with random values
    initArray(arr, size);

    // Print unsorted array
    printf("Unsorted array:\n");
    printArray(arr, size);

    // Sort array using bucket sort
    bucketSort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}