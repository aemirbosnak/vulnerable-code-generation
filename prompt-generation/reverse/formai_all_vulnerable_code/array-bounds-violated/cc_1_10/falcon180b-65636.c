//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex lock for critical section
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Condition variable for thread synchronization
pthread_cond_t cv = PTHREAD_COND_INITIALIZER;

// Buffer for producer-consumer problem
#define BUFFER_SIZE 10
int buffer[BUFFER_SIZE];
int front = 0, rear = -1;

// Function for producer thread
void *producer(void *arg) {
    int i;
    for(i = 0; i < 20; i++) {
        pthread_mutex_lock(&lock);
        // Wait until there is space in the buffer
        while(rear == BUFFER_SIZE - 1) {
            pthread_cond_wait(&cv, &lock);
        }
        buffer[++rear] = i;
        printf("Produced %d\n", i);
        fflush(stdout);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

// Function for consumer thread
void *consumer(void *arg) {
    int i;
    for(i = 0; i < 20; i++) {
        pthread_mutex_lock(&lock);
        // Wait until there is data in the buffer
        while(front == -1) {
            pthread_cond_wait(&cv, &lock);
        }
        printf("Consumed %d\n", buffer[front++]);
        fflush(stdout);
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread_id[2];

    // Create producer and consumer threads
    pthread_create(&thread_id[0], NULL, producer, NULL);
    pthread_create(&thread_id[1], NULL, consumer, NULL);

    // Join producer and consumer threads
    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}