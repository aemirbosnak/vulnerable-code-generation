//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

// Shared buffer between the producer and the consumer
int buffer[BUFFER_SIZE];

// Index where the producer puts values and where the consumer reads values
int buf_index = 0;

// Semaphores for synchronization
sem_t empty;
sem_t full;
sem_t lock;

// Producer thread function
void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 50;
        sem_wait(&empty); // wait for an empty slot in the buffer
        sem_wait(&lock); // acquire the lock to modify the buffer
        buffer[buf_index++] = item;
        printf("Produced item: %d\n", item);
        sem_post(&lock); // release the lock
        sem_post(&full); // signal that a new item is available in the buffer
        sleep(1); // wait some time to produce the next item
    }
    return NULL;
}

// Consumer thread function
void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full); // wait for a new item in the buffer
        sem_wait(&lock); // acquire the lock to modify the buffer
        item = buffer[--buf_index];
        printf("Consumed item: %d\n", item);
        sem_post(&lock); // release the lock
        sem_post(&empty); // signal that an empty slot is available in the buffer
        sleep(2); // wait some time to consume the next item
    }
    return NULL;
}

int main() {
    // Initialize the semaphores
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&lock, 0, 1);

    // Create the producer and consumer threads
    pthread_t producer_thread, consumer_thread;
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for the producer and consumer threads to complete
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Destroy the semaphores
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&lock);

    return 0;
}