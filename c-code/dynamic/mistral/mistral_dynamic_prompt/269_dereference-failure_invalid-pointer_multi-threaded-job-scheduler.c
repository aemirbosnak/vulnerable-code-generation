#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct Job {
    void* function;
    void* arg;
} Job;

void* worker(void* data) {
    Job* job = (Job*) data;
    ((void(*)()) job->function)(job->arg);
    return NULL;
}

void unsafe_function(void* arg) {
    int* arr = (int*) arg;
    printf("Value at arr[1000]: %d\n", arr[1000]);
}

int main() {
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Job jobs[5];

    for (int i = 0; i < 5; ++i) {
        jobs[i].function = unsafe_function;
        jobs[i].arg = &arr;
        pthread_t tid;
        pthread_create(&tid, NULL, worker, &jobs[i]);
    }

    sleep(1);

    return 0;
}
