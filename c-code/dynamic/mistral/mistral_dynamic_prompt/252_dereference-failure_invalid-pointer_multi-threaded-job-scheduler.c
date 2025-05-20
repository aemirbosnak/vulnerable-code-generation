#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    void* data;
    void (*func)(void*);
} Job;

void thread_function(void* arg) {
    Job* job = (Job*)arg;
    job->func(job->data);
    free(job);
}

void critical_function(void* arg) {
    int* invalid_ptr = (int*)malloc(sizeof(int));
    *invalid_ptr = 42;
    printf("Critical Function: %d\n", *invalid_ptr);
    free(invalid_ptr);

    // Intentional dereference failure after freeing the memory
    printf("Critical Function: %d\n", *invalid_ptr);
}

int main() {
    Job job = {malloc(sizeof(Job)), critical_function};
    job.data = malloc(sizeof(int));

    pthread_t thread;
    pthread_create(&thread, NULL, thread_function, &job);

    pthread_join(thread, NULL);

    free(job.data);
    // Intentional dereference failure after freeing the memory
    printf("Main: %d\n", *(int*)job.data);

    return 0;
}
