#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 100

typedef struct {
    char *job;
    char *buffer;
} Job;

Job jobs[MAX_THREADS];
pthread_t threads[MAX_THREADS];

void* work(void* arg) {
    Job* job = (Job*) arg;
    for(int i = 0; i < strlen(job->job); i++) {
        job->buffer[i % BUFFER_SIZE] = job->job[i];
    }
    free(job->job);
    free(job);
    return NULL;
}

int main() {
    for(int i = 0; i < MAX_THREADS; i++) {
        jobs[i].job = malloc(50 * sizeof(char));
        strcpy(jobs[i].job, "Job #");
        snprintf(jobs[i].job + 6, 50 - 6, "%d", i);
        pthread_create(&threads[i], NULL, work, &jobs[i]);
    }

    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
