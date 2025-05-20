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
    Job* job = (Job*)arg;
    if (job->id == 3) {
        // Deliberate invalid pointer dereference
        printf("Thread %d: Dereferencing invalid pointer\n", job->id);
        int value = *(job->data); // Invalid read
        printf("Value: %d\n", value);
    } else {
        printf("Thread %d: Processing data\n", job->id);
        *job->data += job->id; // Valid write
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    Job jobs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = malloc(sizeof(int));
        if (jobs[i].data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        *jobs[i].data = i * 10;
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, &jobs[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        free(jobs[i].data);
    }

    return 0;
}
