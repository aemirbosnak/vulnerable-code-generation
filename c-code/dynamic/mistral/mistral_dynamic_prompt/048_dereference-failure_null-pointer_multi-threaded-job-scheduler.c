#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    void* function;
    void* arg;
} Job;

void* work_function(void* arg) {
    printf("Working on job: %p\n", arg);
    // Simulate a null pointer dereference
    ((int*) arg)[0] = 42;
    return NULL;
}

void job_scheduler() {
    pthread_t worker;
    Job job = { work_function, (void*) malloc(sizeof(int)) };

    pthread_create(&worker, NULL, job.function, job.arg);
    pthread_join(worker, NULL);

    free(job.arg);
}

int main() {
    for (int i = 0; i < 10; i++) {
        job_scheduler();
    }

    return 0;
}
