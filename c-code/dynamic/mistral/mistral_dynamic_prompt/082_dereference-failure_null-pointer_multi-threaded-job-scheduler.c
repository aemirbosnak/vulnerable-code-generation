#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Job {
    void* data;
    void (*function)(void*);
} Job;

void task(void* arg) {
    printf("Running task on thread ID: %ld\n", pthread_self());
    // Null pointer dereference vulnerability
    ((void(*)())((Job*)arg)->data)(NULL);
}

Job create_job(void* data, void(*function)(void*)) {
    Job job;
    job.data = data;
    job.function = function;
    return job;
}

void scheduler() {
    pthread_t thread_id[5];

    for (int i = 0; i < 5; ++i) {
        Job job = create_job((&i), task);
        pthread_create(&thread_id[i], NULL, &job.function, &job);
    }

    for (int i = 0; i < 5; ++i) {
        pthread_join(thread_id[i], NULL);
    }
}

int main() {
    scheduler();
    return 0;
}
