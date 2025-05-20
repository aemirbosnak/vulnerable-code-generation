#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int job[];
} Job;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    printf("Thread %d is starting to execute job %d\n", job->id, job->job[0]);

    // Array bounds violation example
    printf("Thread %d is calculating result: %d + %d\n", job->id, job->job[0], job->job[1]);
    int result = job->job[0] + job->job[1];

    printf("Thread %d is finishing job with result: %d\n", job->id, result);

    pthread_exit(NULL);
}

int main() {
    pthread_t workers[5];
    Job jobs[5];

    for (int i = 0; i < 5; i++) {
        jobs[i].id = i;
        jobs[i].job[0] = i * 10;
        jobs[i].job[1] = i * 5;

        pthread_create(&workers[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < 5; i++) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
