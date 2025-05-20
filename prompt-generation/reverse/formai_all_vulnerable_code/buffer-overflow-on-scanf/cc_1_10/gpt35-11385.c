//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: configurable
// Configurable C Threading Library Implementation Example
// This program creates a configurable number of threads that increment a global counter
// The number of threads and the value to increment the counter can be configured at runtime
// The program uses a mutex lock to ensure thread safety

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;
pthread_mutex_t lock;

void* thread_increment(void* arg) {
    int increment_value = *(int*) arg;
    pthread_mutex_lock(&lock);
    counter += increment_value;
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    int num_threads;
    int increment_value;

    // Get user input for number of threads and increment value
    printf("Enter the number of threads to create: ");
    scanf("%d",&num_threads);
    printf("Enter the value to increment the counter by: ");
    scanf("%d",&increment_value);

    // Initialize the mutex lock
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex lock initialization failed\n");
        return 1;
    }

    // Allocate memory for array of thread IDs
    pthread_t* thread_ids = (pthread_t*) malloc(num_threads * sizeof(pthread_t));
    if (thread_ids == NULL) {
        printf("Failed to allocate memory for thread IDs\n");
        return 1;
    }

    // Create threads
    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&thread_ids[i], NULL, thread_increment, &increment_value) != 0) {
            printf("Failed to create thread %d\n",i);
            return 1;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(thread_ids[i], NULL) != 0) {
            printf("Failed to join thread %d\n",i);
            return 1;
        }
    }

    // Destroy the mutex lock
    pthread_mutex_destroy(&lock);

    // Output final value of counter
    printf("Final counter value is: %d\n",counter);

    // Free the memory allocated for thread IDs
    free(thread_ids);

    return 0;
}