//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Shared variables
int next_term;
int num_threads;
int n;

// Mutex to protect shared variables
pthread_mutex_t mutex;

// Function to calculate the next Fibonacci term
void *calculate_next_term(void *arg) {
    // Get the thread ID
    int tid = *(int *)arg;

    // Calculate the next Fibonacci term
    int term;
    if (tid == 0) {
        term = 0;
    } else if (tid == 1) {
        term = 1;
    } else {
        pthread_mutex_lock(&mutex);
        term = next_term + *(int *)arg;
        next_term = *(int *)arg;
        pthread_mutex_unlock(&mutex);
    }

    // Print the result
    printf("Thread %d: %d\n", tid, term);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Get the number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Get the number of Fibonacci terms
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    // Initialize the shared variables
    next_term = 0;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, calculate_next_term, (void *)&i);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}