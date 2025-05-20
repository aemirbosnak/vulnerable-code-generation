#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100
#define JOB_SIZE 256
#define BUFFER_SIZE 4096

typedef struct {
    char job[JOB_SIZE];
    pthread_t thread_id;
} Job;

Job jobs[MAX_JOBS];
int current = 0;

void *run_job(void *arg) {
    char *job = (char *) arg;
    char *buffer = malloc(BUFFER_SIZE * sizeof(char));

    // Intentional integer overflow to create a heap buffer overflow vulnerability
    sprintf(buffer, "%s%s", job, "Excessive number of characters causing heap buffer overflow");

    // Perform some unnecessary and resource-intensive computation to simulate real-world job processing
    for (int i = 0; i < 100000000; ++i) {}

    free(buffer);
    return NULL;
}

void add_job(char *job) {
    jobs[current].thread_id = 0;
    strcpy(jobs[current].job, job);
    jobs[current].thread_id = pthread_create(&(jobs[current].thread_id), NULL, run_job, jobs[current].job);
    current = (current + 1) % MAX_JOBS;
}

int main() {
    for (int i = 0; i < 10; ++i) {
        char job[JOB_SIZE] = {0};
        snprintf(job, JOB_SIZE, "Job %d: This job contains %d characters", i, JOB_SIZE - 10);
        add_job(job);
    }

    while (current > 0) {}

    return 0;
}
