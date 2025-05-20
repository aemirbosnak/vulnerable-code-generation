//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4
#define NUM_BUCKETS 10

typedef struct {
    int *array;
    int size;
} bucket_t;

void *bucket_sort(void *arg) {
    bucket_t *bucket = (bucket_t *)arg;
    int i, j;

    // Sort the bucket using insertion sort
    for (i = 1; i < bucket->size; i++) {
        int key = bucket->array[i];
        j = i - 1;

        while (j >= 0 && bucket->array[j] > key) {
            bucket->array[j + 1] = bucket->array[j];
            j--;
        }

        bucket->array[j + 1] = key;
    }

    return NULL;
}

int main() {
    int i, j;
    int num_elements;
    int *array;
    bucket_t buckets[NUM_BUCKETS];

    // Get the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    // Allocate memory for the array
    array = malloc(num_elements * sizeof(int));

    // Get the elements
    printf("Enter the elements: ");
    for (i = 0; i < num_elements; i++) {
        scanf("%d", &array[i]);
    }

    // Create the buckets
    for (i = 0; i < NUM_BUCKETS; i++) {
        buckets[i].array = malloc(num_elements * sizeof(int));
        buckets[i].size = 0;
    }

    // Distribute the elements into the buckets
    for (i = 0; i < num_elements; i++) {
        int bucket_index = array[i] / NUM_BUCKETS;
        buckets[bucket_index].array[buckets[bucket_index].size++] = array[i];
    }

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, bucket_sort, &buckets[i]);
    }

    // Join the threads
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Concatenate the buckets
    int index = 0;
    for (i = 0; i < NUM_BUCKETS; i++) {
        for (j = 0; j < buckets[i].size; j++) {
            array[index++] = buckets[i].array[j];
        }

        free(buckets[i].array);
    }

    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < num_elements; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    free(array);

    return 0;
}