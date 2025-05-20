//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000

void generateArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % MAX_SIZE;
    }
}

void bucketSort(int arr[], int size) {
    int i, j, n;
    int *bucket[MAX_SIZE];

    // Initialize all buckets to NULL
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = NULL;
    }

    // Place each element into its respective bucket
    for (i = 0; i < size; i++) {
        n = arr[i];
        if (bucket[n] == NULL) {
            bucket[n] = (int *) malloc(sizeof(int));
            *bucket[n] = n;
        } else {
            int *temp = (int *) malloc(sizeof(int));
            *temp = n;
            bucket[n] = temp;
        }
    }

    // Concatenate the sorted buckets into the original array
    i = 0;
    for (j = 0; j < MAX_SIZE; j++) {
        if (bucket[j]!= NULL) {
            while (bucket[j]!= NULL) {
                arr[i++] = *bucket[j++];
            }
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE];
    int size;

    // Get user input for array size
    printf("Enter array size: ");
    scanf("%d", &size);

    // Generate random array
    generateArray(arr, size);

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