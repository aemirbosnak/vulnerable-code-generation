//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10
#define MAX_NUMBERS 1000

// A structure to represent a single bucket
typedef struct Bucket {
    int *array; // Pointer to the array for this bucket
    int size;   // Current size of the bucket
} Bucket;

// Function to initialize a bucket
Bucket* createBucket() {
    Bucket* bucket = (Bucket*)malloc(sizeof(Bucket));
    bucket->array = (int*)malloc(BUCKET_SIZE * sizeof(int));
    bucket->size = 0;
    return bucket;
}

// Function to add an element to a bucket
void addToBucket(Bucket* bucket, int value) {
    if (bucket->size < BUCKET_SIZE) {
        bucket->array[bucket->size++] = value;
    } else {
        // If the bucket is full, we need to resize it
        bucket->array = (int*)realloc(bucket->array, (bucket->size + 1) * sizeof(int));
        bucket->array[bucket->size++] = value;
    }
}

// Function to sort a bucket using insertion sort
void sortBucket(Bucket* bucket) {
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
void bucketSort(int* arr, int n) {
    // Create buckets
    Bucket** buckets = (Bucket**)malloc(BUCKET_SIZE * sizeof(Bucket*));
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = createBucket();
    }

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / BUCKET_SIZE;
        addToBucket(buckets[index], arr[i]);
    }

    // Sort each bucket and gather the results
    int sortedIndex = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        sortBucket(buckets[i]);
        for (int j = 0; j < buckets[i]->size; j++) {
            arr[sortedIndex++] = buckets[i]->array[j];
        }
    }

    // Free buckets
    for (int i = 0; i < BUCKET_SIZE; i++) {
        free(buckets[i]->array);
        free(buckets[i]);
    }
    free(buckets);
}

// Function to print an array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int arr[MAX_NUMBERS];
    int n;

    printf("Enter number of elements to sort (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n > MAX_NUMBERS) {
        printf("Error: Number of elements exceeds the maximum allowed (%d).\n", MAX_NUMBERS);
        return 1;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}