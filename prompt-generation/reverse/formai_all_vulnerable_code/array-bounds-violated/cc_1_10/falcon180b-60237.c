//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10
#define NUM_SHARED_VARIABLES 5

int shared_variables[NUM_SHARED_VARIABLES];
pthread_mutex_t mutex;

void init_shared_variables() {
    for (int i = 0; i < NUM_SHARED_VARIABLES; i++) {
        shared_variables[i] = 0;
    }
}

void *thread_function(void *arg) {
    int thread_id = (int) arg;
    int sum = 0;

    for (int i = 0; i < 1000000; i++) {
        pthread_mutex_lock(&mutex);
        shared_variables[thread_id]++;
        sum += shared_variables[thread_id];
        pthread_mutex_unlock(&mutex);
    }

    printf("Thread %d finished with sum: %d\n", thread_id, sum);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    init_shared_variables();
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *) &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}