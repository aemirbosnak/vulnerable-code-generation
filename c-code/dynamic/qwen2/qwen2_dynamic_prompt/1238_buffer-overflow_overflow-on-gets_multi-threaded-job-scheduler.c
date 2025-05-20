#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOB_SIZE 1024

typedef struct {
    char *job;
} Job;

void* execute_job(void* arg) {
    Job *job = (Job*)arg;
    printf("Executing job: %s\n", job->job);
    free(job->job);
    free(job);
    return NULL;
}

int main() {
    pthread_t threads[10];
    Job jobs[10];

    for (int i = 0; i < 10; i++) {
        jobs[i].job = (char*)malloc(MAX_JOB_SIZE);
        if (!jobs[i].job) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE);
        }
        snprintf(jobs[i].job, MAX_JOB_SIZE, "Job %d", i);
        if (pthread_create(&threads[i], NULL, execute_job, &jobs[i]) != 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("Failed to join thread");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
