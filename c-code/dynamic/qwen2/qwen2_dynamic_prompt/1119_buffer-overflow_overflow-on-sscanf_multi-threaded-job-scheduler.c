#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 10

typedef struct {
    int id;
    char command[256];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    printf("Executing job %d: %s\n", job->id, job->command);
    // Simulate job execution with a sleep
    sleep(1);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];

    // Add jobs to the queue
    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        snprintf(jobs[i].command, sizeof(jobs[i].command), "echo Job %d", i + 1);
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
