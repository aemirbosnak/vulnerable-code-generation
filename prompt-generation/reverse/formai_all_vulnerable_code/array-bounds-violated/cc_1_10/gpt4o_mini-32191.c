//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 10
#define CONVEYOR_BELT_CAPACITY 5

typedef struct {
    int bag_id;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int count;
    sem_t full;
    sem_t empty;
    pthread_mutex_t mutex;
} ConveyorBelt;

ConveyorBelt conveyor_belt;

void* bag_producer(void* arg) {
    for (int i = 0; i < MAX_BAGS; i++) {
        sem_wait(&conveyor_belt.empty);
        pthread_mutex_lock(&conveyor_belt.mutex);

        conveyor_belt.bags[conveyor_belt.count].bag_id = i + 1;
        printf("Produced Bag %d\n", i + 1);
        conveyor_belt.count++;

        pthread_mutex_unlock(&conveyor_belt.mutex);
        sem_post(&conveyor_belt.full);

        sleep(rand() % 2); // Simulate time taken to produce a bag
    }
    return NULL;
}

void* bag_consumer(void* arg) {
    for (int i = 0; i < MAX_BAGS; i++) {
        sem_wait(&conveyor_belt.full);
        pthread_mutex_lock(&conveyor_belt.mutex);

        int bag_id = conveyor_belt.bags[conveyor_belt.count - 1].bag_id;
        printf("Consumed Bag %d\n", bag_id);
        conveyor_belt.count--;

        pthread_mutex_unlock(&conveyor_belt.mutex);
        sem_post(&conveyor_belt.empty);

        sleep(rand() % 3); // Simulate time taken to process a bag
    }
    return NULL;
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize the conveyor belt
    conveyor_belt.count = 0;
    sem_init(&conveyor_belt.full, 0, 0);
    sem_init(&conveyor_belt.empty, 0, CONVEYOR_BELT_CAPACITY);
    pthread_mutex_init(&conveyor_belt.mutex, NULL);

    // Create the producer and consumer threads
    pthread_create(&producer_thread, NULL, bag_producer, NULL);
    pthread_create(&consumer_thread, NULL, bag_consumer, NULL);

    // Join threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Cleanup
    sem_destroy(&conveyor_belt.full);
    sem_destroy(&conveyor_belt.empty);
    pthread_mutex_destroy(&conveyor_belt.mutex);

    printf("Baggage handling complete.\n");
    return 0;
}