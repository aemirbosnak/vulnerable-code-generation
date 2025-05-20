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
    // Simulate job execution with a buffer overflow vulnerability
    char buffer[128];
    sscanf(job->command, "%255s", buffer); // Vulnerability here
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        snprintf(jobs[i].command, sizeof(jobs[i].command), "ls -la /path/to/important/data/%d", i);
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
