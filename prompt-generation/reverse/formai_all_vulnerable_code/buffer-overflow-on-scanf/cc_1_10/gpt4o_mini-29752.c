//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_BAGS 100

typedef struct {
    int id;
    int processed;
} Bag;

typedef struct {
    Bag bags[MAX_BAGS];
    int count;
} BaggageList;

BaggageList baggageList;
sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void* baggage_handler(void* arg) {
    int handler_id = *((int*)arg);

    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        
        if (baggageList.count > 0) {
            Bag bag = baggageList.bags[--baggageList.count];
            printf("Handler %d is processing Bag %d...\n", handler_id, bag.id);
            pthread_mutex_unlock(&mutex);
            sleep(rand() % 3 + 1);  // Simulate processing time
            printf("Handler %d completed Bag %d processing.\n", handler_id, bag.id);
        } else {
            pthread_mutex_unlock(&mutex);
        }
        
        sem_post(&empty);
        sleep(rand() % 2); // Random idle time
    }
    return NULL;
}

void add_bags(int num_bags) {
    for (int i = 0; i < num_bags; i++) {
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        
        if (baggageList.count < MAX_BAGS) {
            baggageList.bags[baggageList.count].id = baggageList.count + 1;
            baggageList.bags[baggageList.count].processed = 0;
            baggageList.count++;
            printf("Added Bag %d to the system.\n", baggageList.count);
        } else {
            printf("Bag storage is full!\n");
        }
        
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
        sleep(rand() % 2); // Random arrival time
    }
}

int main() {
    int num_handlers, num_bags;

    printf("Enter number of baggage handlers: ");
    scanf("%d", &num_handlers);
    printf("Enter number of bags to be processed: ");
    scanf("%d", &num_bags);

    if (num_handlers <= 0 || num_bags <= 0 || num_bags > MAX_BAGS) {
        fprintf(stderr, "Invalid number of handlers or bags.\n");
        return 1;
    }

    baggageList.count = 0;
    sem_init(&empty, 0, MAX_BAGS);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_t handlers[num_handlers];
    int handler_ids[num_handlers];

    for (int i = 0; i < num_handlers; i++) {
        handler_ids[i] = i + 1;
        pthread_create(&handlers[i], NULL, baggage_handler, &handler_ids[i]);
    }

    add_bags(num_bags);

    // Clean up
    for (int i = 0; i < num_handlers; i++) {
        pthread_cancel(handlers[i]); // Cancel the threads when done
    }

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    printf("Baggage handling simulation completed.\n");

    return 0;
}