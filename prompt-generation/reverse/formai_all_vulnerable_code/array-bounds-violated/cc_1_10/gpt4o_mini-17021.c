//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define MAX_BAGS 10
#define NUM_BAGGAGE_HANDLERS 3

sem_t empty; // Semaphore for empty bins
sem_t full;  // Semaphore for full bins
pthread_mutex_t mutex; // Mutex for critical section

int baggage[MAX_BAGS];
int count = 0; // Current number of bags

void* baggage_handler(void* id) {
    int handler_id = *(int*)id;

    while (1) {
        sem_wait(&full); // Wait for a full bin

        pthread_mutex_lock(&mutex); // Lock the mutex
        int bag = baggage[count - 1]; // Get the bag from the buffer
        count--;
        printf("Handler %d processing bag %d\n", handler_id, bag);
        pthread_mutex_unlock(&mutex); // Unlock the mutex

        sem_post(&empty); // Signal that there is an empty bin

        sleep(rand() % 3 + 1); // Simulate time taken to handle the bag
    }
}

void* baggage_loader(void* arg) {
    while (1) {
        sem_wait(&empty); // Wait for an empty bin

        pthread_mutex_lock(&mutex); // Lock the mutex
        int bag = rand() % 100; // Generate a random bag ID
        baggage[count] = bag; // Add the bag to the buffer
        printf("Loaded bag %d\n", bag);
        count++;
        pthread_mutex_unlock(&mutex); // Unlock the mutex

        sem_post(&full); // Signal that there is a full bin

        sleep(rand() % 3 + 1); // Simulate time taken to load the bag
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    pthread_t loaders[1]; // Create thread for baggage loader
    pthread_t handlers[NUM_BAGGAGE_HANDLERS]; // Create threads for baggage handlers
    int handler_ids[NUM_BAGGAGE_HANDLERS]; // IDs for the handlers

    sem_init(&empty, 0, MAX_BAGS); // Initialize empty semaphore
    sem_init(&full, 0, 0); // Initialize full semaphore
    pthread_mutex_init(&mutex, NULL); // Initialize mutex

    // Create baggage loader thread
    pthread_create(&loaders[0], NULL, baggage_loader, NULL);

    // Create baggage handlers threads
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        handler_ids[i] = i + 1; // Assign IDs to handlers
        pthread_create(&handlers[i], NULL, baggage_handler, &handler_ids[i]);
    }

    // Join all threads (in this example, they run indefinitely)
    pthread_join(loaders[0], NULL);
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_join(handlers[i], NULL);
    }

    // Cleanup (though this won't be reached in this infinite loop)
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}