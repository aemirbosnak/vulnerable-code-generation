#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_JOBS 10

typedef struct {
    int id;
    void* (*function)(void*);
    void* arg;
} Job;

Job jobs[MAX_JOBS];
pthread_t threads[MAX_JOBS];

void* do_work(void* arg) {
    int i = *(int*)arg;
    printf("Starting job %d\n", i);
    // Simulate some work...
    usleep(1000000 * i);
    printf("Job %d completed\n", i);
    return NULL;
}

void scheduler() {
    for (int i = 0; i < MAX_JOBS; ++i) {
        int* job_id = malloc(sizeof(int));
        *job_id = i;
        jobs[i].id = i;
        jobs[i].function = do_work;
        jobs[i].arg = job_id;
        pthread_create(&threads[i], NULL, jobs[i].function, jobs[i].arg);
    }
}

int main() {
    scheduler();
    for (int i = 0; i < MAX_JOBS; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}
