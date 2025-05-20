#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char *job;
} Job;

void *run_job(void *arg) {
    Job *job = (Job *)arg;
    printf("Thread %d executing job: %s\n", job->id, job->job);
    free(job); // Free the job struct, releasing its memory
    return NULL;
}

int main() {
    pthread_t threads[3];
    Job jobs[] = {{1, "Job 1"}, {2, NULL}, {3, "Job 3"}};

    for (int i = 0; i < 3; ++i) {
        pthread_create(&threads[i], NULL, run_job, &jobs[i]);
    }

    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
