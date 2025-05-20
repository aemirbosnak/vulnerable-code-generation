//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/**
 * This function creates a bucket for the given range,
 * which is calculated based on the number of elements and their maximum value.
 */
int getBucketIndex(float value, int numberOfBuckets, float maxValue) {
    return (int)((value / maxValue) * numberOfBuckets);
}

/**
 * A single bucket structure to hold the values.
 */
typedef struct Bucket {
    float *array;
    int size;
    int capacity;
} Bucket;

/**
 * Function to create a bucket dynamically.
 */
Bucket* createBucket(int capacity) {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->array = (float*)malloc(capacity * sizeof(float));
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

/**
 * Function to insert an item into the bucket.
 */
void insertIntoBucket(Bucket* bucket, float value) {
    if (bucket->size < bucket->capacity) {
        bucket->array[bucket->size++] = value;
    } else {
        // If the bucket is full we double its capacity
        bucket->capacity *= 2;
        bucket->array = (float*)realloc(bucket->array, bucket->capacity * sizeof(float));
        bucket->array[bucket->size++] = value;
    }
}

/**
 * A simple insertion sort function to sort the values within each bucket.
 */
void insertionSort(float* arr, int size) {
    for (int i = 1; i < size; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * The main bucket sort function that orchestrates the sorting process.
 */
void bucketSort(float* arr, int n) {
    // Main variables
    int numberOfBuckets = (n / 5) + 1;   // arbitrary bucket size
    Bucket** buckets = (Bucket**)malloc(numberOfBuckets * sizeof(Bucket*));
    
    // Initialize the buckets
    for (int i = 0; i < numberOfBuckets; i++) {
        buckets[i] = createBucket(n);
    }

    // Determine the maximum value to calculate bucket index
    float maxValue = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    // Insert elements into respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = getBucketIndex(arr[i], numberOfBuckets, maxValue);
        insertIntoBucket(buckets[bucketIndex], arr[i]);
    }

    // Sort buckets and concatenate
    int index = 0;
    for (int i = 0; i < numberOfBuckets; i++) {
        if (buckets[i]->size > 0) {
            insertionSort(buckets[i]->array, buckets[i]->size);
            for (int j = 0; j < buckets[i]->size; j++) {
                arr[index++] = buckets[i]->array[j];
            }
        }
        free(buckets[i]->array); // Free individual bucket array
        free(buckets[i]);        // Free individual bucket struct
    }

    // Free the bucket array holder
    free(buckets);
}

/**
 * Function to print the array.
 */
void printArray(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

/**
 * A little twist: Main function to demonstrate the puzzle-solving bucket sort!
 */
int main() {
    // Play with this array of floats
    float arr[MAX];
    int n;

    printf("Enter number of elements to be sorted (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Array created:\n");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);
    
    return 0;
}