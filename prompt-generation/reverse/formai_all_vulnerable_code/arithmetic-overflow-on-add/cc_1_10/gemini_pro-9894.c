//GEMINI-pro DATASET v1.0 Category: Threading Library Implementation ; Style: puzzling
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 10

pthread_t threads[NUM_THREADS];

int shared_data = 0;

// A mutex ensures that only one thread can access shared data at a time
pthread_mutex_t mutex;

void* thread_function(void* arg) {
    // Initialize the random number generator for this thread
    srand(time(NULL) + (int) arg);

    while (1) {
        // Acquire the mutex lock
        pthread_mutex_lock(&mutex);

        // Increment the shared data by a random amount
        shared_data += rand() % 10;

        // Release the mutex lock
        pthread_mutex_unlock(&mutex);

        // Sleep for a random amount of time
        sleep(rand() % 5);
    }

    return NULL;
}

int main(int argc, char** argv) {
    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void*) i);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    // Print the final value of the shared data
    printf("Final value of shared data: %d\n", shared_data);

    return 0;
}