//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 100

// Struct representing a bucket
typedef struct Bucket {
    float *array;
    int size;
} Bucket;

// Function to initialize a bucket
void initBucket(Bucket *bucket) {
    bucket->size = 0;
    bucket->array = (float *)malloc(MAX_NUM * sizeof(float));
}

// Function to add an element to a bucket
void addElementToBucket(Bucket *bucket, float value) {
    bucket->array[bucket->size++] = value;
}

// Function to sort elements within a bucket
void bucketSort(Bucket *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->array[j] > bucket->array[j + 1]) {
                float temp = bucket->array[j];
                bucket->array[j] = bucket->array[j + 1];
                bucket->array[j + 1] = temp;
            }
        }
    }
}

// Function to merge all buckets back into the original array
void mergeBuckets(Bucket *buckets, int numBuckets, float *sortedArray, int *sortedIndex) {
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].size; j++) {
            sortedArray[(*sortedIndex)++] = buckets[i].array[j];
        }
    }
}

int main() {
    int numElements, numBuckets, sortedIndex = 0;
    float *inputArray;
    
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);
    
    inputArray = (float *)malloc(numElements * sizeof(float));

    printf("Enter the elements (float numbers):\n");
    for (int i = 0; i < numElements; i++) {
        scanf("%f", &inputArray[i]);
    }

    printf("Enter the number of buckets: ");
    scanf("%d", &numBuckets);

    Bucket *buckets = (Bucket *)malloc(numBuckets * sizeof(Bucket));
    for (int i = 0; i < numBuckets; i++) {
        initBucket(&buckets[i]);
    }

    // Distribute input elements into buckets
    for (int i = 0; i < numElements; i++) {
        int bucketIndex = (int)(inputArray[i] * numBuckets / (MAX_NUM + 1)); // Mapping value to a bucket
        if (bucketIndex >= numBuckets) { // Ensuring index is within range
            bucketIndex = numBuckets - 1;
        }
        addElementToBucket(&buckets[bucketIndex], inputArray[i]);
    }

    // Sort each bucket
    for (int i = 0; i < numBuckets; i++) {
        bucketSort(&buckets[i]);
    }

    // Prepare to store the sorted result
    float *sortedArray = (float *)malloc(numElements * sizeof(float));
    
    // Merge all buckets into the sorted array
    mergeBuckets(buckets, numBuckets, sortedArray, &sortedIndex);
    
    // Output the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < sortedIndex; i++) {
        printf("%f ", sortedArray[i]);
    }
    printf("\n");

    // Free allocated memory
    for (int i = 0; i < numBuckets; i++) {
        free(buckets[i].array);
    }
    free(buckets);
    free(inputArray);
    free(sortedArray);

    return 0;
}