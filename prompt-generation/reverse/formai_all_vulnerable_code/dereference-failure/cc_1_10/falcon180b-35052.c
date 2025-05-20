//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define the maximum number of threads
#define MAX_THREADS 10

// Define the number of iterations each thread will perform
#define ITERATIONS 1000000

// Define the shared data structure
typedef struct {
    int value;
    sem_t lock;
} shared_data_t;

// Function to initialize the shared data structure
void init_shared_data(shared_data_t* data) {
    data->value = 0;
    sem_init(&data->lock, 0, 1);
}

// Function to increment the shared data value
void* thread_func(void* arg) {
    int id = *(int*)arg;
    shared_data_t* data = (shared_data_t*)malloc(sizeof(shared_data_t));
    init_shared_data(data);

    for (int i = 0; i < ITERATIONS; i++) {
        sem_wait(&data->lock);
        data->value++;
        sem_post(&data->lock);
    }

    printf("Thread %d finished.\n", id);
    return NULL;
}

int main() {
    // Initialize the shared data structure
    shared_data_t shared_data;
    init_shared_data(&shared_data);

    // Create the threads
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];
    for (int i = 0; i < MAX_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    // Join the threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}