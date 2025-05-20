//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>

// Create a bucket
struct Bucket {
    int *arr;
    int size;
    int capacity;
};

// Create a new bucket
struct Bucket *createBucket(int capacity) {
    struct Bucket *bucket = (struct Bucket *)malloc(sizeof(struct Bucket));
    bucket->arr = (int *)malloc(sizeof(int) * capacity);
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

// Insert an element into a bucket
void insertIntoBucket(struct Bucket *bucket, int element) {
    if (bucket->size == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->arr = (int *)realloc(bucket->arr, sizeof(int) * bucket->capacity);
    }
    bucket->arr[bucket->size++] = element;
}

// Sort a bucket
void sortBucket(struct Bucket *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->arr[j] > bucket->arr[j + 1]) {
                int temp = bucket->arr[j];
                bucket->arr[j] = bucket->arr[j + 1];
                bucket->arr[j + 1] = temp;
            }
        }
    }
}

// Perform bucket sort on an array
void bucketSort(int *arr, int n) {
    // Create buckets
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int bucketCount = (max - min) / n + 1;
    struct Bucket **buckets = (struct Bucket **)malloc(sizeof(struct Bucket *) * bucketCount);
    for (int i = 0; i < bucketCount; i++) {
        buckets[i] = createBucket(n);
    }

    // Insert elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (arr[i] - min) / n;
        insertIntoBucket(buckets[bucketIndex], arr[i]);
    }

    // Sort buckets
    for (int i = 0; i < bucketCount; i++) {
        sortBucket(buckets[i]);
    }

    // Concatenate buckets
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[index++] = buckets[i]->arr[j];
        }
    }

    // Free buckets
    for (int i = 0; i < bucketCount; i++) {
        free(buckets[i]->arr);
        free(buckets[i]);
    }
    free(buckets);
}

// Print an array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Get the input array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    // Free the array
    free(arr);

    return 0;
}