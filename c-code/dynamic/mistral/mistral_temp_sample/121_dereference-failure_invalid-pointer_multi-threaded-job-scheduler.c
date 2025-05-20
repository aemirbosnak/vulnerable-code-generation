#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    void (*function)(void*);
    void* arguments;
} Job;

void dereference_error(void* arg) {
    int* ptr = (int*) arg;
    printf("Result: %d\n", *ptr);
}

void* worker(void* job) {
    Job* job_data = (Job*) job;
    (job_data->function)(job_data->arguments);
    free(job_data);
    return NULL;
}

int main() {
    int* invalid_ptr = malloc(1);
    *invalid_ptr = -1;

    Job job = {dereference_error, invalid_ptr};
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, worker, &job);
    pthread_join(thread_id, NULL);

    free(invalid_ptr);

    return 0;
}
