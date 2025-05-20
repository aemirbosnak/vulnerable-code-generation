//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BUCKETS 10
#define MAX_NUMBERS 100
#define RANGE 100.0

typedef struct Bucket {
    float *elements;
    int size;
} Bucket;

// Function prototypes
void bucketSort(float arr[], int n);
void initializeBuckets(Bucket buckets[], int numBuckets);
void insertIntoBucket(Bucket *bucket, float value);
void sortBuckets(Bucket buckets[], int numBuckets);
void printArray(float arr[], int n);
void freeBuckets(Bucket buckets[], int numBuckets);

int main() {
    float arr[MAX_NUMBERS];
    int n, i;

    // Generate random float numbers
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    
    if(n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid input! Please enter a number between 1 and %d.\n", MAX_NUMBERS);
        return 1;
    }

    printf("Generating %d random float numbers between 0 and %.1f:\n", n, RANGE);
    for (i = 0; i < n; i++) {
        arr[i] = (float)rand() / RAND_MAX * RANGE;
    }

    printf("Original array: \n");
    printArray(arr, n);

    // Sort the array using bucket sort
    bucketSort(arr, n);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}

void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    Bucket buckets[NUM_BUCKETS];
    initializeBuckets(buckets, NUM_BUCKETS);

    // Step 2: Distribute elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(arr[i] * NUM_BUCKETS / RANGE);
        if (bucketIndex >= NUM_BUCKETS) {
            bucketIndex = NUM_BUCKETS - 1; // Avoid out of bounds
        }
        insertIntoBucket(&buckets[bucketIndex], arr[i]);
    }

    // Step 3: Sort each bucket
    sortBuckets(buckets, NUM_BUCKETS);

    // Step 4: Combine buckets back into the original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            arr[index++] = buckets[i].elements[j];
        }
    }

    // Free bucket memory
    freeBuckets(buckets, NUM_BUCKETS);
}

void initializeBuckets(Bucket buckets[], int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].size = 0;
        buckets[i].elements = (float *)malloc(MAX_NUMBERS * sizeof(float)); // Allocate memory for elements
        if (buckets[i].elements == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
    }
}

void insertIntoBucket(Bucket *bucket, float value) {
    bucket->elements[bucket->size++] = value; // Add the value to the bucket
}

void sortBuckets(Bucket buckets[], int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        if (buckets[i].size > 0) {
            // Use simple bubble sort for demonstration; can replace with a more efficient sort
            for (int j = 0; j < buckets[i].size - 1; j++) {
                for (int k = 0; k < buckets[i].size - j - 1; k++) {
                    if (buckets[i].elements[k] > buckets[i].elements[k + 1]) {
                        float temp = buckets[i].elements[k];
                        buckets[i].elements[k] = buckets[i].elements[k + 1];
                        buckets[i].elements[k + 1] = temp;
                    }
                }
            }
        }
    }
}

void printArray(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

void freeBuckets(Bucket buckets[], int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].elements); // Free each bucket's elements
    }
}