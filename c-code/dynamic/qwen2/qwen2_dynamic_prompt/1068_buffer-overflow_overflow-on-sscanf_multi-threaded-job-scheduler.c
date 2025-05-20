#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

typedef struct {
    int id;
    char command[256];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
pthread_mutex_t lock;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    pthread_mutex_lock(&lock);
    if (index >= 0 && index < job_count) {
        printf("Executing job %d: %s\n", jobs[index].id, jobs[index].command);
        // Vulnerability: Buffer overflow in sscanf
        int num_args;
        sscanf(jobs[index].command, "%d", &num_args);
        printf("Number of arguments: %d\n", num_args);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    pthread_mutex_init(&lock, NULL);

    // Simulate adding jobs to the scheduler
    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        snprintf(jobs[i].command, sizeof(jobs[i].command), "job%d %s", i + 1, "some data");
        job_count++;
    }

    // Create threads to execute jobs
    for (int i = 0; i < job_count; i++) {
        pthread_create(&threads[i], NULL, execute_job, &i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < job_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}
