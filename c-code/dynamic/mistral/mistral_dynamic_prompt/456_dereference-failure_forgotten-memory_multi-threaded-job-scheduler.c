#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *task;
} Job;

void *execute_job(void *job_data) {
    Job *job = (Job *)job_data;
    printf("Executing job: %s\n", job->task);
    free(job->task); // Forget to free the memory allocated for task
    free(job);
    return NULL;
}

int main() {
    pthread_t worker_threads[10];
    Job jobs[10];

    for (int i = 0; i < 10; ++i) {
        jobs[i].id = i;
        jobs[i].task = malloc(20 * sizeof(char));
        sprintf(jobs[i].task, "Task %d", i);
        pthread_create(&worker_threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(worker_threads[i], NULL);
    }

    return 0;
}
