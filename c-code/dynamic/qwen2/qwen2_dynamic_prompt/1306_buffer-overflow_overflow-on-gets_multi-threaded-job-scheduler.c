#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_JOBS 100
#define JOB_SIZE 256

typedef struct {
    char job[JOB_SIZE];
    int id;
} Job;

Job jobs[MAX_JOBS];
int job_count = 0;
pthread_mutex_t mutex;

void* worker(void* arg) {
    int id = *(int*)arg;
    while (1) {
        pthread_mutex_lock(&mutex);
        if (job_count > 0) {
            strcpy(jobs[id].job, "Executing job");
            printf("Worker %d: Executing job %s\n", id, jobs[id].job);
            job_count--;
        } else {
            pthread_mutex_unlock(&mutex);
            break;
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t threads[MAX_JOBS];
    int thread_ids[MAX_JOBS];

    pthread_mutex_init(&mutex, NULL);

    // Create worker threads
    for (int i = 0; i < MAX_JOBS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, worker, &thread_ids[i]);
    }

    // Simulate adding jobs to the queue
    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_mutex_lock(&mutex);
        strcpy(jobs[job_count].job, "New job");
        jobs[job_count].id = job_count;
        job_count++;
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    // Wait for all workers to finish
    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
