//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

// Global variables
int num_threads;
int num_simulations;
int num_invasions;
pthread_mutex_t lock;

// Function to simulate an alien invasion
void *simulate_invasion(void *arg) {
    // Get the thread ID
    int thread_id = *(int *)arg;

    // Initialize the random number generator
    srand(time(NULL) + thread_id);

    // Run the simulations
    for (int i = 0; i < num_simulations; i++) {
        // Generate a random number between 0 and 1
        double random_number = (double)rand() / (double)RAND_MAX;

        // Check if the random number is less than the probability of invasion
        if (random_number < 0.01) {
            // Increment the number of invasions
            pthread_mutex_lock(&lock);
            num_invasions++;
            pthread_mutex_unlock(&lock);
        }
    }

    // Return NULL
    return NULL;
}

// Main function
int main() {
    // Get the number of threads
    printf("Enter the number of threads: ");
    scanf("%d", &num_threads);

    // Get the number of simulations
    printf("Enter the number of simulations: ");
    scanf("%d", &num_simulations);

    // Initialize the number of invasions
    num_invasions = 0;

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create the threads
    pthread_t threads[num_threads];
    for (int i = 0; i < num_threads; i++) {
        int *thread_id = malloc(sizeof(int));
        *thread_id = i;
        pthread_create(&threads[i], NULL, simulate_invasion, thread_id);
    }

    // Join the threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    // Print the number of invasions
    printf("The number of invasions is: %d\n", num_invasions);

    // Return 0
    return 0;
}