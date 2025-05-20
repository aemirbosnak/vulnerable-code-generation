//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000
#define MAX_VALUE 1000

// Function to generate a random array of integers
void generateArray(int arr[], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_VALUE;
    }
}

// Function to print the contents of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform the bucket sort algorithm
void bucketSort(int arr[], int size) {
    // Create an empty bucket array
    int buckets[MAX_VALUE];
    for (int i = 0; i < MAX_VALUE; i++) {
        buckets[i] = 0;
    }

    // Place each element in its respective bucket
    for (int i = 0; i < size; i++) {
        buckets[arr[i]]++;
    }

    // Modify the bucket array to store the position of each element
    for (int i = 1; i < MAX_VALUE; i++) {
        buckets[i] += buckets[i - 1];
    }

    // Place each element in its final sorted position
    for (int i = size - 1; i >= 0; i--) {
        arr[--buckets[arr[i]]] = arr[i];
    }
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[MAX_SIZE];
    if (size > MAX_SIZE) {
        printf("Error: Array size exceeds maximum limit.\n");
        return 0;
    }

    // Generate a random array of integers
    generateArray(arr, size);
    printf("Original array:\n");
    printArray(arr, size);

    // Perform the bucket sort algorithm
    bucketSort(arr, size);
    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}