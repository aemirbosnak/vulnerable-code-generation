//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 4

// Define the shared data structure
typedef struct {
    int *data;
    int size;
} shared_data_t;

// Function to be executed by each thread
void *sum_elements(void *arg) {
    int thread_id = *(int *) arg;
    shared_data_t *shared_data = (shared_data_t *) malloc(sizeof(shared_data_t));
    shared_data->data = (int *) malloc(sizeof(int) * 10);
    shared_data->size = 10;

    // Initialize the shared data with random values
    for (int i = 0; i < shared_data->size; i++) {
        shared_data->data[i] = rand() % 100;
    }

    // Sum the elements in the shared data
    int sum = 0;
    for (int i = 0; i < shared_data->size; i++) {
        sum += shared_data->data[i];
    }

    // Print the result
    printf("Thread %d: Sum of elements in shared data is %d\n", thread_id, sum);

    // Free the shared data
    free(shared_data->data);
    free(shared_data);

    return NULL;
}

int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Create the threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {1, 2, 3, 4};
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, sum_elements, (void *) &thread_ids[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}