#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_JOBS 100
#define JOB_NAME_SIZE 256

typedef struct {
    int id;
    char name[JOB_NAME_SIZE];
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
pthread_mutex_t mutex;

void* scheduler(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);
        if (job_count > 0) {
            Job job = jobs[--job_count];
            printf("Executing job %d: %s\n", job.id, job.name);
        } else {
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[4];
    pthread_mutex_init(&mutex, NULL);

    // Create scheduler threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, scheduler, NULL);
    }

    // Simulate adding jobs
    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_mutex_lock(&mutex);
        jobs[job_count].id = i;
        printf("Enter job name for job %d: ", i);
        gets(jobs[job_count].name);  // Vulnerable to buffer overflow
        job_count++;
        pthread_mutex_unlock(&mutex);
    }

    // Wait for all jobs to be processed
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}
