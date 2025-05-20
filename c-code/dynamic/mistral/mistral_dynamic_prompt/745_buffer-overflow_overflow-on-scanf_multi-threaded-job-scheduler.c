#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char *job;
    pthread_t tid;
} Job;

void *run_job(void *arg) {
    Job *job = (Job *)arg;
    printf("Running job: %s\n", job->job);
    sleep(atoi(job->job));
    free(job->job);
    free(job);
    return NULL;
}

int main() {
    int num_jobs;
    printf("Enter number of jobs:\n");
    scanf("%d", &num_jobs);

    Job *jobs = (Job *)calloc(num_jobs, sizeof(Job));

    for (int i = 0; i < num_jobs; ++i) {
        jobs[i].job = (char *)malloc(100 * sizeof(char));
        printf("Enter job for thread %d:\n", i);
        scanf("%s", jobs[i].job);
        pthread_create(&jobs[i].tid, NULL, run_job, &jobs[i]);
    }

    for (int i = 0; i < num_jobs; ++i) {
        pthread_join(jobs[i].tid, NULL);
    }

    free(jobs);
    return 0;
}
