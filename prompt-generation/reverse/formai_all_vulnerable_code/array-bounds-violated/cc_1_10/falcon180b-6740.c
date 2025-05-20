//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_BAGS 100
#define NUM_CONVEYORS 4
#define NUM_WORKERS 6
#define DELAY 3

typedef struct {
    int id;
    int destination;
} Bag;

Bag bags[NUM_BAGS];
int conveyor_belts[NUM_CONVEYORS];
int worker_threads[NUM_WORKERS];

sem_t mutex;
sem_t empty;
sem_t full;

void init_semaphores() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, NUM_CONVEYORS);
    sem_init(&full, 0, 0);
}

void *conveyor_belt(void *arg) {
    int i = *(int *) arg;

    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);

        if (conveyor_belts[i] == 0) {
            conveyor_belts[i] = rand() % NUM_CONVEYORS;
        }

        bags[conveyor_belts[i]].destination = i;
        conveyor_belts[i] = (conveyor_belts[i] + 1) % NUM_CONVEYORS;

        sem_post(&mutex);
        sem_post(&full);

        sleep(DELAY);
    }

    return NULL;
}

void *worker(void *arg) {
    int i = *(int *) arg;

    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);

        if (bags[i].destination!= i) {
            bags[i].destination = i;
        }

        sem_post(&mutex);
        sem_post(&empty);

        sleep(DELAY);
    }

    return NULL;
}

int main() {
    srand(time(0));

    init_semaphores();

    for (int i = 0; i < NUM_WORKERS; i++) {
        pthread_create(&worker_threads[i], NULL, worker, (void *) i);
    }

    for (int i = 0; i < NUM_CONVEYORS; i++) {
        pthread_create(&worker_threads[NUM_WORKERS + i], NULL, conveyor_belt, (void *) i);
    }

    for (int i = 0; i < NUM_WORKERS + NUM_CONVEYORS; i++) {
        pthread_join(worker_threads[i], NULL);
    }

    return 0;
}