//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex for thread synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for thread synchronization
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Global variable for thread ID
int thread_id;

// Function to be executed by each thread
void* thread_func(void* param) {
    int id = *(int*)param;
    printf("Thread %d started\n", id);

    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Signal the main thread that a new thread has been created
    pthread_cond_signal(&cond);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    // Sleep for a random amount of time
    usleep(rand() % 1000000);

    printf("Thread %d finished\n", id);
    return NULL;
}

// Main function
int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create an array of thread IDs
    pthread_t threads[num_threads];

    // Create the specified number of threads
    for (int i = 0; i < num_threads; i++) {
        int* id_ptr = malloc(sizeof(int));
        *id_ptr = i;
        pthread_create(&threads[i], NULL, thread_func, id_ptr);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}