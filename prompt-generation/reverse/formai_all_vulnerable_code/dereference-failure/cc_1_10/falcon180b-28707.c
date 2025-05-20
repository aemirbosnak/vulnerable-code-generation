//Falcon-180B DATASET v1.0 Category: Memory management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 10
#define MAX_REQUESTS 1000

typedef struct request {
    int id;
    int size;
    char *data;
} request_t;

typedef struct thread_data {
    int thread_id;
    sem_t *sem;
    request_t *requests;
} thread_data_t;

void *thread_function(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int i;

    for (i = 0; i < MAX_REQUESTS; i++) {
        sem_wait(data->sem);

        request_t request = data->requests[i];
        printf("Thread %d processing request %d of size %d\n", data->thread_id, request.id, request.size);

        // Do some processing here

        free(request.data);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    sem_t sem;
    request_t requests[MAX_REQUESTS];
    thread_data_t thread_data[MAX_THREADS];

    int i, j;

    // Initialize semaphore
    sem_init(&sem, 0, 0);

    // Create requests
    for (i = 0; i < MAX_REQUESTS; i++) {
        requests[i].id = i;
        requests[i].size = rand() % 100;
        requests[i].data = (char *) malloc(requests[i].size);
        memset(requests[i].data, 'a', requests[i].size);
    }

    // Create threads
    for (i = 0; i < MAX_THREADS; i++) {
        thread_data[i].thread_id = i;
        thread_data[i].sem = &sem;
        thread_data[i].requests = requests;

        pthread_create(&threads[i], NULL, thread_function, (void *) &thread_data[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy semaphore
    sem_destroy(&sem);

    return 0;
}