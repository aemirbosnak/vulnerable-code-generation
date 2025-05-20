//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKET_SIZE 10
#define MAX_NUMBERS 1000

typedef struct Bucket {
    int *array;
    int size;
} Bucket;

void initBuckets(Bucket *buckets, int size) {
    for (int i = 0; i < size; i++) {
        buckets[i].array = (int *)malloc(MAX_NUMBERS * sizeof(int));
        if (buckets[i].array == NULL) {
            fprintf(stderr, "Memory allocation failed for bucket %d\n", i);
            exit(EXIT_FAILURE);
        }
        buckets[i].size = 0;
    }
}

void freeBuckets(Bucket *buckets, int size) {
    for (int i = 0; i < size; i++) {
        free(buckets[i].array);
    }
}

void insertIntoBucket(Bucket *bucket, int value) {
    bucket->array[bucket->size] = value;
    bucket->size++;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void bucketSort(int *array, int n) {
    if (n <= 0) return;

    Bucket buckets[BUCKET_SIZE];
    initBuckets(buckets, BUCKET_SIZE);

    // Find the maximum value in input array
    int maxValue = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxValue) {
            maxValue = array[i];
        }
    }

    // Bucket sorting
    int range = (maxValue + 1) / BUCKET_SIZE;
    for (int i = 0; i < n; i++) {
        int bucketIndex = array[i] / range;
        if (bucketIndex >= BUCKET_SIZE) {
            bucketIndex = BUCKET_SIZE - 1; // Ensure we don't go out of bounds
        }
        insertIntoBucket(&buckets[bucketIndex], array[i]);
    }

    // Sort individual buckets and merge
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        if (buckets[i].size > 0) {
            qsort(buckets[i].array, buckets[i].size, sizeof(int), compare);
            memcpy(array + index, buckets[i].array, buckets[i].size * sizeof(int));
            index += buckets[i].size;
        }
    }

    freeBuckets(buckets, BUCKET_SIZE);
}

void printArray(int *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        fprintf(stderr, "Invalid number of elements!\n");
        return EXIT_FAILURE;
    }

    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Unsorted array:\n");
    printArray(array, n);
    
    bucketSort(array, n);
    
    printf("Sorted array:\n");
    printArray(array, n);

    free(array);
    return EXIT_SUCCESS;
}