//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 100

// Semaphore for critical section
sem_t mutex;

// Request queue
int request_queue[MAX_REQUESTS];
int front = -1, rear = -1;

// Thread ID array
pthread_t threads[MAX_THREADS];

// Function to be executed by each thread
void *customer(void *arg) {
    int id = *(int *) arg;
    char name[10] = {0};
    sprintf(name, "Cust%d", id);

    printf("%s is waiting in the queue...\n", name);

    // Wait until there is space in the request queue
    sem_wait(&mutex);

    // Enqueue request and print message
    request_queue[++rear] = id;
    printf("%s has placed an order.\n", name);

    // Signal the barber that a request has been placed
    sem_post(&mutex);

    // Wait for the barber to complete the request
    sem_wait(&mutex);

    printf("%s's order has been fulfilled.\n", name);

    // Dequeue request and print message
    rear--;
    printf("%s has left the shop.\n", name);

    // Signal the next customer that the barber is available
    sem_post(&mutex);

    pthread_exit(0);
}

int main() {
    int i, choice;
    char ch;

    printf("Barber Shop Simulation\n");
    printf("1. Start Simulation\n");
    printf("2. Exit\n");
    scanf("%d", &choice);

    if (choice == 1) {
        // Initialize semaphore
        sem_init(&mutex, 0, 1);

        // Create threads
        for (i = 0; i < MAX_THREADS; i++) {
            pthread_create(&threads[i], NULL, customer, (void *) i);
        }

        // Wait for all threads to finish
        for (i = 0; i < MAX_THREADS; i++) {
            pthread_join(threads[i], NULL);
        }

        sem_destroy(&mutex);
    }

    return 0;
}