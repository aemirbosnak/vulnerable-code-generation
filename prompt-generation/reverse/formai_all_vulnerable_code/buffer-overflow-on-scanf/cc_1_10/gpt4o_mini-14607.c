//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

// Function to create a bucket
struct Bucket {
    int* arr;
    int count;
};

// Function to create a new bucket with a given size
struct Bucket* createBucket(int size) {
    struct Bucket* bucket = (struct Bucket*)malloc(sizeof(struct Bucket));
    bucket->arr = (int*)malloc(sizeof(int) * size);
    bucket->count = 0;
    return bucket;
}

// Function to insert an element into the bucket
void insertIntoBucket(struct Bucket* bucket, int value) {
    bucket->arr[bucket->count++] = value;
}

// Recursive function to sort individual buckets using insertion sort
void insertionSort(int* arr, int n) {
    if (n <= 1) return;  // Base case
    insertionSort(arr, n - 1);  // Recursive call
    int last = arr[n - 1];
    int j = n - 2;
    
    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;  // Insert last at the correct place
}

// Function to perform bucket sort
void bucketSort(int* arr, int n) {
    if (n <= 0) return; // Base case for empty array

    struct Bucket* buckets[BUCKET_SIZE];
    for (int i = 0; i < BUCKET_SIZE; ++i) {
        buckets[i] = createBucket(n);  // Create empty buckets
    }

    // Distribute input array elements into buckets
    for (int i = 0; i < n; ++i) {
        int index = arr[i] * BUCKET_SIZE / (n + 1);  // Simple hash function
        insertIntoBucket(buckets[index], arr[i]);
    }

    // Sort each bucket individually
    for (int i = 0; i < BUCKET_SIZE; ++i) {
        if (buckets[i]->count > 0) {
            insertionSort(buckets[i]->arr, buckets[i]->count);
        }
    }

    // Concatenate buckets into the array
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; ++i) {
        for (int j = 0; j < buckets[i]->count; ++j) {
            arr[index++] = buckets[i]->arr[j];
        }
        free(buckets[i]->arr); // Free allocated bucket array
        free(buckets[i]); // Free bucket structure
    }
}

// Driver function to test the bucket sort implementation
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Number of elements should be greater than zero.\n");
        return 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free allocated memory for the array
    return 0;
}