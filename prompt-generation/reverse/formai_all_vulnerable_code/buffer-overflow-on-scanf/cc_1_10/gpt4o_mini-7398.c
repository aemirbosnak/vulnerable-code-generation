//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Function to create and initialize buckets
float** createBuckets(int numBuckets) {
    float** buckets = (float**)malloc(numBuckets * sizeof(float*));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = (float*)malloc(BUCKET_SIZE * sizeof(float));
    }
    return buckets;
}

// Function to insert an element into a bucket
void insertIntoBucket(float** buckets, float value, int index, int* count) {
    int position = count[index];
    if (position < BUCKET_SIZE) {
        buckets[index][position] = value;
        count[index]++;
    } else {
        printf("Bucket overflow!\n");
    }
}

// Function to perform insertion sort on a single bucket
void insertionSort(float* bucket, int count) {
    for (int i = 1; i < count; i++) {
        float key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
}

// Function to perform the bucket sort algorithm
void bucketSort(float* array, int n) {
    // Step 1: Create buckets
    float** buckets = createBuckets(n);
    int* count = (int*)calloc(n, sizeof(int));

    // Step 2: Place elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (int)(array[i] * n);
        insertIntoBucket(buckets, array[i], bucketIndex, count);
    }

    // Step 3: Sort individual buckets
    for (int i = 0; i < n; i++) {
        if (count[i] > 0) {
            insertionSort(buckets[i], count[i]);
        }
    }

    // Step 4: Concatenate buckets back into the original array
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            array[index++] = buckets[i][j];
        }
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(count);
}

// Function to print the sorted array
void printArray(float* array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", array[i]);
    }
    printf("\n");
}

// Main function to test the bucket sort
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float* array = (float*)malloc(n * sizeof(float));
    
    printf("Enter %d floating point numbers between 0 and 1:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%f", &array[i]);
    }

    bucketSort(array, n);
    
    printf("Sorted array:\n");
    printArray(array, n);

    free(array);
    return 0;
}