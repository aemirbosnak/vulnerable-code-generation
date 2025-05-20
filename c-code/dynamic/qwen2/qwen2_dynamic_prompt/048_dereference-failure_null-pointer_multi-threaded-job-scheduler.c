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
    if (job->data == NULL) {
        printf("Thread %d: Null pointer dereference\n", job->id);
        return NULL;
    }
    printf("Thread %d: Data = %d\n", job->id, *(job->data));
    free(job->data);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    Job jobs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = malloc(sizeof(int));
        if (jobs[i].data != NULL) {
            *jobs[i].data = i * 10;
        } else {
            printf("Failed to allocate memory for thread %d\n", i);
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_func, &jobs[i]) != 0) {
            printf("Failed to create thread %d\n", i);
            exit(1);
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
