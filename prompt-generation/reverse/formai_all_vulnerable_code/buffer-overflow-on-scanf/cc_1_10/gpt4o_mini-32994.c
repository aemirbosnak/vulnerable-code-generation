//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bucket
typedef struct Bucket {
    float *elements;
    int count;
} Bucket;

// Function to create a bucket and allocate memory
Bucket* createBucket(int size) {
    Bucket* newBucket = (Bucket*)malloc(sizeof(Bucket));
    newBucket->elements = (float*)malloc(size * sizeof(float));
    newBucket->count = 0;
    return newBucket;
}

// Function to free memory allocated for buckets
void freeBucks(Bucket* bucks, int n) {
    for (int i = 0; i < n; i++) {
        free(bucks[i].elements);
    }
    free(bucks);
}

// Function to insert an element into the bucket
void insertIntoBucket(Bucket* bucket, float value) {
    bucket->elements[bucket->count++] = value;
}

// Comparison function to sort individual buckets
int compare(const void* a, const void* b) {
    return (*(float*)a > *(float*)b) - (*(float*)a < *(float*)b);
}

// Bucket Sort Function
void bucketSort(float* array, int n) {
    // Create buckets
    int bucketCount = n; // Number of buckets
    Bucket* buckets = (Bucket*)malloc(bucketCount * sizeof(Bucket));

    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = *createBucket(n);
    }

    // Find the maximum value in the array
    float maxValue = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    // Distribute the input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(array[i] * bucketCount / (maxValue + 1));
        insertIntoBucket(&buckets[bucketIndex], array[i]);
    }

    // Sort the individual buckets
    for (int i = 0; i < bucketCount; i++) {
        if (buckets[i].count > 0) {
            qsort(buckets[i].elements, buckets[i].count, sizeof(float), compare);
        }
    }

    // Concatenate the sorted buckets back into the array
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index++] = buckets[i].elements[j];
        }
    }

    // Free allocated memory for buckets
    freeBucks(buckets, bucketCount);
}

// Function to print an array
void printArray(float* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");
}

// Main function to test the bucket sort implementation
int main() {
    int n;

    // Input: size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of elements must be positive.\n");
        return 1;
    }

    float* array = (float*)malloc(n * sizeof(float));
    
    // Input: array elements
    printf("Enter %d floating-point numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    printf("Original array: ");
    printArray(array, n);
    
    // Perform Bucket Sort
    bucketSort(array, n);

    // Output: sorted array
    printf("Sorted array: ");
    printArray(array, n);

    // Clean up allocated memory
    free(array);
    
    return 0;
}