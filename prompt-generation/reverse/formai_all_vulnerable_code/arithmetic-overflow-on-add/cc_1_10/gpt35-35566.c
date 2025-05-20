//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

// Define constants
#define NUM_THREADS 4
#define GRID_SIZE 100
#define ITERATIONS 1000000

// Define shared variables
double invasion_probability = 0;
volatile int completed_threads = 0;
pthread_mutex_t mutex;

// Define thread function
void* calculate_invasion_probability(void* thread_ID) {
    int ID = *(int*) thread_ID;
    double local_probability = 0;
    srand(time(NULL) + ID);

    for (int i = 0; i < ITERATIONS/NUM_THREADS; i++) {
        int x = rand() % GRID_SIZE;
        int y = rand() % GRID_SIZE;

        if (x < GRID_SIZE/10 && y < GRID_SIZE/10) {
            local_probability++;
        }
    }

    // Update shared probability
    pthread_mutex_lock(&mutex);
    invasion_probability += local_probability / (ITERATIONS/NUM_THREADS);
    completed_threads++;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Initialize threads
    pthread_t threads[NUM_THREADS];
    int thread_IDs[NUM_THREADS];

    // Start threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_IDs[i] = i;
        pthread_create(&threads[i], NULL, calculate_invasion_probability, (void*) &thread_IDs[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy mutex
    pthread_mutex_destroy(&mutex);

    // Print results
    printf("Alien Invasion Probability: %.2f%%\n", invasion_probability*100);
    printf("Completed threads: %d\n", completed_threads);

    return 0;
}