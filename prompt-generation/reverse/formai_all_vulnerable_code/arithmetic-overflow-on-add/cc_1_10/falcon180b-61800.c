//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

struct thread_data {
    int thread_id;
    int start_time;
};

void *drone_thread(void *param) {
    struct thread_data *data = (struct thread_data *) param;
    int thread_id = data->thread_id;
    int start_time = data->start_time;

    printf("Drone %d started at %d\n", thread_id, start_time);

    // Simulate drone flight
    for (int i = 0; i < 10; i++) {
        printf("Drone %d is flying...\n", thread_id);
        sleep(1);
    }

    printf("Drone %d finished at %d\n", thread_id, start_time + 10);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    struct thread_data data[NUM_THREADS];

    // Initialize thread data
    for (int i = 0; i < NUM_THREADS; i++) {
        data[i].thread_id = i + 1;
        data[i].start_time = time(NULL);
    }

    // Create drone threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, drone_thread, &data[i]);
    }

    // Wait for all drones to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}