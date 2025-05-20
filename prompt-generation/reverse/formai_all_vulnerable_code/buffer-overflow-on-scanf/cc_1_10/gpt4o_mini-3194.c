//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10

// Structure for a bucket
typedef struct Bucket {
    float* array;
    int size;
} Bucket;

// Function prototypes
void bucketSort(float array[], int n);
void insertIntoBucket(float value, Bucket* bucket);
void sortBucket(Bucket* bucket);
void printArray(float array[], int n);
void freeBuckets(Bucket buckets[]);

int main() {
    int n, i;
    float* array;

    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    // Allocate memory for the array
    array = (float*)malloc(n * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d floating-point numbers between 0 and 1:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &array[i]);
        if (array[i] < 0 || array[i] > 1) {
            fprintf(stderr, "Value %.2f is out of range! Must be between 0 and 1.\n", array[i]);
            free(array);
            return EXIT_FAILURE;
        }
    }

    bucketSort(array, n);
    
    printf("Sorted Array:\n");
    printArray(array, n);

    free(array);
    return EXIT_SUCCESS;
}

// Function to perform bucket sort
void bucketSort(float array[], int n) {
    int i;
    Bucket buckets[BUCKET_COUNT];

    // Initialize buckets
    for (i = 0; i < BUCKET_COUNT; i++) {
        buckets[i].array = (float*)malloc(n * sizeof(float));
        buckets[i].size = 0;
    }

    // Put array elements into buckets
    for (i = 0; i < n; i++) {
        int index = (int)(array[i] * BUCKET_COUNT);
        if (index == BUCKET_COUNT) index--; // Ensure the index is within bounds
        insertIntoBucket(array[i], &buckets[index]);
    }

    // Sort individual buckets and gather them back into the main array
    int arrayIndex = 0;
    for (i = 0; i < BUCKET_COUNT; i++) {
        sortBucket(&buckets[i]);
        for (int j = 0; j < buckets[i].size; j++) {
            array[arrayIndex++] = buckets[i].array[j];
        }
        free(buckets[i].array);
    }
}

// Insert value into a bucket
void insertIntoBucket(float value, Bucket* bucket) {
    bucket->array[bucket->size++] = value;
}

// Sort a bucket using simple insertion sort
void sortBucket(Bucket* bucket) {
    for (int i = 1; i < bucket->size; i++) {
        float key = bucket->array[i];
        int j = i - 1;
        while (j >= 0 && bucket->array[j] > key) {
            bucket->array[j + 1] = bucket->array[j];
            j--;
        }
        bucket->array[j + 1] = key;
    }
}

// Function to print the array
void printArray(float array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Free the memory allocated for buckets (not necessary here since we free them in bucketSort)
void freeBuckets(Bucket buckets[]) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i].array);
    }
}