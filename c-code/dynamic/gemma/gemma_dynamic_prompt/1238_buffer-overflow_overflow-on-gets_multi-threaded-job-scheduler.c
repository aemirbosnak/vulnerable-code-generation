#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 10

typedef struct Job {
    char name[256];
    int priority;
    pthread_t thread;
} Job;

void* job_thread(void* arg) {
    Job* job = (Job*)arg;
    printf("Job %s is running\n", job->name);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    Job jobs[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].priority = i;
        gets(jobs[i].name);
        pthread_create(&threads[i], NULL, job_thread, &jobs[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
