//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define buffer size
#define BUFFER_SIZE 10

// Declare buffer and counter variables
int buffer[BUFFER_SIZE];
int counter = 0;

// Define mutex and condition variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;

// Define producer function
void *producer(void *arg) {
    int i;
    for(i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);
        if(counter == BUFFER_SIZE) {
            pthread_cond_wait(&empty, &mutex);
        }
        buffer[counter++] = i;
        pthread_cond_signal(&full);
        pthread_mutex_unlock(&mutex);
    }
    printf("Producer: Exiting\n");
    pthread_exit(NULL);
}

// Define consumer function
void *consumer(void *arg) {
    int i, item;
    for(i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);
        if(counter == 0) {
            pthread_cond_wait(&full, &mutex);
        }
        item = buffer[--counter];
        pthread_cond_signal(&empty);
        pthread_mutex_unlock(&mutex);
        printf("Consumer: Consumed Item %d\n", item);
    }
    printf("Consumer: Exiting\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    // Create producer thread
    if(pthread_create(&thread1, NULL, producer, NULL)) {
        fprintf(stderr, "Error creating producer thread\n");
        return 1;
    }
    printf("Producer thread created\n");

    // Create consumer thread
    if(pthread_create(&thread2, NULL, consumer, NULL)) {
        fprintf(stderr, "Error creating consumer thread\n");
        return 1;
    }
    printf("Consumer thread created\n");

    // Wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy mutex and condition variables
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&full);
    pthread_cond_destroy(&empty);

    return 0;
}