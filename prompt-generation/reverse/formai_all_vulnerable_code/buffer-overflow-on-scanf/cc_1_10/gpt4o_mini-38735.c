//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50
#define BUCKET_COUNT 10 // Number of buckets 

// A structure to represent a bucket
typedef struct Bucket {
    int *array;
    int size;
    int capacity;
} Bucket;

// Function to create a bucket
Bucket* createBucket(int capacity) {
    Bucket *bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->capacity = capacity;
    bucket->size = 0;
    bucket->array = (int *)malloc(capacity * sizeof(int));
    return bucket;
}

// Function to add an element to the bucket
void addToBucket(Bucket *bucket, int value) {
    if (bucket->size == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->array = (int *)realloc(bucket->array, bucket->capacity * sizeof(int));
    }
    bucket->array[bucket->size++] = value;
}

// Function to perform insertion sort on a bucket
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
    if (n <= 0) return;

    // Create buckets
    Bucket **buckets = (Bucket **)malloc(BUCKET_COUNT * sizeof(Bucket *));
    for (int i = 0; i < BUCKET_COUNT; i++) {
        buckets[i] = createBucket(1);
    }

    // Add elements into buckets
    for (int i = 0; i < n; i++) {
        int index = array[i] * BUCKET_COUNT / (100 + 1); // Assuming max value is 100
        addToBucket(buckets[index], array[i]);
    }

    // Sort each bucket and collect the sorted values
    int index = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        sortBucket(buckets[i]);
        for (int j = 0; j < buckets[i]->size; j++) {
            array[index++] = buckets[i]->array[j];
        }
        free(buckets[i]->array);
        free(buckets[i]);
    }

    free(buckets);
}

// Function to print the array
void printArray(int *array, int n) {
    printf("Sorted Array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n;
    printf("Welcome to the Magical World of Bucket Sorting!\n");
    printf("Enter the total number of elements you wish to sort: ");
    scanf("%d", &n);

    // Create an array to hold the input values
    int *array = (int *)malloc(n * sizeof(int));
    printf("Enter %d integers (between 0 and 100):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Perform bucket sort
    bucketSort(array, n);
    
    // Print the sorted array
    printArray(array, n);

    // Clean up dynamically allocated memory
    free(array);
    
    printf("The stars have aligned your numbers and they are now sorted! 🌟\n");
    return 0;
}