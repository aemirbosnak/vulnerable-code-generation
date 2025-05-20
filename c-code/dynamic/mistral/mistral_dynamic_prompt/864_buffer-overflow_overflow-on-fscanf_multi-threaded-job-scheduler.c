#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 32

typedef struct {
    char name[256];
    char job[256];
} Job;

void* execute_job(void* arg) {
    Job* job = (Job*)arg;
    // Simulate execution of the job with sleep
    sleep(5);
    printf("Executing %s: %s\n", job->name, job->job);
    return NULL;
}

int main() {
    pthread_t worker_threads[10];
    Job jobs[10];

    for (int i = 0; i < 10; ++i) {
        printf("Enter job details (name job) for worker %d:\n", i);
        if (scanf("%s%s", jobs[i].name, jobs[i].job) != 2) {
            printf("Invalid input, try again.\n");
            i--;
            continue;
        }
    }

    for (int i = 0; i < 10; ++i) {
        pthread_create(&worker_threads[i], NULL, execute_job, &jobs[i]);
    }

    // Buffer overflow intentionally introduced here
    char buffer[BUFFER_SIZE];
    if (scanf("%s", buffer) != 1) {
        printf("Invalid input, exiting.\n");
        return 1;
    }

    for (int i = 0; i < 10; ++i) {
        pthread_join(worker_threads[i], NULL);
    }

    return 0;
}
