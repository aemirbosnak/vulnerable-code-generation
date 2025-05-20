//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_STRING_LENGTH 100

// Mutex for critical section
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for threads to wait on
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

// Array of strings
char strings[MAX_THREADS][MAX_STRING_LENGTH];

// Number of threads
int num_threads;

// Function to be executed by each thread
void *thread_function(void *arg) {
    int thread_id = *(int *) arg;
    char *string = &strings[thread_id][0];

    // Add your string manipulation code here

    pthread_mutex_lock(&lock);
    printf("Thread %d finished\n", thread_id);
    pthread_cond_signal(&condition);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    // Get number of threads from user
    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    // Initialize strings array
    for (i = 0; i < num_threads; i++) {
        strings[i][0] = '\0';
    }

    // Create threads
    for (i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, thread_function, (void *) &i);
    }

    // Wait for all threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}