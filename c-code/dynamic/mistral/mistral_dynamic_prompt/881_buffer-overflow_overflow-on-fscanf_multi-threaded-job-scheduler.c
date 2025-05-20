#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 10
#define BUFFER_SIZE 64

typedef struct {
    char *job;
    pthread_t thread_id;
} Job;

void* execute_job(void *arg) {
    Job *job = (Job *) arg;
    printf("Executing job: %s\n", job->job);
    free(job->job);
    free(job);
    return NULL;
}

int main() {
    char buffer[BUFFER_SIZE];
    Job *jobs[MAX_THREADS];
    pthread_t threads[MAX_THREADS];

    int i, num_jobs;
    printf("Job Scheduler\n");

    while (1) {
        printf("Enter number of jobs (or 0 to exit): ");
        fscanf(stdin, "%*d%*c%s", buffer);
        num_jobs = strlen(buffer);

        for (i = 0; i < num_jobs; ++i) {
            jobs[i] = (Job *) malloc(sizeof(Job) + num_jobs - i - 1);
            strcpy(jobs[i]->job, buffer + i);
            pthread_create(&threads[i], NULL, execute_job, jobs[i]);
        }
    }

    return 0;
}
