//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_SAMPLES 1000000 // Number of Monte Carlo samples
#define NUM_THREADS 4 // Number of threads to use
#define ALIEN_PROB 0.001 // Hypothetical alien invasion probability per year

typedef struct {
    int thread_id;
    long samples;
    long *invasion_count;
} ThreadData;

void *calculate_probability(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    long local_count = 0;
    unsigned int seed = time(NULL) + data->thread_id; // Unique seed for each thread

    for (long i = 0; i < data->samples; i++) {
        double rand_val = (double)rand_r(&seed) / RAND_MAX; // Random value between 0 and 1
        if (rand_val < ALIEN_PROB) {
            local_count++;
        }
    }
    
    *(data->invasion_count) += local_count;
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    long invasion_count = 0;
    
    long samples_per_thread = NUM_SAMPLES / NUM_THREADS;

    // Initialize random number generator
    srand(time(NULL));

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].samples = samples_per_thread;
        thread_data[i].invasion_count = &invasion_count;

        if (pthread_create(&threads[i], NULL, calculate_probability, (void *)&thread_data[i]) != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Calculate the probability of alien invasion
    double probability = (double)invasion_count / NUM_SAMPLES;
    printf("Estimated probability of an alien invasion: %.8f\n", probability);
    
    // Show confidence interval
    double confidence_interval = 1.96 * sqrt((probability * (1 - probability)) / NUM_SAMPLES);
    printf("95%% Confidence Interval: [%.8f, %.8f]\n", 
           probability - confidence_interval, 
           probability + confidence_interval);
    
    // Understanding the significance of the result
    if (probability > ALIEN_PROB) {
        printf("Warning: The estimated probability is higher than expected! Prepare for potential invasion!\n");
    } else {
        printf("Status: Current probability is below the expectation. All is calm for now.\n");
    }

    return 0;
}