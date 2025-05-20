#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    int id;
    void* data;
    void (*function)(void*);
} Job;

void job_function_a(void* args) {
    // Valid code for function A
    printf("Function A executing job %d\n", ((Job*)args)->id);
}

void job_function_b(void* args) {
    // Vulnerable code for function B, dereferencing an invalid pointer
    int* invalid_ptr = (int*)malloc(sizeof(int));
    (*invalid_ptr) = 42;
    printf("Function B executing job %d, result: %d\n", ((Job*)args)->id, *invalid_ptr);
}

void job_scheduler(Job* jobs, int num_jobs) {
    pthread_t threads[num_jobs];
    for (int i = 0; i < num_jobs; ++i) {
        pthread_create(&threads[i], NULL, jobs[i].function, &jobs[i]);
    }

    for (int i = 0; i < num_jobs; ++i) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    Job jobs[2] = {
        {.id = 1, .data = malloc(sizeof(Job)), .function = job_function_a},
        {.id = 2, .data = malloc(sizeof(Job)), .function = job_function_b}
    };

    job_scheduler(jobs, 2);

    for (int i = 0; i < 2; ++i) {
        free(jobs[i].data);
    }

    return 0;
}
