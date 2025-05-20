//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 1000 // Maximum value for elements to be sorted
#define NUM_BUCKETS 10 // Number of buckets

// Structure for a bucket containing a dynamic array
typedef struct {
    int *array;
    int size;
    int capacity;
} Bucket;

// Function to initialize a bucket
Bucket* createBucket(int capacity) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->array = (int *)malloc(capacity * sizeof(int));
    bucket->size = 0;
    bucket->capacity = capacity;
    return bucket;
}

// Function to insert an element into a bucket
void insertBucket(Bucket *bucket, int value) {
    if (bucket->size >= bucket->capacity) {
        bucket->capacity *= 2;
        bucket->array = (int *)realloc(bucket->array, bucket->capacity * sizeof(int));
    }
    bucket->array[bucket->size++] = value;
}

// Function to sort a bucket using insertion sort
void sortBucket(Bucket *bucket) {
    for (int i = 1; i < bucket->size; i++) {
        int key = bucket->array[i];
        int j = i - 1;
        while (j >= 0 && bucket->array[j] > key) {
            bucket->array[j + 1] = bucket->array[j];
            j--;
        }
        bucket->array[j + 1] = key;
    }
}

// Function to perform bucket sort
void bucketSort(int *array, int n) {
    // Create buckets
    Bucket **buckets = (Bucket **)malloc(NUM_BUCKETS * sizeof(Bucket *));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = createBucket(10); // Start with capacity of 10
    }

    // Place array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = (array[i] * NUM_BUCKETS) / (MAX_VALUE + 1); // Calculate the bucket index
        insertBucket(buckets[index], array[i]);
    }

    // Sort each bucket and merge the results
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        sortBucket(buckets[i]);
        for (int j = 0; j < buckets[i]->size; j++) {
            array[index++] = buckets[i]->array[j];
        }
        free(buckets[i]->array); // Free the bucket array
        free(buckets[i]); // Free the bucket structure
    }

    free(buckets); // Free the buckets array
}

// Function to print the array
void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Dynamic input for the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Array size must be greater than 0.\n");
        return 1;
    }

    int *array = (int *)malloc(n * sizeof(int));

    // Dynamic input of array elements
    printf("Enter the elements of the array (0 to %d):\n", MAX_VALUE);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] < 0 || array[i] > MAX_VALUE) {
            printf("Please enter numbers within the range [0, %d].\n", MAX_VALUE);
            free(array);
            return 1;
        }
    }

    // Display the unsorted array
    printf("Unsorted array:\n");
    printArray(array, n);

    // Perform bucket sort
    bucketSort(array, n);

    // Display the sorted array
    printf("Sorted array:\n");
    printArray(array, n);

    // Free the allocated memory
    free(array);

    return 0;
}