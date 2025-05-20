//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the number of threads
#define NUM_THREADS 4

// Define the shared data structure
typedef struct {
    int data[10];
    int index;
} shared_data_t;

// Define the thread function
void *thread_function(void *arg) {
    int thread_id = *(int *)arg;
    shared_data_t *data = (shared_data_t *)malloc(sizeof(shared_data_t));

    // Initialize the shared data
    for (int i = 0; i < 10; i++) {
        data->data[i] = 0;
    }

    // Update the shared data
    for (int i = 0; i < 100; i++) {
        data->data[thread_id]++;
    }

    // Print the thread ID and the updated shared data
    printf("Thread %d updated the shared data:\n", thread_id);
    for (int i = 0; i < 10; i++) {
        printf("%d ", data->data[i]);
    }
    printf("\n");

    // Free the shared data
    free(data);

    return NULL;
}

// Define the main function
int main() {
    // Create the threads
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2, 3};
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}