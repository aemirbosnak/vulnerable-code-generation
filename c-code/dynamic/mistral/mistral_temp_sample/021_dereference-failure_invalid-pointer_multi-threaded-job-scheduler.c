#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>

typedef struct {
    int id;
    char *job;
} Job;

void *execute_job(void *arg) {
    Job *job = (Job *)arg;
    printf("Executing job: %s (ID: %d)\n", job->job, job->id);
    free(job); // Dereference failure potential
    return NULL;
}

int main() {
    pthread_t threads[10];
    Job jobs[10];

    for (int i = 0; i < 10; ++i) {
        jobs[i].id = i;
        jobs[i].job = (char *)malloc(10 * sizeof(char)); // Insufficient memory allocation
        snprintf(jobs[i].job, 10, "Job %d", i);

        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
