//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_COUNT 10  // Define the number of buckets

// A structure to represent a bucket
struct Bucket {
    float* items;  // Pointer to hold items in the bucket
    int size;      // Number of items in the bucket
};

// Function to create buckets
struct Bucket* createBuckets(int count) {
    struct Bucket* buckets = (struct Bucket*)malloc(count * sizeof(struct Bucket));
    if (buckets == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }

    for (int i = 0; i < count; i++) {
        buckets[i].size = 0;
        buckets[i].items = (float*)malloc(0);
    }
    return buckets;
}

// Function to insert an element into a specific bucket
void insertIntoBucket(struct Bucket* bucket, float value) {
    bucket->size++;
    bucket->items = (float*)realloc(bucket->items, bucket->size * sizeof(float));
    if (bucket->items == NULL) {
        fprintf(stderr, "Memory reallocation error!\n");
        exit(1);
    }
    bucket->items[bucket->size - 1] = value;
}

// Simple sort function using insertion sort for a single bucket
void sortBucket(struct Bucket* bucket) {
    for (int i = 1; i < bucket->size; i++) {
        float key = bucket->items[i];
        int j = i - 1;

        // Move elements of bucket->items[0..i-1] that are greater
        // than key to one position ahead of their current position
        while (j >= 0 && bucket->items[j] > key) {
            bucket->items[j + 1] = bucket->items[j];
            j--;
        }
        bucket->items[j + 1] = key;
    }
}

// Function to concatenate sorted buckets into one array
void concatenateBuckets(struct Bucket* buckets, int count, float* sortedArray) {
    int index = 0;

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            sortedArray[index++] = buckets[i].items[j];
        }
    }
}

// The main bucket sort function
void bucketSort(float* array, int n) {
    if (n <= 0) return;  // If the array is empty, do nothing

    struct Bucket* buckets = createBuckets(BUCKET_COUNT);

    // Insert elements into their respective buckets
    for (int i = 0; i < n; i++) {
        int index = (int)(BUCKET_COUNT * array[i]);  // Determine bucket index
        if (index >= BUCKET_COUNT) {
            index = BUCKET_COUNT - 1;  // Edge case for the last bucket
        }
        insertIntoBucket(&buckets[index], array[i]);
    }

    // Sort each bucket
    for (int i = 0; i < BUCKET_COUNT; i++) {
        sortBucket(&buckets[i]);
    }

    // Concatenate the sorted buckets back into the original array
    concatenateBuckets(buckets, BUCKET_COUNT, array);

    // Free allocated memory for buckets
    for (int i = 0; i < BUCKET_COUNT; i++) {
        free(buckets[i].items);
    }
    free(buckets);
}

// Helper function to print an array
void printArray(float* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements to sort: ");
    scanf("%d", &n);

    // Create an array to hold the elements
    float* array = (float*)malloc(n * sizeof(float));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation error!\n");
        return 1;
    }

    // Input elements
    printf("Enter the elements (between 0.0 and 1.0): ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    // Perform the bucket sort
    bucketSort(array, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(array, n);

    // Free allocated memory for the array
    free(array);
    return 0;
}