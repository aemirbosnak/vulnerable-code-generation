//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

// Mutex for critical section
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for synchronization
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;

// Array to store data
int data[MAX_THREADS];

// Number of threads
int num_threads;

// Function to be executed by each thread
void* thread_func(void* arg) {
    int thread_num = *(int*) arg;
    int i;

    // Lock mutex
    pthread_mutex_lock(&mutex);

    // Notify main thread that this thread is ready to start
    pthread_cond_signal(&cond_var);

    // Wait for main thread to signal start
    pthread_cond_wait(&cond_var, &mutex);

    // Critical section
    for (i = thread_num; i < MAX_THREADS; i += num_threads) {
        data[i] = i;
    }

    // Unlock mutex
    pthread_mutex_unlock(&mutex);

    // Exit thread
    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];
    int thread_num;

    // Get number of threads from user
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    // Create threads
    for (i = 0; i < num_threads; i++) {
        thread_num = i;
        pthread_create(&threads[i], NULL, thread_func, &thread_num);
    }

    // Join threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print data array
    printf("Data array:\n");
    for (i = 0; i < MAX_THREADS; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}