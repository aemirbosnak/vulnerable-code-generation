#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    void (*func)(void*);
    void* arg;
} Job;

void* worker(void* data) {
    Job* job = (Job*)data;
    job->func(job->arg);
    return NULL;
}

void dangerous_function(void* arg) {
    int* ptr = (int*)arg;
    printf("Dangerous Function - Value before dereference: %d\n", *ptr);
    printf("Dangerous Function - Value after dereference: %d\n", *ptr * 2);
}

int main() {
    pthread_t workers[10];
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; ++i) {
        Job jobs[i];
        jobs[i].func = dangerous_function;
        jobs[i].arg = &arr[i];

        pthread_create(&workers[i], NULL, worker, &jobs[i]);
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
