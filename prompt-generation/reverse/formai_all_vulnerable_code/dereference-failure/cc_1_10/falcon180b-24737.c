//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
    int thread_id;
    int *shared_data;
} thread_data_t;

void *thread_func(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    int thread_id = data->thread_id;
    int *shared_data = data->shared_data;

    // Do some work here
    for (int i = 0; i < 1000; i++) {
        // Access shared data
        shared_data[thread_id] = i;

        // Yield to other threads
        sched_yield();
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int shared_data[NUM_THREADS];

    // Initialize shared data
    for (int i = 0; i < NUM_THREADS; i++) {
        shared_data[i] = 0;
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));
        data->thread_id = i;
        data->shared_data = shared_data;

        if (pthread_create(&threads[i], NULL, thread_func, data)) {
            printf("Error creating thread %d\n", i);
            exit(1);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL)) {
            printf("Error joining thread %d\n", i);
            exit(1);
        }
    }

    return 0;
}