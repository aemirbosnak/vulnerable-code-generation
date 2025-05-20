//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000
#define RANGE 1000000

// Function to generate a random integer between 0 and RANGE-1
int randInt() {
    return rand() % RANGE;
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bucket sort on an array of integers
void bucketSort(int arr[], int size) {
    int i, j, index;
    int* buckets[MAX_SIZE];

    // Create empty buckets
    for (i = 0; i < MAX_SIZE; i++) {
        buckets[i] = malloc(sizeof(int) * size);
    }

    // Distribute elements into buckets
    for (i = 0; i < size; i++) {
        index = arr[i] / RANGE;
        buckets[index][i % MAX_SIZE] = arr[i];
    }

    // Sort each bucket using insertion sort
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 1; j < size; j++) {
            swap(&buckets[i][j - 1], &buckets[i][j]);
        }
    }

    // Merge sorted buckets back into original array
    for (i = 0; i < size; i++) {
        arr[i] = buckets[arr[i] / RANGE][i % MAX_SIZE];
    }

    // Free memory allocated for buckets
    for (i = 0; i < MAX_SIZE; i++) {
        free(buckets[i]);
    }
}

int main() {
    int i, size;
    int* arr;

    // Get size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Dynamically allocate memory for array
    arr = malloc(sizeof(int) * size);

    // Populate array with random integers
    for (i = 0; i < size; i++) {
        arr[i] = randInt();
    }

    // Print unsorted array
    printf("Unsorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort array using bucket sort
    bucketSort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free memory allocated for array
    free(arr);

    return 0;
}