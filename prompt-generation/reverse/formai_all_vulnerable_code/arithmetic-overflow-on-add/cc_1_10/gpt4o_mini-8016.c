//GPT-4o-mini DATASET v1.0 Category: Threading Library Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <time.h>

#define NUM_THREADS 5
#define MAX_ITEMS 10

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

int buffer[MAX_ITEMS];
int in = 0; // Next empty place in the buffer
int out = 0; // Next filled place in the buffer

void* producer(void* param);
void* consumer(void* param);
void produce(int item);
int consume();

int main() {
    pthread_t producers[NUM_THREADS];
    pthread_t consumers[NUM_THREADS];

    // Initialize semaphores and mutex
    sem_init(&empty, 0, MAX_ITEMS);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    // Create producer threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&producers[i], NULL, producer, (void*)&i) != 0) {
            perror("Failed to create producer thread");
            exit(EXIT_FAILURE);
        }
    }

    // Create consumer threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&consumers[i], NULL, consumer, (void*)&i) != 0) {
            perror("Failed to create consumer thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(producers[i], NULL);
        pthread_join(consumers[i], NULL);
    }

    // Clean up
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}

void* producer(void* param) {
    int id = *(int*)param;
    srand(time(NULL) + id); // Seed random number generator

    for (int i = 0; i < 10; i++) {
        int item = rand() % 100; // Produce a random item

        // Wait for empty space
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        produce(item);
        printf("Producer %d produced: %d\n", id, item);

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(rand() % 3); // Simulate variable production time
    }

    return NULL;
}

void* consumer(void* param) {
    int id = *(int*)param;

    for (int i = 0; i < 10; i++) {
        // Wait for full item
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item = consume();
        printf("Consumer %d consumed: %d\n", id, item);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(rand() % 3); // Simulate variable consumption time
    }

    return NULL;
}

void produce(int item) {
    buffer[in] = item;
    in = (in + 1) % MAX_ITEMS;
}

int consume() {
    int item = buffer[out];
    out = (out + 1) % MAX_ITEMS;
    return item;
}