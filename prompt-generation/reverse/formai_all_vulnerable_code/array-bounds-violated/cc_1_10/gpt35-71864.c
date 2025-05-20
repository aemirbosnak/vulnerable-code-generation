//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

// Define global variables
#define BUFFER_SIZE 10
int baggageBuffer[BUFFER_SIZE]; // Shared buffer
int count = 0; // Count of the number of baggage in the buffer
sem_t empty; // Semaphore to signal when the buffer is empty
sem_t full; // Semaphore to signal when the buffer is full
pthread_mutex_t mutex; // Mutex to ensure proper execution of critical section

// Define the functions for the producers and consumers
void *producer(void *arg) {
    while (true) {
        int baggage = rand() % 10; // Generate a random amount of baggage to add
        sem_wait(&empty); // Wait until there is an empty slot in buffer
        pthread_mutex_lock(&mutex); // Lock the critical section
        
        // Add the baggage to the buffer
        baggageBuffer[count] = baggage;
        count++;
        printf("Producer produced %d items\n", baggage);
        
        pthread_mutex_unlock(&mutex); // Unlock the critical section
        sem_post(&full); // Signal that the buffer is now full
    }
}

void *consumer(void *arg) {
    while (true) {
        sem_wait(&full); // Wait until there is a full slot in buffer
        pthread_mutex_lock(&mutex); // Lock the critical section
        
        // Remove the baggage from the buffer
        int baggage = baggageBuffer[count - 1];
        count--;
        printf("Consumer consumed %d items\n", baggage);
        
        pthread_mutex_unlock(&mutex); // Unlock the critical section
        sem_post(&empty); // Signal that the buffer is now empty
    }
}

int main() {
    // Initialize the semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    
    // Create the producer and consumer threads
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);
    
    // Wait for the threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);
    
    // Destroy the semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}