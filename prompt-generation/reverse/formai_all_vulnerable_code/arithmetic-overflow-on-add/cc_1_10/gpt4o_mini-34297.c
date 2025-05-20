//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_CALCULATIONS 10000
#define NUM_THREADS 4

typedef struct {
    int thread_id;
    int calculations;
    double probability;
} ThreadData;

void* calculate_probability(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    srand(time(NULL) + data->thread_id);
    
    int alien_invasions = 0;
    
    // Simulate the number of alien invasions
    for (int i = 0; i < data->calculations; i++) {
        // Randomly determine if an alien invasion occurs (for illustrative purposes)
        if (rand() % 100 < 10) { // 10% chance for an invasion
            alien_invasions++;
        }
    }
    
    // Calculate probability for this thread
    data->probability = (double)alien_invasions / data->calculations;

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];

    // Number of calculations per thread
    int calculations_per_thread = NUM_CALCULATIONS / NUM_THREADS;

    // Create and execute threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].calculations = calculations_per_thread;
        thread_data[i].probability = 0.0;
        
        int rc = pthread_create(&threads[i], NULL, calculate_probability, (void*)&thread_data[i]);
        if (rc) {
            fprintf(stderr, "Error creating thread %d: %d\n", i, rc);
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to complete
    double total_probability = 0.0;
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        total_probability += thread_data[i].probability;
    }

    // Calculate the overall invasion probability
    double average_probability = total_probability / NUM_THREADS;

    // Display the results
    printf("Total calculations: %d\n", NUM_CALCULATIONS);
    printf("Average Probability of Alien Invasion: %.4f\n", average_probability);

    // Simulate final decision based on invasion probability
    if (average_probability > 0.05) {
        printf("Warning: High probability of alien invasion detected! Prepare defenses!\n");
    } else {
        printf("All clear: Low probability of alien invasion.\n");
    }
    
    return 0;
}