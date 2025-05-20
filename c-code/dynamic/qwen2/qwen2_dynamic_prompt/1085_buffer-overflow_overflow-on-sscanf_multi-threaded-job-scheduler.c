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
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* execute_job(void* arg) {
    int index = *(int*)arg;
    pthread_mutex_lock(&mutex);
    if (index >= 0 && index < job_count) {
        printf("Executing job %d: %s\n", jobs[index].id, jobs[index].command);
        // Simulate job execution
        sleep(1);
    }
    pthread_mutex_unlock(&mutex);
    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int thread_ids[MAX_JOBS];

    for (int i = 0; i < MAX_JOBS; i++) {
        jobs[i].id = i + 1;
        snprintf(jobs[i].command, sizeof(jobs[i].command), "echo Job %d", i + 1);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, execute_job, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
