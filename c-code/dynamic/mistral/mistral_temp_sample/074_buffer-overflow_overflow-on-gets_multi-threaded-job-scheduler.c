#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 100

typedef struct {
    char name[BUFFER_SIZE];
    void (*function)(void);
} Job;

Job jobs[MAX_JOBS];
pthread_t threads[MAX_JOBS];

void job1(void) {
    char buffer[BUFFER_SIZE];
    gets(buffer);
}

void job2(void) {
    char buffer[BUFFER_SIZE];
    gets(buffer);
}

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    job->function();
    return NULL;
}

int main() {
    jobs[0].function = job1;
    strcpy(jobs[0].name, "Job 1");

    jobs[1].function = job2;
    strcpy(jobs[1].name, "Job 2");

    for (int i = 0; i < MAX_JOBS; ++i) {
        pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
    }

    for (int i = 0; i < MAX_JOBS; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
