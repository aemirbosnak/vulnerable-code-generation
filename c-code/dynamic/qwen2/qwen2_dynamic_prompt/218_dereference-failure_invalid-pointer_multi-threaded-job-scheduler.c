#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct {
    int id;
    int *data;
} Job;

void* thread_func(void* arg) {
    Job *job = (Job*)arg;
    if (job->id == 2) {
        // Deliberate invalid pointer dereference
        printf("Thread %d: Dereferencing invalid pointer\n", job->id);
        int value = *(job->data); // Invalid dereference
        printf("Value: %d\n", value);
    } else {
        printf("Thread %d: Processing data\n", job->id);
        *job->data += job->id;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    Job jobs[NUM_THREADS];

    int shared_data = 0;

    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = &shared_data;
        pthread_create(&threads[i], NULL, thread_func, &jobs[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final value of shared data: %d\n", shared_data);

    return 0;
}
