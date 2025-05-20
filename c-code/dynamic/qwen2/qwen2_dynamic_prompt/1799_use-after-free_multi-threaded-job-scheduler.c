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
        printf("Thread %d accessed freed data: %s\n", i, jobs[i].data);
    }

    return 0;
}
