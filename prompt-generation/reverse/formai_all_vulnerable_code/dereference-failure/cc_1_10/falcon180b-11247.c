//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_MSG_SIZE 1024

// semaphore for mutual exclusion
sem_t mutex;

// shared memory for interprocess communication
char shared_memory[MAX_MSG_SIZE];

// flag to indicate if there is data in the shared memory
int data_available = 0;

// function prototypes
void *producer(void *arg);
void *consumer(void *arg);

int main(int argc, char *argv[]) {
    int i;
    pthread_t threads[MAX_THREADS];

    // initialize semaphore
    sem_init(&mutex, 0, 1);

    // create producer threads
    for (i = 0; i < 5; i++) {
        pthread_create(&threads[i], NULL, producer, (void *)i);
    }

    // create consumer threads
    for (i = 5; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, consumer, (void *)i);
    }

    // wait for all threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

void *producer(void *arg) {
    int id = *((int *)arg);
    char msg[MAX_MSG_SIZE];

    // wait for semaphore
    sem_wait(&mutex);

    // generate message
    sprintf(msg, "Producer %d generated message: %d", id, id);

    // copy message to shared memory
    strcpy(shared_memory, msg);

    // set data available flag
    data_available = 1;

    // signal semaphore
    sem_post(&mutex);

    return NULL;
}

void *consumer(void *arg) {
    int id = *((int *)arg);

    // wait for semaphore
    sem_wait(&mutex);

    // check if there is data available
    while (data_available == 0) {
        sem_wait(&mutex);
    }

    // copy message from shared memory
    char msg[MAX_MSG_SIZE];
    strcpy(msg, shared_memory);

    // reset data available flag
    data_available = 0;

    // process message
    printf("Consumer %d received message: %s\n", id, msg);

    // signal semaphore
    sem_post(&mutex);

    return NULL;
}