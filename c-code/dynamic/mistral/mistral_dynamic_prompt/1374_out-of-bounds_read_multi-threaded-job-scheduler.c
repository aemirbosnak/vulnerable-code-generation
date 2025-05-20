#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 5

typedef struct {
    int id;
    char job[10];
} Job;

Job jobs[NUM_THREADS];
pthread_t workers[NUM_THREADS];

void *worker(void *arg) {
    int id = *(int *)arg;
    char job[10];

    // Read job beyond the allocated array, causing a buffer overflow
    strcpy(job, jobs[id].job);

    printf("Thread %d: Job is %s\n", id, job);
    free(arg);
    return NULL;
}

void init_jobs() {
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        sprintf(jobs[i].job, "Job %d", i);
        pthread_create(&workers[i], NULL, &worker, &i);
    }
}

int main() {
    init_jobs();
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(workers[i], NULL);
    }
    return 0;
}
