#include <string.h>
#include <stdint.h>
#include <stddef.h>

#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    void* data;
    void (*func)(void*);
} Job;

void run_job(void* args) {
    Job* job = (Job*)args;
    job->func(job->data);
}

void job_scheduler(Job* jobs, int size) {
    pthread_t threads[size];
    for (int i = 0; i < size; ++i) {
        pthread_create(&threads[i], NULL, run_job, jobs + i);
    }

    for (int i = 0; i < size; ++i) {
        pthread_join(threads[i], NULL);
    }
}

// Job function with a deliberate null pointer dereference vulnerability
void handle_data(void* data) {
    int* numbers = (int*)data;
    printf("Processing data: %d\n", numbers[0]);
    printf("Result: %d\n", numbers[1] * 2); // Dereferencing non-allocated memory
}

int main() {
    int* numbers = (int*)malloc(sizeof(int) * 2);
    numbers[0] = 5;

    Job jobs[] = {
        {&numbers, handle_data},
        {NULL, NULL}, // Null job
    };

    job_scheduler(jobs, sizeof(jobs) / sizeof(Job));

    return 0;
}
