//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_NUMBERS 1000
#define NUM_BUCKETS 10

// Structure to hold the data needed by each thread
typedef struct {
    int *bucket;       // The bucket to sort
    int size;          // The size of the bucket
} BucketInfo;

// Function prototype
void *sortBucket(void *arg);
void bucketSort(int *array, int n);

int main() {
    int n, i;
    int *array;

    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);

    // Allocate memory for the input array
    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Fill the array with random numbers
    printf("Randomly generated numbers:\n");
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100; // Random numbers in range [0, 99]
        printf("%d ", array[i]);
    }
    printf("\n");

    // Perform bucket sort
    bucketSort(array, n);

    // Print the sorted array
    printf("Sorted numbers:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);
    return 0;
}

// Function to perform the sorting of each bucket
void *sortBucket(void *arg) {
    BucketInfo *info = (BucketInfo *)arg;
    int *bucket = info->bucket;
    int size = info->size;

    // Insertion sort for the bucket
    for (int i = 1; i < size; i++) {
        int key = bucket[i];
        int j = i - 1;
        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }
    pthread_exit(0);
}

// Bucket sort function
void bucketSort(int *array, int n) {
    int i, j;
    int buckets[NUM_BUCKETS][MAX_NUMBERS];
    int bucketSizes[NUM_BUCKETS] = {0};

    // Distribution of input array elements into buckets
    for (i = 0; i < n; i++) {
        int bucketIndex = array[i] / (100 / NUM_BUCKETS);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = array[i];
    }

    // Create threads for sorting each bucket
    pthread_t threads[NUM_BUCKETS];
    BucketInfo bucketInfos[NUM_BUCKETS];

    for (i = 0; i < NUM_BUCKETS; i++) {
        bucketInfos[i].bucket = buckets[i];
        bucketInfos[i].size = bucketSizes[i];

        // Only create a thread if the bucket has elements
        if (bucketSizes[i] > 0) {
            pthread_create(&threads[i], NULL, sortBucket, (void *)&bucketInfos[i]);
        }
    }

    // Wait for all threads to complete
    for (i = 0; i < NUM_BUCKETS; i++) {
        if (bucketSizes[i] > 0) {
            pthread_join(threads[i], NULL);
        }
    }

    // Merge sorted buckets back into the original array
    j = 0;
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (int k = 0; k < bucketSizes[i]; k++) {
            array[j++] = buckets[i][k];
        }
    }
}