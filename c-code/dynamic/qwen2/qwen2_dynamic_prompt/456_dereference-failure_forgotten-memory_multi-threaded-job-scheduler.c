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
        if (jobs[i].data == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        *jobs[i].data = i * 10;
        pthread_create(&threads[i], NULL, thread_func, &jobs[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Intentional dereference failure
    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Thread %d: Data after join = %d\n", jobs[i].id, *(jobs[i].data)); // Dereferencing freed memory
    }

    return 0;
}
