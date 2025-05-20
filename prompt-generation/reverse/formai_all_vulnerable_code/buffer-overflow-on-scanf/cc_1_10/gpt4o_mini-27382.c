//GPT-4o-mini DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define NUM_FACTORS 3
#define NUM_THREADS 3

typedef struct {
    int *values;
    double probability;
    int thread_id;
} ThreadData;

void *calculate_probability(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    
    // Simple logic to simulate probability calculation
    double factor_weight[] = {0.5, 0.3, 0.2}; // weights for UFO sightings, defense spending, technological advancement
    data->probability = (data->values[0] * factor_weight[0] + 
                         data->values[1] * factor_weight[1] + 
                         data->values[2] * factor_weight[2]) / 
                         (data->values[0] + data->values[1] + data->values[2]);
    
    printf("Thread %d calculated probability: %f\n", data->thread_id, data->probability);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    ThreadData thread_data[NUM_THREADS];
    int invasion_factors[NUM_FACTORS];
    
    // Input data for alien invasion factors
    printf("Enter number of UFO sightings: ");
    scanf("%d", &invasion_factors[0]);
    printf("Enter government spending on defense (in billions): ");
    scanf("%d", &invasion_factors[1]);
    printf("Enter level of technological advancement (1-10): ");
    scanf("%d", &invasion_factors[2]);

    // Initializing threads
    for(int i = 0; i < NUM_THREADS; i++) {
        thread_data[i].values = invasion_factors;
        thread_data[i].thread_id = i;
        
        if(pthread_create(&threads[i], NULL, calculate_probability, (void *)&thread_data[i])) {
            fprintf(stderr, "Error creating thread\n");
            return 1;
        }
    }
    
    // Wait for all threads to complete
    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Aggregate results from threads
    double total_probability = 0;
    for(int i = 0; i < NUM_THREADS; i++) {
        total_probability += thread_data[i].probability;
    }
    double average_probability = total_probability / NUM_THREADS;

    printf("Average Alien Invasion Probability: %.2f%%\n", average_probability * 100);
    
    return 0;
}