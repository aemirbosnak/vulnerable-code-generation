//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define STACK_SIZE (1024 * 1024) // 1MB

typedef struct {
    int id;
    void *(*start_routine)(void *);
    void *arg;
} thread_data_t;

void *time_travel(void *arg) {
    int destination_year = *(int *) arg;

    printf("Thread %d traveling to the year %d...\n", *(int *) arg, destination_year);

    sleep(1); // Simulate time travel

    printf("Thread %d has arrived in the year %d!\n", *(int *) arg, destination_year);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int ids[NUM_THREADS] = {1, 2, 3};
    void *result;
    int rc;

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data_t *data = (thread_data_t *) malloc(sizeof(thread_data_t));

        data->id = ids[i];
        data->start_routine = time_travel;
        data->arg = &ids[i];

        rc = pthread_create(&threads[i], NULL, data->start_routine, data);
        if (rc) {
            printf("Error: unable to create thread %d, %d\n", i, rc);
            exit(-1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &result);
        if (rc) {
            printf("Error: unable to join with thread %d, %d\n", i, rc);
            exit(-1);
        }
    }

    return 0;
}