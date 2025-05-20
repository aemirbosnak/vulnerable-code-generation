#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 10

typedef struct {
    int id;
    char command[256];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    pthread_mutex_lock(&mutex);
    if (index >= 0 && index < job_count) {
        printf("Executing job %d: %s\n", jobs[index].id, jobs[index].command);
        // Vulnerability: Buffer overflow in sscanf
        sscanf(jobs[index].command, "%255s", jobs[index].command); // Overflow here
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];

    // Create some jobs
    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        snprintf(jobs[i].command, sizeof(jobs[i].command), "echo Job %d", i + 1);
        job_count++;
    }

    // Execute jobs in separate threads
    for (int i = 0; i < job_count; i++) {
        pthread_create(&threads[i], NULL, execute_job, &i);
    }

    // Wait for all threads to finish
    for (int i = 0; i < job_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
