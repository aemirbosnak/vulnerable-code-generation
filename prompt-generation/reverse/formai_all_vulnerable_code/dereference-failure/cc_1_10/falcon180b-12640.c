//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

// Mutex for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for synchronization
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

// Function to be executed by each thread
void *thread_function(void *arg) {
    int id = *(int *) arg;
    printf("Thread %d started\n", id);

    // Lock the mutex before waiting on the condition variable
    pthread_mutex_lock(&mutex);

    // Wait on the condition variable until signaled
    pthread_cond_wait(&condition, &mutex);

    // Unlock the mutex after waiting on the condition variable
    pthread_mutex_unlock(&mutex);

    printf("Thread %d finished\n", id);
    return NULL;
}

int main() {
    int num_threads = 5;
    pthread_t threads[num_threads];

    // Create each thread
    for (int i = 0; i < num_threads; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, thread_function, id);
    }

    // Signal each thread to start execution
    for (int i = 0; i < num_threads; i++) {
        pthread_cond_signal(&condition);
    }

    // Wait for each thread to finish execution
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}