//GEMINI-pro DATASET v1.0 Category: Interprocess communication ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int count = 0;
sem_t mutex;
sem_t empty;
sem_t full;

void producer(void) {
    while (1) {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = rand() % 100;
        in = (in + 1) % BUFFER_SIZE;
        count++;
        printf("Producer produced %d\n", buffer[in-1]);
        sem_post(&mutex);
        sem_post(&full);
    }
}

void consumer(void) {
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        int item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        count--;
        printf("Consumer consumed %d\n", item);
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    pthread_t producer_thread;
    pthread_t consumer_thread;

    pthread_create(&producer_thread, NULL, (void*) producer, NULL);
    pthread_create(&consumer_thread, NULL, (void*) consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    return 0;
}