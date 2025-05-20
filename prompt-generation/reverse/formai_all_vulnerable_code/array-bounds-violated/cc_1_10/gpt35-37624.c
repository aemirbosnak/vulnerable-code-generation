//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int bags_processed = 0;
int total_bags = 0;

typedef struct {
    int flight_num;
    int num_bags;
} Flight;

typedef struct {
    int bag_id;
    int flight_num;
} Bag;

Flight flights[MAX_FLIGHTS];
Bag bags[MAX_BAGS];

void* bag_handling(void* arg) {
    Bag* bag = (Bag*) arg;

    pthread_mutex_lock(&mutex);

    while (bags_processed >= total_bags) {
        pthread_cond_wait(&cond, &mutex);
    }

    // bag handling code here...

    printf("Bag %d processed for Flight %d\n", bag->bag_id, bag->flight_num);

    bags_processed++;

    pthread_mutex_unlock(&mutex);
    pthread_cond_broadcast(&cond);

    return NULL;
}

int main() {
    int i, j;

    // Initialize flights data
    for (i = 0; i < MAX_FLIGHTS; i++) {
        flights[i].flight_num = i + 1;
        flights[i].num_bags = rand() % MAX_BAGS;
        total_bags += flights[i].num_bags;
    }

    // Initialize bags data
    int bag_id = 1;
    for (i = 0; i < MAX_FLIGHTS; i++) {
        for (j = 0; j < flights[i].num_bags; j++) {
            bags[bag_id - 1].bag_id = bag_id;
            bags[bag_id - 1].flight_num = flights[i].flight_num;
            bag_id++;
        }
    }

    // Shuffle bags to simulate random order
    for (i = 0; i < total_bags; i++) {
        int index = rand() % total_bags;
        Bag temp = bags[i];
        bags[i] = bags[index];
        bags[index] = temp;
    }

    // Start bag processing threads
    pthread_t threads[MAX_BAGS];
    for (i = 0; i < total_bags; i++) {
        pthread_create(&threads[i], NULL, bag_handling, &bags[i]);
    }

    // Wait for all threads to finish
    for (i = 0; i < total_bags; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All bags have been processed\n");

    return 0;
}