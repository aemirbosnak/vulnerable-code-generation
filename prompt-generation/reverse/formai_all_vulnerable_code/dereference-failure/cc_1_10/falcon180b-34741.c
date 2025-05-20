//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ELEMENTS 1000000

// Function to sort a single bucket
void* sort_bucket(void* arg) {
    int* bucket = (int*) arg;
    int n = 0;
    int i, j, temp;

    // Count the number of elements in the bucket
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (bucket[i]!= 0) {
            n++;
        }
    }

    // Sort the bucket using insertion sort
    for (i = 1; i < n; i++) {
        j = i;
        temp = bucket[i];

        while (j > 0 && bucket[j - 1] > temp) {
            bucket[j] = bucket[j - 1];
            j--;
        }

        bucket[j] = temp;
    }

    return NULL;
}

// Function to perform bucket sort
void bucket_sort(int* arr, int size) {
    pthread_t threads[MAX_ELEMENTS];
    int* buckets = (int*) malloc(MAX_ELEMENTS * sizeof(int));
    int bucket_size = MAX_ELEMENTS / size;
    int i, j, index;

    // Initialize all buckets to 0
    for (i = 0; i < MAX_ELEMENTS; i++) {
        buckets[i] = 0;
    }

    // Distribute elements into buckets
    for (i = 0; i < size; i++) {
        index = arr[i] / bucket_size;
        buckets[index]++;
    }

    // Sort each bucket using a separate thread
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (buckets[i]!= 0) {
            pthread_create(&threads[i], NULL, sort_bucket, (void*) &arr[i * bucket_size]);
        }
    }

    // Join all threads
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (buckets[i]!= 0) {
            pthread_join(threads[i], NULL);
        }
    }

    free(buckets);
}

// Main function
int main() {
    int* arr = (int*) malloc(MAX_ELEMENTS * sizeof(int));
    int size = 100000;

    // Initialize array with random values
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX_ELEMENTS;
    }

    // Perform bucket sort
    bucket_sort(arr, size);

    // Print sorted array
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}