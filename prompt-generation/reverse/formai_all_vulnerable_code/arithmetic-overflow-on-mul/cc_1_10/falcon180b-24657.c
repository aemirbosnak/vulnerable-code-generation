//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

#define NUM_THREADS 4
#define NUM_ROWS 1000000

int shared_data[NUM_ROWS];
pthread_mutex_t mutex;

void* thread_func(void* arg) {
    int thread_id = *((int*) arg);
    int start_row = thread_id * NUM_ROWS / NUM_THREADS;
    int end_row = (thread_id + 1) * NUM_ROWS / NUM_THREADS;

    for (int i = start_row; i < end_row; i++) {
        shared_data[i] = i * i;
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    for (int i = 0; i < NUM_ROWS; i++) {
        if (shared_data[i]!= i * i) {
            printf("Error: Data mismatch at row %d\n", i);
            return 1;
        }
    }

    printf("Benchmark completed successfully!\n");
    return 0;
}