#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int id;
    char *data;
} Job;

void* thread_func(void* arg) {
    Job *job = (Job*)arg;
    printf("Thread %d processing data: %s\n", job->id, job->data);
    sleep(1); // Simulate work
    free(job->data); // Free memory
    job->data = NULL; // Set pointer to NULL
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    Job jobs[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        jobs[i].id = i;
        jobs[i].data = (char*)malloc(20 * sizeof(char));
        sprintf(jobs[i].data, "Data for thread %d", i);
        pthread_create(&threads[i], NULL, thread_func, &jobs[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Use-after-free vulnerability
    for (int i = 0; i < NUM_THREADS; i++) {
        if (jobs[i].data != NULL) {
            printf("Use-after-free: Thread %d tried to access freed data: %s\n", jobs[i].id, jobs[i].data);
        }
    }

    return 0;
}
