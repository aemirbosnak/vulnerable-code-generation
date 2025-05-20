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
    char buffer[MAX_JOB_SIZE];
    
    // Vulnerability: Buffer overflow via sscanf
    sscanf(job->job, "%1023s", buffer);
    
    printf("Executing job: %s\n", buffer);
    free(job);
    return NULL;
}

int main() {
    pthread_t threads[10];
    Job jobs[10];

    for (int i = 0; i < 10; i++) {
        jobs[i].job = malloc(2048); // Allocate more than MAX_JOB_SIZE to trigger overflow
        sprintf(jobs[i].job, "Long job description that will cause buffer overflow if not handled properly");
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
