//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_BUCKETS 10
#define MAX_NUMBERS 100
#define MAX_STRING_LENGTH 50

// Bucket structure
typedef struct Bucket {
    int *elements;
    int size;
    int capacity;
} Bucket;

// Function prototypes
Bucket* createBucket(int capacity);
void addElement(Bucket *bucket, int element);
void sortBucket(Bucket *bucket);
void bucketSort(int *array, int n);
void printArray(int *array, int n);
void freeBuckets(Bucket **buckets, int numberOfBuckets);

int main() {
    int array[MAX_NUMBERS];
    int n;

    printf("Enter the number of elements to sort (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array:\n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Sorted array:\n");
    printArray(array, n);
    
    return 0;
}

Bucket* createBucket(int capacity) {
    Bucket* bucket = (Bucket *)malloc(sizeof(Bucket));
    bucket->capacity = capacity;
    bucket->size = 0;
    bucket->elements = (int *)malloc(sizeof(int) * capacity);
    return bucket;
}

void addElement(Bucket *bucket, int element) {
    if (bucket->size == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->elements = (int *)realloc(bucket->elements, sizeof(int) * bucket->capacity);
    }
    bucket->elements[bucket->size++] = element;
}

void sortBucket(Bucket *bucket) {
    for (int i = 0; i < bucket->size - 1; i++) {
        for (int j = 0; j < bucket->size - i - 1; j++) {
            if (bucket->elements[j] > bucket->elements[j + 1]) {
                int temp = bucket->elements[j];
                bucket->elements[j] = bucket->elements[j + 1];
                bucket->elements[j + 1] = temp;
            }
        }
    }
}

void bucketSort(int *array, int n) {
    Bucket **buckets = (Bucket **)malloc(NUM_BUCKETS * sizeof(Bucket *));
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = createBucket(5); // Initial capacity of 5
    }

    // Distribute input array elements into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = array[i] / (MAX_NUMBERS / NUM_BUCKETS);
        bucketIndex = bucketIndex >= NUM_BUCKETS ? NUM_BUCKETS - 1 : bucketIndex;
        addElement(buckets[bucketIndex], array[i]);
    }

    // Sort each bucket
    for (int i = 0; i < NUM_BUCKETS; i++) {
        sortBucket(buckets[i]);
    }

    // Concatenate sorted buckets back into original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        for (int j = 0; j < buckets[i]->size; j++) {
            array[index++] = buckets[i]->elements[j];
        }
    }

    // Free memory
    freeBuckets(buckets, NUM_BUCKETS);
}

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void freeBuckets(Bucket **buckets, int numberOfBuckets) {
    for (int i = 0; i < numberOfBuckets; i++) {
        free(buckets[i]->elements);
        free(buckets[i]);
    }
    free(buckets);
}