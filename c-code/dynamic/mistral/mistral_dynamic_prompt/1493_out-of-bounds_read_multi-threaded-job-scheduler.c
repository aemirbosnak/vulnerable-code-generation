#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 10

typedef struct {
    int id;
    char* buffer;
} Job;

void* worker(void* arg) {
    Job* job = (Job*) arg;
    char* data = job->buffer;

    // Out-of-bounds read example
    printf("Thread %d: Reading %d bytes from memory at address %p\n", job->id, job->id * 100, &data[job->id * 100]);

    return NULL;
}

int main() {
    Job* jobs = (Job*) malloc(NUM_THREADS * sizeof(Job));

    for (int i = 0; i < NUM_THREADS; ++i) {
        jobs[i].id = i;
        jobs[i].buffer = (char*) malloc(sizeof(char) * 100);
    }

    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_create(&threads[i], NULL, worker, &jobs[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        free(jobs[i].buffer);
    }
    free(jobs);

    return 0;
}
