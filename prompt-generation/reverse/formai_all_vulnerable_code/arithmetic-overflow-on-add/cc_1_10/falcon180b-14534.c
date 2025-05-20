//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 10
#define MAX_TIME 1000
#define PROBABILITY_THRESHOLD 0.5

int num_invasions = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    int start_time = time(NULL) + thread_id * 10;
    int end_time = start_time + MAX_TIME;

    while (difftime(time(NULL), start_time) < 0) {
        usleep(100000); // Sleep for a short time to avoid busy waiting
    }

    while (difftime(time(NULL), end_time) < 0) {
        double rand_num = rand() / (double) RAND_MAX;
        if (rand_num < PROBABILITY_THRESHOLD) {
            pthread_mutex_lock(&mutex);
            num_invasions++;
            printf("Thread %d detected an alien invasion at time %ld\n", thread_id, time(NULL));
            pthread_mutex_unlock(&mutex);
        }
        usleep(100000); // Sleep for a short time to avoid busy waiting
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total number of alien invasions detected: %d\n", num_invasions);

    return 0;
}