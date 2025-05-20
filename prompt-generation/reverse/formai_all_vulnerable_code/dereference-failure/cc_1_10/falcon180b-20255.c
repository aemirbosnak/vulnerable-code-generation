//Falcon-180B DATASET v1.0 Category: Threading Library Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define STACK_SIZE (1024 * 1024) // 1MB

void *thread_func(void *arg) {
    int tid = *(int *) arg;
    printf("Thread %d started\n", tid);
    sleep(1);
    printf("Thread %d finished\n", tid);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, i;
    void *stack;

    // Allocate stack for each thread
    for (i = 0; i < NUM_THREADS; i++) {
        stack = malloc(STACK_SIZE);
        if (stack == NULL) {
            printf("Failed to allocate stack for thread %d\n", i);
            exit(1);
        }
    }

    // Create threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_create(&threads[i], NULL, thread_func, (void *)&i);
        if (rc) {
            printf("Failed to create thread %d: %d\n", i, rc);
            exit(1);
        }
    }

    // Join threads
    for (i = 0; i < NUM_THREADS; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Failed to join thread %d: %d\n", i, rc);
            exit(1);
        }
    }

    printf("All threads joined\n");
    return 0;
}