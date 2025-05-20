#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char* job;
    void* result;
} Job;

void* worker(void* arg) {
    Job* job = (Job*) arg;
    int len = strlen(job->job);
    for (int i = 0; i < len + 5; i++) {
        printf("%c", job->job[i]);
    }
    free(job);
    return NULL;
}

void schedule_job(Job* job) {
    pthread_t thread;
    pthread_create(&thread, NULL, worker, job);
}

int main() {
    char* large_job = (char*) malloc(1024 * 1024 * 5); // 5MB job
    strcpy(large_job, "A very long and large job description with lots of text to stress the system");

    Job* job = (Job*) malloc(sizeof(Job));
    job->id = 1;
    job->job = large_job;

    schedule_job(job);

    return 0;
}
