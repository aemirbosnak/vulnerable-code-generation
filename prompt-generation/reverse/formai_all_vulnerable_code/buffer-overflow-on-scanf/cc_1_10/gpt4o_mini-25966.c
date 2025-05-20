//GPT-4o-mini DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_BUCKETS 10
#define MAX_NUMBERS 1000
#define MAX_THREADS 4

typedef struct {
    int *arr;
    int size;
    int thread_id;
    int *buckets[NUM_BUCKETS];
    int bucket_sizes[NUM_BUCKETS];
} ThreadData;

void *bucket_sort(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int i, j;
    
    // Initialize bucket sizes
    for (i = 0; i < NUM_BUCKETS; i++) {
        data->bucket_sizes[i] = 0;
        data->buckets[i] = malloc(MAX_NUMBERS * sizeof(int));
    }

    // Place numbers into buckets
    for (i = data->thread_id; i < data->size; i += MAX_THREADS) {
        int index = data->arr[i] * NUM_BUCKETS / 100; // Scale to bucket indexing
        if (index >= NUM_BUCKETS) index = NUM_BUCKETS - 1; // Handle edge case
        data->buckets[index][data->bucket_sizes[index]++] = data->arr[i];
    }

    pthread_exit(0);
}

void insertion_sort(int *arr, int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void collect_and_sort_buckets(ThreadData *data, int *sorted_array, int *sorted_index) {
    for (int i = 0; i < NUM_BUCKETS; i++) {
        insertion_sort(data->buckets[i], data->bucket_sizes[i]);
        for (int j = 0; j < data->bucket_sizes[i]; j++) {
            sorted_array[(*sorted_index)++] = data->buckets[i][j];
        }
    }
}

int main() {
    int arr[MAX_NUMBERS];
    int sorted_array[MAX_NUMBERS];
    int n, i;

    // Randomly generating numbers
    printf("Enter the number of elements (max %d): ", MAX_NUMBERS);
    scanf("%d", &n);
    if (n > MAX_NUMBERS) {
        printf("Exceeds maximum limit of %d.\n", MAX_NUMBERS);
        return 1;
    }

    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Range between 0-99
    }

    pthread_t threads[MAX_THREADS];
    ThreadData thread_data[MAX_THREADS];
    int sorted_index = 0;

    // Create threads
    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].arr = arr;
        thread_data[i].size = n;
        thread_data[i].thread_id = i;
        pthread_create(&threads[i], NULL, bucket_sort, (void *)&thread_data[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Collect results
    collect_and_sort_buckets(thread_data, sorted_array, &sorted_index);

    // Print sorted array
    printf("Sorted Array: \n");
    for (i = 0; i < n; i++) {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    // Free allocated memory
    for (i = 0; i < MAX_THREADS; i++) {
        for (int j = 0; j < NUM_BUCKETS; j++) {
            free(thread_data[i].buckets[j]);
        }
    }

    return 0;
}