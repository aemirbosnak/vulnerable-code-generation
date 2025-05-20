//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGGAGE 10
#define MAX_AIRCRAFT 5

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

int baggageQueue[MAX_BAGGAGE]; // Shared buffer to hold baggage
int baggageCount = 0;

// Function for baggage loading
void* baggageLoading(void* arg) {
    int aircraftID = *(int*)arg;
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        // Simulating random baggage loading
        usleep(rand() % 100000); // sleep for a random time in microseconds

        // Wait for empty space before loading baggage
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        // Load baggage
        baggageQueue[baggageCount] = i + (aircraftID * 100); // Unique baggage ID
        baggageCount++;
        printf("Aircraft %d loaded baggage ID %d\n", aircraftID, baggageQueue[baggageCount - 1]);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    return NULL;
}

// Function for baggage unloading
void* baggageUnloading(void* arg) {
    int unloadingID = *(int*)arg;
    for (int i = 0; i < MAX_BAGGAGE; i++) {
        // Wait for filled baggage to unload
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        // Unload baggage
        int baggageID = baggageQueue[baggageCount - 1];
        baggageCount--;
        printf("Baggage Handler %d unloaded baggage ID %d\n", unloadingID, baggageID);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        // Simulating random baggage unloading
        usleep(rand() % 100000); // sleep for a random time in microseconds
    }
    return NULL;
}

int main() {
    pthread_t aircraft[MAX_AIRCRAFT];
    pthread_t handlers[MAX_AIRCRAFT];
    int aircraftID[MAX_AIRCRAFT];
    int handlerID[MAX_AIRCRAFT];

    // Initialize semaphore and mutex
    sem_init(&empty, 0, MAX_BAGGAGE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create aircraft threads
    for (int i = 0; i < MAX_AIRCRAFT; i++) {
        aircraftID[i] = i + 1;
        pthread_create(&aircraft[i], NULL, baggageLoading, (void*)&aircraftID[i]);

        handlerID[i] = i + 1;
        pthread_create(&handlers[i], NULL, baggageUnloading, (void*)&handlerID[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_AIRCRAFT; i++) {
        pthread_join(aircraft[i], NULL);
        pthread_join(handlers[i], NULL);
    }

    // Destroy semaphore and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}