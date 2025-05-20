#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct Job {
    char *data;
    size_t len;
    pthread_t thread_id;
    pthread_t *parent;
    struct Job *next;
} Job;

void *job_func(void *arg) {
    Job *job = (Job *)arg;
    printf("Executing job: %.*s\n", job->len, job->data);
    free(job->data);
    job->data = NULL;
    job->len = 0;
    if (job->parent) {
        *job->parent = (Job *)job->next;
        pthread_t *tmp = &job->thread_id;
        void *status;
        pthread_join(*tmp, &status);
    }
    free(job);
    return NULL;
}

void add_job(Job **jobs, const char *data, size_t len, Job *parent) {
    Job *job = (Job *)malloc(sizeof(Job));
    job->data = malloc(len);
    memcpy(job->data, data, len);
    job->len = len;
    job->parent = &parent;
    job->next = *jobs;
    *jobs = job;
    pthread_create(&job->thread_id, NULL, job_func, job);
}

int main() {
    Job *jobs = NULL;

    add_job(&jobs, "Task 1", 8, NULL);
    add_job(&jobs, "Task 2", 5, &jobs);
    add_job(&jobs, "Task 3", 7, &jobs);
    add_job(&jobs, "Task 4", 6, &jobs);

    while (jobs != NULL) {
        sleep(1);
    }

    return 0;
}
