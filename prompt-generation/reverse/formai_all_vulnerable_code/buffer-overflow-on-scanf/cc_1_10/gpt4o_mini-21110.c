//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a bucket
typedef struct Bucket {
    int* arr;              // array for storing values
    int size;             // current number of elements in the bucket
    int capacity;         // capacity of the bucket
} Bucket;

// Function to create and initialize a new bucket
Bucket* createBucket(int capacity) {
    Bucket* bucket = (Bucket*) malloc(sizeof(Bucket));
    bucket->arr = (int*) malloc(sizeof(int) * capacity);
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

// Function to add an element to the bucket
void addElement(Bucket* bucket, int value) {
    if (bucket->size < bucket->capacity) {
        bucket->arr[bucket->size++] = value;
    } else {
        // Expand the bucket if it's full
        bucket->capacity *= 2;
        bucket->arr = (int*) realloc(bucket->arr, sizeof(int) * bucket->capacity);
        bucket->arr[bucket->size++] = value;
    }
}

// Function to sort the elements in the bucket using insertion sort
void insertionSort(int* arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int* arr, int n) {
    if (n <= 0) return;

    // Create buckets
    Bucket** buckets = (Bucket**) malloc(sizeof(Bucket*) * n);
    for (int i = 0; i < n; i++) {
        buckets[i] = createBucket(5); // Initialize each bucket with a capacity
    }

    // Find max value to distribute values into buckets
    int maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Put array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] * n) / (maxValue + 1);
        addElement(buckets[bucketIndex], arr[i]);
    }

    // Sort each bucket and concatenate results
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (buckets[i]->size > 0) {
            insertionSort(buckets[i]->arr, buckets[i]->size);
            for (int j = 0; j < buckets[i]->size; j++) {
                arr[index++] = buckets[i]->arr[j];
            }
        }
    }

    // Free memory for buckets
    for (int i = 0; i < n; i++) {
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to drive the program
int main() {
    int n;
    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(sizeof(int) * n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    // Perform bucket sort
    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    // Free the array memory
    free(arr);
    return 0;
}