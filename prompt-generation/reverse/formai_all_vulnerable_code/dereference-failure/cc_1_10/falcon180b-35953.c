//Falcon-180B DATASET v1.0 Category: Benchmarking ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4
#define NUM_ITERATIONS 1000000

int shared_data = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int id = *((int *) arg);
    int i;

    for (i = 0; i < NUM_ITERATIONS; i++) {
        pthread_mutex_lock(&mutex);
        shared_data++;
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %d completed %d iterations.\n", id, NUM_ITERATIONS);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i, rc;
    struct timespec start, end;

    srand(time(NULL));

    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)i);
        if (rc) {
            printf("Error: unable to create thread %d, %d\n", i, rc);
            exit(-1);
        }
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    clock_gettime(CLOCK_REALTIME, &start);
    shared_data = 0;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)i);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    clock_gettime(CLOCK_REALTIME, &end);

    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
    double throughput = (double)NUM_ITERATIONS * NUM_THREADS / elapsed_time;

    printf("Total iterations: %d\n", shared_data);
    printf("Throughput: %.2f iterations per second\n", throughput);

    return 0;
}