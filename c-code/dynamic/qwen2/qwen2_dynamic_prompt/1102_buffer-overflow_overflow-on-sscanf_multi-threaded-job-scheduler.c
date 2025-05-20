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
    char buffer[256];
    
    // Vulnerability: Buffer overflow due to insufficient check on input length
    sscanf(job->job, "%255s", buffer);
    
    printf("Executing job: %s\n", buffer);
    free(job);
    return NULL;
}

int main() {
    pthread_t threads[10];
    Job jobs[10];

    for (int i = 0; i < 10; i++) {
        jobs[i].job = malloc(MAX_JOB_SIZE);
        sprintf(jobs[i].job, "Long job description that will cause buffer overflow if not properly handled");
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
