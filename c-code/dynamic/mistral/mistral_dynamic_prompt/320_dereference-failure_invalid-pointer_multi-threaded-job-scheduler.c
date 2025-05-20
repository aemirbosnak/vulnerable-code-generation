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

void work(void* data) {
    printf("Working on data: %p\n", data);
    free(data);
}

void* scheduler(void* arg) {
    Job* job = (Job*)arg;
    job->func(job->data);
    free(job);
    return NULL;
}

int main() {
    void* data = malloc(10);
    Job* job = malloc(sizeof(Job));
    job->data = data;
    job->func = &work;

    pthread_t thread;
    pthread_create(&thread, NULL, scheduler, (void*)job);

    pthread_t another_thread;
    pthread_create(&another_thread, NULL, scheduler, (void*)NULL);

    // Use the 'data' pointer after it has been freed by the first thread, causing a dereference failure
    printf("Using data: %p\n", data);

    pthread_join(thread, NULL);
    pthread_join(another_thread, NULL);

    return 0;
}
