//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Number of bags in the airport
#define BAGS 20

// Maximum number of bags that can be stored in the baggage handling system at a time
#define MAX_CAPACITY 10

// A bag stores information about the bag's ID and its destination
typedef struct Bag {
    int id;
    char destination[50];
} Bag;

// Variables to keep track of the bags in the system and the number of bags
Bag bags[BAGS];
int numBags = 0;

// Semaphores for the baggage handling system
sem_t mutex, full, empty;

// Functions for the threads
void *producer(void *arg);
void *consumer(void *arg);

int main() {
    // Initialize the semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, MAX_CAPACITY);

    // Create the threads
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, producer, NULL);
    pthread_create(&consumerThread, NULL, consumer, NULL);

    // Wait for the threads to finish
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destroy the semaphores
    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);

    return 0;
}

// Producer function to generate the bags
void *producer(void *arg) {
    int i;
    for(i = 0; i < BAGS; i++) {
        sem_wait(&empty);
        sem_wait(&mutex);

        // Generate a bag with a random ID and a random destination
        Bag newBag;
        newBag.id = i;
        sprintf(newBag.destination, "Destination %d", rand()%5+1);

        // Add the bag to the system
        bags[numBags++] = newBag;
        printf("Producer: Bag with ID %d and destination %s added to the system. Total bags: %d\n", newBag.id, newBag.destination, numBags);

        sem_post(&mutex);
        sem_post(&full);
    }

    // Exit the thread
    pthread_exit(NULL);
}

// Consumer function to handle the bags
void *consumer(void *arg) {
    int i;
    for(i = 0; i < BAGS; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        // Get the bag with the highest ID and remove it from the system
        int highestID = -1, highestIndex = -1;
        int j;
        for(j = 0; j < numBags; j++) {
            if(bags[j].id > highestID) {
                highestID = bags[j].id;
                highestIndex = j;
            }
        }
        Bag removedBag = bags[highestIndex];
        printf("Consumer: Bag with ID %d and destination %s removed from the system. Total bags: %d\n", removedBag.id, removedBag.destination, numBags-1);
        numBags--;
        bags[highestIndex] = bags[numBags];

        sem_post(&mutex);
        sem_post(&empty);
    }

    // Exit the thread
    pthread_exit(NULL);
}