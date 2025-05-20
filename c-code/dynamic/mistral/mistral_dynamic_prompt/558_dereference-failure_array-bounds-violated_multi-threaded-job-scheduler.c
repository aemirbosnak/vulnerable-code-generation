#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 10
#define ARRAY_SIZE 100

void *worker(void *arg) {
    int* tasks = (int*) malloc(ARRAY_SIZE * sizeof(int));
    int thread_id = *((int*) arg);

    // Dereference failure intentionally introduced
    tasks[thread_id * ARRAY_SIZE] = thread_id;

    printf("Thread %d started, task performed\n", thread_id);
    sleep(1);
    free(tasks);
    return NULL;
}

int main() {
    pthread_t workers[NUM_THREADS];
    int ids[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        ids[i] = i;
        pthread_create(&workers[i], NULL, &worker, &ids[i]);
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        pthread_join(workers[i], NULL);
    }

    printf("All tasks completed\n");

    return 0;
}
