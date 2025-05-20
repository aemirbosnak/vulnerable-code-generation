//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Function to create a bucket
struct bucket {
    int count;
    int *array;
};

// Function to create a bucket array
struct bucket *createBucketArray(int numBuckets) {
    struct bucket *buckets = (struct bucket *)malloc(sizeof(struct bucket) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        buckets[i].count = 0;
        buckets[i].array = NULL;
    }
    return buckets;
}

// Function to insert an element into a bucket
void insertIntoBucket(struct bucket *buckets, int numBuckets, int element) {
    int bucketIndex = element / numBuckets;
    if (buckets[bucketIndex].array == NULL) {
        buckets[bucketIndex].array = (int *)malloc(sizeof(int));
        buckets[bucketIndex].array[0] = element;
        buckets[bucketIndex].count = 1;
    } else {
        int *newArray = (int *)realloc(buckets[bucketIndex].array, sizeof(int) * (buckets[bucketIndex].count + 1));
        if (newArray != NULL) {
            buckets[bucketIndex].array = newArray;
            buckets[bucketIndex].array[buckets[bucketIndex].count] = element;
            buckets[bucketIndex].count++;
        } else {
            printf("Error: Memory allocation failed.\n");
            exit(1);
        }
    }
}

// Function to sort a bucket
void sortBucket(struct bucket *bucket) {
    // Insertion Sort
    for (int i = 1; i < bucket->count; i++) {
        int key = bucket->array[i];
        int j = i - 1;
        while (j >= 0 && bucket->array[j] > key) {
            bucket->array[j + 1] = bucket->array[j];
            j--;
        }
        bucket->array[j + 1] = key;
    }
}

// Function to sort an array using bucket sort
void bucketSort(int *array, int numElements, int numBuckets) {
    // Create a bucket array
    struct bucket *buckets = createBucketArray(numBuckets);

    // Insert elements into buckets
    for (int i = 0; i < numElements; i++) {
        insertIntoBucket(buckets, numBuckets, array[i]);
    }

    // Sort each bucket
    for (int i = 0; i < numBuckets; i++) {
        sortBucket(&buckets[i]);
    }

    // Concatenate buckets into a sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            array[index] = buckets[i].array[j];
            index++;
        }
        free(buckets[i].array);
    }
    free(buckets);
}

// Function to print an array
void printArray(int *array, int numElements) {
    for (int i = 0; i < numElements; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    // Get the input array
    int numElements, numBuckets;
    printf("Enter the number of elements: ");
    scanf("%d", &numElements);
    printf("Enter the number of buckets: ");
    scanf("%d", &numBuckets);
    int *array = (int *)malloc(sizeof(int) * numElements);
    printf("Enter the elements: ");
    for (int i = 0; i < numElements; i++) {
        scanf("%d", &array[i]);
    }

    // Sort the array using bucket sort
    bucketSort(array, numElements, numBuckets);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(array, numElements);

    // Free the allocated memory
    free(array);
    return 0;
}