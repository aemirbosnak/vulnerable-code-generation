//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 10
#define NUM_TERMINALS 3
#define NUM_BAGGAGE_HANDLERS 5

sem_t available_bags;
sem_t baggage_handlers;
pthread_mutex_t lock;

typedef struct {
    int id;
    char baggage_id[10];
} Baggage;

Baggage conveyor_belt[MAX_BAGS];
int count = 0;

void* baggage_arrival(void* arg) {
    while (1) {
        sleep(rand() % 3 + 1); // Simulate bag arrival interval
        sem_wait(&available_bags);
        pthread_mutex_lock(&lock);

        if (count < MAX_BAGS) {
            Baggage new_bag;
            new_bag.id = count + 1;
            sprintf(new_bag.baggage_id, "BAG%d", new_bag.id);
            conveyor_belt[count] = new_bag;
            printf("Bag arrived: %s\n", new_bag.baggage_id);
            count++;
        } else {
            printf("Conveyor belt full! Cannot add more bags.\n");
        }

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* baggage_handling(void* arg) {
    int terminal_id = *((int*)arg);
    while (1) {
        sem_wait(&baggage_handlers);
        pthread_mutex_lock(&lock);
        
        if (count > 0) {
            count--;
            char processed_bag_id[10];
            strcpy(processed_bag_id, conveyor_belt[count].baggage_id);
            printf("Terminal %d processed: %s\n", terminal_id, processed_bag_id);
        } else {
            printf("Terminal %d found no bags to process.\n", terminal_id);
        }

        pthread_mutex_unlock(&lock);
        sem_post(&available_bags);
        sleep(rand() % 2 + 1); // Simulate handling time
    }
    return NULL;
}

int main() {
    srand(time(NULL));
    
    sem_init(&available_bags, 0, MAX_BAGS);
    sem_init(&baggage_handlers, 0, NUM_BAGGAGE_HANDLERS);
    pthread_mutex_init(&lock, NULL);

    pthread_t arrival_thread;
    pthread_create(&arrival_thread, NULL, baggage_arrival, NULL);

    pthread_t handlers[NUM_BAGGAGE_HANDLERS];
    int terminal_ids[NUM_TERMINALS];

    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        terminal_ids[i] = i + 1;
        pthread_create(&handlers[i], NULL, baggage_handling, (void*)&terminal_ids[i]);
    }

    pthread_join(arrival_thread, NULL);
    
    for (int i = 0; i < NUM_BAGGAGE_HANDLERS; i++) {
        pthread_join(handlers[i], NULL);
    }

    sem_destroy(&available_bags);
    sem_destroy(&baggage_handlers);
    pthread_mutex_destroy(&lock);

    return 0;
}