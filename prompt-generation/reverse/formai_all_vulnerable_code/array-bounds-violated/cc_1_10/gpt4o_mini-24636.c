//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define NUM_ITERATIONS 10

int buffer[BUFFER_SIZE];
int count = 0;  // Number of items in the buffer

sem_t empty;  // Semaphore to count empty slots in buffer
sem_t full;   // Semaphore to count full slots in buffer
pthread_mutex_t mutex;  // Mutex for critical section

// Function for producer
void* producer(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        int item = rand() % 100; // Produce a random number
        sem_wait(&empty); // Wait for an empty slot
        pthread_mutex_lock(&mutex); // Enter critical section

        // Add item to buffer
        buffer[count++] = item;
        printf("Producer produced: %d\n", item);

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&full); // Signal that a new item is available

        sleep(1); // Simulate time taken to produce an item
    }
    return NULL;
}

// Function for consumer
void* consumer(void* arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        sem_wait(&full); // Wait for a full slot
        pthread_mutex_lock(&mutex); // Enter critical section

        // Remove item from buffer
        int item = buffer[--count];
        printf("Consumer consumed: %d\n", item);

        pthread_mutex_unlock(&mutex); // Exit critical section
        sem_post(&empty); // Signal that an item has been consumed

        sleep(2); // Simulate time taken to consume an item
    }
    return NULL;
}

int main() {
    pthread_t prod_thread, cons_thread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE); // Set empty to the size of the buffer
    sem_init(&full, 0, 0); // No items initially
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod_thread, NULL, producer, NULL);
    pthread_create(&cons_thread, NULL, consumer, NULL);

    // Wait for both threads to finish
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);

    // Clean up
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}