//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define STACK_SIZE 1024

void *thread_func(void *param);

int main() {
    pthread_t threads[NUM_THREADS];
    int rc;
    void *status;

    // Initialize random seed
    srand(time(NULL));

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)i);
        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], &status);
        if (rc) {
            printf("Error: unable to join thread, %d\n", rc);
            exit(-1);
        }
    }

    return 0;
}

void *thread_func(void *param) {
    int id = *(int *)param;
    printf("Thread %d started\n", id);

    // Simulate some work
    for (int i = 0; i < 1000000; i++) {
        int random = rand() % 10;
    }

    printf("Thread %d finished\n", id);
    return NULL;
}