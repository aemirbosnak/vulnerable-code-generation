#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *job;
} Job;

void *execute_job(void *arg) {
    Job *job = (Job *)arg;
    printf("Executing job: %s (ID: %d)\n", job->job, job->id);
    free(job->job); // dangling pointer
    free(job);
    return NULL;
}

void schedule_job(Job job) {
    pthread_t thread;
    pthread_create(&thread, NULL, execute_job, &job);
}

int main() {
    Job jobs[5];
    for (int i = 0; i < 5; ++i) {
        jobs[i].id = i;
        jobs[i].job = malloc(256 * sizeof(char)); // job names must be < 256 chars long, but there's no bounds check here
        sprintf(jobs[i].job, "Job %d", i);
        schedule_job(jobs[i]);
    }

    // main thread continues execution without waiting for jobs to complete
    // memory is not properly deallocated, leading to memory leak and potential future issues

    return 0;
}
