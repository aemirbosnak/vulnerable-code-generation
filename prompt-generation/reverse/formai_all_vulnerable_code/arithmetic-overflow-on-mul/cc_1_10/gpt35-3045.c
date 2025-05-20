//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_PROBABILITY 100
#define MIN_PROBABILITY 1

int invade_probability = 0;
pthread_mutex_t mutex;

void* calculate_probability(void* thread_id) {
    int id = *(int*) thread_id;

    // Generate a random probability between 1 and 100
    srand(time(NULL) * id);
    int probability = (rand() % (MAX_PROBABILITY - MIN_PROBABILITY + 1)) + MIN_PROBABILITY;

    // Lock the mutex to prevent race conditions
    pthread_mutex_lock(&mutex);

    printf("Thread %d calculated an invasion probability of %d\n", id, probability);

    // If this thread has the highest probability so far, update the global invade_probability
    if (probability > invade_probability) {
        invade_probability = probability;
    }

    // Unlock the mutex so other threads can access the global invade_probability variable
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, calculate_probability, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("The highest calculated invasion probability is: %d\n", invade_probability);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}