#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

typedef struct Job {
    void* data;
    void (*func)(void*);
} Job;

static Job* free_job = NULL;

void process_job(Job* job) {
    job->func(job->data);
    free(job);
    free_job = job;
}

void func_a(void* data) {
    printf("Function A executing with data: %p\n", data);
    free(data);
}

void* worker(void* arg) {
    while (true) {
        if (free_job != NULL) {
            Job* temp = free_job;
            free_job = NULL;
            process_job(temp);
        }
    }
    return NULL;
}

int main() {
    pthread_t worker_thread;

    pthread_create(&worker_thread, NULL, &worker, NULL);

    void* data_a = malloc(10);
    memcpy(data_a, "Some data for function A", 10);

    Job job_a = {data_a, func_a};
    free_job = &job_a;

    void* data_b = malloc(20);
    memcpy(data_b, "Some data for function B", 20);

    func_a(data_b); // UB: Calling func_a with incorrect data

    return 0;
}
