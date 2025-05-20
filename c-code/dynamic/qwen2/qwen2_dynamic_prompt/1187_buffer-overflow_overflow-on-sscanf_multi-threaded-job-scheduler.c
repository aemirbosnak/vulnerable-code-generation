#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

typedef struct {
    int id;
    char command[256];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    if (index >= job_count) return NULL;
    printf("Executing job %d: %s\n", jobs[index].id, jobs[index].command);
    // Simulate job execution time
    sleep(1);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int thread_ids[MAX_JOBS];

    // Populate jobs array with some data
    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        snprintf(jobs[i].command, sizeof(jobs[i].command), "echo Job %d", i + 1);
    }
    job_count = MAX_JOBS;

    // Create threads to execute jobs
    for (int i = 0; i < job_count; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, execute_job, &thread_ids[i]);
    }

    // Join threads
    for (int i = 0; i < job_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
