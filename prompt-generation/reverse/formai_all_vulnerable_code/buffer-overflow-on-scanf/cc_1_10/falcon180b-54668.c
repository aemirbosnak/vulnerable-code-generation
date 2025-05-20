//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10

// Mutex for synchronization
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for signaling threads
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Array to store Fibonacci numbers
long long int fib_array[MAX_THREADS];

// Function to calculate Fibonacci sequence
void *fibonacci(void *arg) {
    int thread_id = *(int *) arg;
    long long int prev = 0, curr = 1, temp;

    pthread_mutex_lock(&mutex);
    // Wait for the previous thread to complete
    pthread_cond_wait(&cond, &mutex);

    // Calculate the Fibonacci number for this thread
    for (int i = 2; i <= thread_id; i++) {
        temp = curr;
        curr += prev;
        prev = temp;
    }

    // Store the result in the array
    fib_array[thread_id - 1] = curr;

    // Signal the next thread
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    int num_threads;
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Create threads
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];
    for (int i = 0; i < num_threads; i++) {
        ids[i] = i + 1; // Thread IDs start from 1
        pthread_create(&threads[i], NULL, fibonacci, (void *) &ids[i]);
    }

    // Join threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the Fibonacci sequence
    printf("Fibonacci sequence:\n");
    for (int i = 0; i < num_threads; i++) {
        printf("%lld ", fib_array[i]);
    }

    return 0;
}