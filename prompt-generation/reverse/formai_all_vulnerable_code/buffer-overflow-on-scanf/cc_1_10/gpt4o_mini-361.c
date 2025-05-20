//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUCKETS 10

// Structure to represent a single bucket
typedef struct Bucket {
    float* values;
    int count;
} Bucket;

// Function to initialize a bucket
void initBucket(Bucket* bucket) {
    bucket->values = (float*)malloc(sizeof(float) * 10); // initial size
    bucket->count = 0;
}

// Function to resize the bucket when full
void resizeBucket(Bucket* bucket) {
    int newSize = bucket->count + 10;
    bucket->values = (float*)realloc(bucket->values, sizeof(float) * newSize);
}

// Function to sort an individual bucket using Insertion Sort
void insertionSort(float* array, int n) {
    for (int i = 1; i < n; i++) {
        float key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// Main Bucket Sort function
void bucketSort(float* arr, int n) {
    if (n <= 0) return;

    Bucket buckets[MAX_BUCKETS];

    // Initialize the buckets
    for (int i = 0; i < MAX_BUCKETS; i++) {
        initBucket(&buckets[i]);
    }

    // Insert elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(MAX_BUCKETS * arr[i]);
        if (bucketIndex >= MAX_BUCKETS) {
            bucketIndex = MAX_BUCKETS - 1;
        }
        if (buckets[bucketIndex].count % 10 == 0) {
            resizeBucket(&buckets[bucketIndex]);
        }
        buckets[bucketIndex].values[buckets[bucketIndex].count++] = arr[i];
    }

    // Sort each bucket and concatenate the results
    int index = 0;
    for (int i = 0; i < MAX_BUCKETS; i++) {
        if (buckets[i].count > 0) {
            insertionSort(buckets[i].values, buckets[i].count);
            for (int j = 0; j < buckets[i].count; j++) {
                arr[index++] = buckets[i].values[j];
            }
        }
        free(buckets[i].values);
    }
}

// Function to display the array
void displayArray(float* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

// Main program
int main() {
    int n;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    float* arr = (float*)malloc(sizeof(float) * n);
    printf("Enter %d floating-point numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Original array:\n");
    displayArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array:\n");
    displayArray(arr, n);

    free(arr);
    return 0;
}