//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

void bucketSort(int arr[], int size) {
    int i, j, count[MAX_SIZE] = {0};
    int *bucket[MAX_SIZE];
    int max = arr[0], min = arr[0];

    // Find the minimum and maximum values in the array
    for (i = 0; i < size; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    // Allocate memory for the buckets
    for (i = 0; i < MAX_SIZE; i++) {
        bucket[i] = (int *) malloc(sizeof(int) * size);
    }

    // Place each element in its bucket
    for (i = 0; i < size; i++) {
        count[(arr[i] - min) / (max - min) * MAX_SIZE]++;
    }

    // Move the elements to their final position
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[j] = bucket[i][j];
        }
    }

    // Free the allocated memory
    for (i = 0; i < MAX_SIZE; i++) {
        free(bucket[i]);
    }
}

int main() {
    int i, n, max, min;
    int *arr;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Allocate memory for the array
    arr = (int *) malloc(sizeof(int) * n);

    // Get the elements of the array from the user
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);

    return 0;
}