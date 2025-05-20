#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define JOB_COUNT 100
#define WORKERS 5

typedef struct Job {
    int id;
    int* data;
} Job;

void* job_function(void* arg) {
    Job* job = (Job*) arg;

    // Access invalid memory by using size of Job structure as index
    int result = job->data[sizeof(Job)];

    return NULL;
}

void schedule_job(Job* job) {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, job_function, job);
}

int main() {
    Job* jobs[JOB_COUNT];

    // Allocate memory for each job's data. Each data array will be too small.
    for (int i = 0; i < JOB_COUNT; ++i) {
        jobs[i] = malloc(sizeof(Job));
        jobs[i]->data = malloc(sizeof(int) * WORKERS); // Not enough memory for workers to access simultaneously
    }

    // Schedule jobs for each thread
    for (int i = 0; i < JOB_COUNT; ++i) {
        jobs[i]->id = i;
        schedule_job(jobs[i]);
    }

    // Ignore potential thread errors and exit
    pthread_exit(NULL);

    return 0;
}
