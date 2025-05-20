//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGGAGE 10
#define NUM_HANDLERS 3

// Struct to represent a baggage item
typedef struct {
    int id;
    int weight;
} Baggage;

// Global variables
Baggage baggageQueue[MAX_BAGGAGE];
int baggageCount = 0;
sem_t emptySlots;
sem_t filledSlots;

// Mutex for accessing baggage queue
pthread_mutex_t queueMutex = PTHREAD_MUTEX_INITIALIZER;

// Function to simulate baggage handling
void* baggageHandler(void* arg) {
    int handlerId = *(int*)arg;

    while (1) {
        // Wait until there is a filled slot
        sem_wait(&filledSlots);
        
        // Lock the access to the baggage queue
        pthread_mutex_lock(&queueMutex);
        
        // Handle the baggage
        Baggage bag = baggageQueue[--baggageCount];
        printf("Handler %d is processing baggage ID %d, weight %dkg\n", 
                handlerId, bag.id, bag.weight);

        // Unlock the mutex after processing
        pthread_mutex_unlock(&queueMutex);
        
        // Signal that there is now an empty slot
        sem_post(&emptySlots);

        // Simulate time taken to process baggage
        sleep(1);
    }
}

// Function to generate baggage
void* generateBaggage(void* arg) {
    int id = 0;
    while (1) {
        // Lock the access to the baggage queue
        pthread_mutex_lock(&queueMutex);
        
        // Check if there's space in the baggage queue
        if (baggageCount < MAX_BAGGAGE) {
            baggageQueue[baggageCount].id = id++;
            baggageQueue[baggageCount].weight = rand() % 30 + 1; // Weight 1 kg to 30 kg
            printf("Generated baggage ID %d, weight %dkg\n", 
                    baggageQueue[baggageCount].id, baggageQueue[baggageCount].weight);
            baggageCount++;

            // Signal that a new baggage has been added
            sem_post(&filledSlots);
        }

        // Unlock the mutex after updating the queue
        pthread_mutex_unlock(&queueMutex);

        // Simulate time taken to generate baggage
        sleep(rand() % 3 + 1); // Sleep between 1 to 3 seconds
    }
}

int main() {
    pthread_t handlers[NUM_HANDLERS];
    pthread_t generator;

    // Initialize semaphores
    sem_init(&emptySlots, 0, MAX_BAGGAGE);
    sem_init(&filledSlots, 0, 0);

    // Create baggage handlers
    int handlerIds[NUM_HANDLERS];
    for (int i = 0; i < NUM_HANDLERS; i++) {
        handlerIds[i] = i + 1;
        pthread_create(&handlers[i], NULL, baggageHandler, &handlerIds[i]);
    }

    // Create baggage generator
    pthread_create(&generator, NULL, generateBaggage, NULL);

    // Wait for the baggage handler threads to complete (this will never happen in this simulation)
    for (int i = 0; i < NUM_HANDLERS; i++) {
        pthread_join(handlers[i], NULL);
    }

    // Wait for the baggage generator thread (this will never happen in this simulation)
    pthread_join(generator, NULL);

    // Destroy semaphores
    sem_destroy(&emptySlots);
    sem_destroy(&filledSlots);
    pthread_mutex_destroy(&queueMutex);

    return 0;
}