#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_JOBS 100

typedef struct {
    char *command;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
pthread_mutex_t lock;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    pthread_mutex_lock(&lock);
    if (index >= 0 && index < job_count) {
        system(jobs[index].command);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int thread_ids[MAX_JOBS];

    // Simulate adding jobs to the scheduler
    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].command = malloc(256);
        snprintf(jobs[i].command, 256, "echo Job %d", i);
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, execute_job, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Clean up
    for (int i = 0; i < MAX_JOBS; i++) {
        free(jobs[i].command);
    }

    return 0;
}
