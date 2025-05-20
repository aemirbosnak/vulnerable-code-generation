//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for signaling between threads
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Number of threads
#define NUM_THREADS 10

// Data structure for passing data between threads
typedef struct {
    int id;
    int *data;
} thread_data_t;

// Function to be executed by each thread
void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;

    // Lock mutex before entering critical section
    pthread_mutex_lock(&mutex);

    // Signal to other threads that this thread is done with critical section
    pthread_cond_signal(&cond);

    // Unlock mutex after exiting critical section
    pthread_mutex_unlock(&mutex);

    // Do some work here...

    // Exit thread
    return NULL;
}

int main() {
    // Create an array of thread data structures
    thread_data_t data[NUM_THREADS];

    // Initialize random seed
    srand(time(NULL));

    // Populate thread data structures with random IDs and pointers to shared data
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].id = rand() % 100;
        data[i].data = malloc(sizeof(int));
        *data[i].data = rand() % 100;
    }

    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_function, &data[i]);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free memory
    for (int i = 0; i < NUM_THREADS; i++) {
        free(data[i].data);
    }

    return 0;
}