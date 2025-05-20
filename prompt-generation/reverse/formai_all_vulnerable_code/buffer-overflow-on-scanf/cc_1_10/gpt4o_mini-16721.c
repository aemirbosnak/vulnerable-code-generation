//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 100

// Structure to represent a bucket
typedef struct Bucket {
    float *values;
    int count;
} Bucket;

// Function to create a bucket
Bucket* createBucket(int size) {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->values = (float*)malloc(size * sizeof(float));
    bucket->count = 0;
    return bucket;
}

// Function to free the bucket memory
void freeBucket(Bucket* bucket) {
    free(bucket->values);
    free(bucket);
}

// Function to perform insertion sort on a bucket
void insertionSort(Bucket* bucket) {
    for (int i = 1; i < bucket->count; i++) {
        float key = bucket->values[i];
        int j = i - 1;
        while (j >= 0 && bucket->values[j] > key) {
            bucket->values[j + 1] = bucket->values[j];
            j--;
        }
        bucket->values[j + 1] = key;
    }
}

// Bucket sort function
void bucketSort(float array[], int n) {
    if (n <= 0) return;

    // Create buckets
    Bucket** buckets = (Bucket**)malloc(n * sizeof(Bucket*));
    for (int i = 0; i < n; i++) {
        buckets[i] = createBucket(n);
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(array[i] * n / MAX_VALUE);
        buckets[index]->values[buckets[index]->count++] = array[i];
    }

    // Sort individual buckets and collect the results
    int index = 0;
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i]);
        for (int j = 0; j < buckets[i]->count; j++) {
            array[index++] = buckets[i]->values[j];
        }
        freeBucket(buckets[i]);
    }

    free(buckets);
}

// Function to print an array
void printArray(float array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Main function to demonstrate the bucket sort
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float* array = (float*)malloc(n * sizeof(float));
    printf("Enter the elements (from 0 to 100):\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    printf("Array before sorting:\n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Array after sorting:\n");
    printArray(array, n);

    free(array);
    return 0;
}