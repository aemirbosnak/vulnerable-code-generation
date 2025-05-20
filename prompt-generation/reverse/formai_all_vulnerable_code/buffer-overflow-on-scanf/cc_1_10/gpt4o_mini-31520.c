//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BUCKET_COUNT 10        // Number of buckets
#define MAX_ELEMENTS 1000      // Maximum number of elements to sort

typedef struct Bucket {
    float *array;      // Pointer to hold the elements in the bucket
    int size;          // Number of elements in the bucket
} Bucket;

// Function to create a bucket
Bucket* createBucket() {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    if (!bucket) {
        fprintf(stderr, "Memory allocation failed for bucket.\n");
        exit(EXIT_FAILURE);
    }
    bucket->array = (float*)malloc(sizeof(float) * MAX_ELEMENTS);
    bucket->size = 0;
    return bucket;
}

// Function to free a bucket
void destroyBucket(Bucket* bucket) {
    free(bucket->array);
    free(bucket);
}

// Function to insert an element into a bucket
void insertIntoBucket(Bucket* bucket, float value) {
    bucket->array[bucket->size++] = value;
}

// Function to sort individual buckets using insertion sort
void insertionSort(float *array, int size) {
    for (int i = 1; i < size; i++) {
        float key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Bucket sort algorithm
void bucketSort(float *array, int n) {
    if (n <= 0) {
        fprintf(stderr, "Array size must be positive.\n");
        return;
    }

    Bucket** buckets = (Bucket**)malloc(BUCKET_COUNT * sizeof(Bucket*));
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = createBucket();
    }

    // Distributing input array elements into buckets
    for (int i = 0; i < n; i++) {
        int idx = (int)(BUCKET_COUNT * array[i]);
        if (idx >= BUCKET_COUNT) idx = BUCKET_COUNT - 1; // Place in last bucket
        insertIntoBucket(buckets[idx], array[i]);
    }

    // Sorting individual buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        insertionSort(buckets[i]->array, buckets[i]->size);
    }

    // Merging the sorted buckets into the original array
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            array[index++] = buckets[i]->array[j];
        }
        destroyBucket(buckets[i]);
    }
    free(buckets);
}

// Utility function to print an array
void printArray(float *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Main function to test the bucket sort
int main() {
    int n;
    float *array;

    printf("Enter the number of elements to sort (max %d): ", MAX_ELEMENTS);
    scanf("%d", &n);
    if (n <= 0 || n > MAX_ELEMENTS) {
        fprintf(stderr, "Invalid number of elements.\n");
        return EXIT_FAILURE;
    }

    array = (float*)malloc(n * sizeof(float));
    if (!array) {
        fprintf(stderr, "Memory allocation failed for array.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the elements (between 0.0 and 1.0):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
        if (array[i] < 0.0 || array[i] > 1.0) {
            fprintf(stderr, "Elements must be in the range [0.0, 1.0].\n");
            free(array);
            return EXIT_FAILURE;
        }
    }

    printf("Original array:\n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Sorted array:\n");
    printArray(array, n);

    free(array);
    return EXIT_SUCCESS;
}