#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_THREADS 100
#define JOB_SIZE 1025

typedef struct {
    char name[256];
    void* arg;
    void (*function)(void*);
} Job;

Job jobs[MAX_THREADS];
pthread_t threads[MAX_THREADS];

void run_job(void* arg) {
    Job* job = (Job*)arg;
    job->function(job->arg);
}

void example_function(void* num) {
    int i, overflow = atoi(num);
    for (i = 0; i < 100000000; i++) {
        overflow += i * i;
    }
    printf("Finished job with argument %d\n", overflow);
}

void* start_threads(void) {
    int i;

    for (i = 0; i < MAX_THREADS; i++) {
        sprintf(jobs[i].name, "Thread %d", i);
        jobs[i].function = &example_function;
        jobs[i].arg = malloc(sizeof(int));
        *((int*)jobs[i].arg) = i * 100;
        pthread_create(&threads[i], NULL, &run_job, &jobs[i]);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return NULL;
}

int main() {
    pthread_t main_thread;
    pthread_create(&main_thread, NULL, &start_threads, NULL);
    pthread_join(main_thread, NULL);

    return 0;
}
