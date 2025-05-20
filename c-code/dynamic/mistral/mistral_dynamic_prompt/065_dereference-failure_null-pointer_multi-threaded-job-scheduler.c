#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void* data;
    void (*function)(void*);
} Job;

void broken_function(void* arg) {
    printf("Running broken function.\n");
    ((int*) arg)[0] += 100; // Dereference null pointer
}

void execute_job(Job job) {
    pthread_t thread_id;
    int* data = malloc(sizeof(int));
    *data = 123;

    job.data = data;
    job.function = &broken_function;

    pthread_create(&thread_id, NULL, job.function, job.data);
}

void clean_up(void* arg) {
    free(arg);
}

int main() {
    Job job = {NULL, &broken_function};
    pthread_t thread_id;

    pthread_create(&thread_id, NULL, job.function, job.data);

    execute_job((Job){.function = &clean_up, .data = &job.data});

    pthread_join(thread_id, NULL);

    return 0;
}
