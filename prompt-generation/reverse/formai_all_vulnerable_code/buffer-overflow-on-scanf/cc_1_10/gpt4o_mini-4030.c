//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define BUCKET_SIZE 10
#define MAX_NUMBERS 100

typedef struct {
    int *bucket;     // Pointer to the bucket array
    int count;       // Count of numbers in the bucket
} Bucket;

// Function declarations
void* sort_bucket(void* arg);
void bucket_sort(int *arr, int n);
void print_array(int *arr, int n);

// Main program entry
int main() {
    int arr[MAX_NUMBERS];
    int n;

    // Generate random numbers
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);

    if (n > MAX_NUMBERS) {
        printf("Exceeded maximum element limit.\n");
        return 1;
    }

    printf("Generating %d random numbers...\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000; // Random numbers between 0-999
    }

    printf("Unsorted Array:\n");
    print_array(arr, n);

    bucket_sort(arr, n);

    printf("Sorted Array:\n");
    print_array(arr, n);

    return 0;
}

// Function to sort bucket using pthreads
void* sort_bucket(void* arg) {
    Bucket *bucket_data = (Bucket*)arg;
    int count = bucket_data->count;
    int *bucket = bucket_data->bucket;

    // Simple insertion sort for the bucket
    for (int i = 1; i < count; i++) {
        int key = bucket[i];
        int j = i - 1;

        while (j >= 0 && bucket[j] > key) {
            bucket[j + 1] = bucket[j];
            j--;
        }
        bucket[j + 1] = key;
    }

    pthread_exit(NULL);
}

// Function to perform bucket sort
void bucket_sort(int *arr, int n) {
    if (n <= 0) return;

    Bucket buckets[BUCKET_SIZE]; 
    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i].bucket = (int*)malloc(n * sizeof(int)); // Allocate memory for buckets
        buckets[i].count = 0;
    }

    // Distribute input array values into buckets
    for (int i = 0; i < n; i++) {
        int index = arr[i] / (1000 / BUCKET_SIZE); // Determine bucket index
        if (index >= BUCKET_SIZE) {
            index = BUCKET_SIZE - 1;
        }
        buckets[index].bucket[buckets[index].count++] = arr[i];
    }

    pthread_t threads[BUCKET_SIZE];

    // Create threads to sort each bucket
    for (int i = 0; i < BUCKET_SIZE; i++) {
        pthread_create(&threads[i], NULL, sort_bucket, (void*)&buckets[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < BUCKET_SIZE; i++) {
        pthread_join(threads[i], NULL);
    }

    // Collect sorted values back into arr
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[index++] = buckets[i].bucket[j];
        }
        free(buckets[i].bucket); // Free memory used by buckets
    }
}

// Function to print array
void print_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}