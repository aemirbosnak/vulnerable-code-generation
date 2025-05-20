//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: statistical
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 10

// Structure to hold thread-specific data
typedef struct {
    int thread_id;
    int sum;
} thread_data_t;

// Thread function
void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;

    // Calculate the sum of the numbers from 1 to 100
    for (int i = 1; i <= 100; i++) {
        data->sum += i;
    }

    // Print the thread ID and the sum
    printf("Thread %d: sum = %d\n", data->thread_id, data->sum);

    return NULL;
}

int main() {
    // Create thread data structures
    thread_data_t data[NUM_THREADS];

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i;
        if (pthread_create(&threads[i], NULL, thread_function, &data[i]) != 0) {
            perror("pthread_create");
            return EXIT_FAILURE;
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}