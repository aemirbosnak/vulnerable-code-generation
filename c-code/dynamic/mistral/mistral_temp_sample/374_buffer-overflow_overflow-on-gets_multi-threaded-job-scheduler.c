#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_JOBS 10
#define JOB_BUFFER_SIZE 256
#define THREAD_COUNT 5

typedef struct {
    char job[JOB_BUFFER_SIZE];
    pthread_t thread_id;
} Job;

Job jobs[MAX_JOBS];
pthread_mutex_t jobs_mutex = PTHREAD_MUTEX_INITIALIZER;

void *execute_job(void *arg) {
    Job *job = (Job *) arg;
    printf("Running job: %s\n", job->job);
    // Add your job execution code here
    sleep(rand() % 5 + 1);
    printf("Job finished: %s\n", job->job);
    return NULL;
}

void add_job(char *job) {
    pthread_mutex_lock(&jobs_mutex);
    for (int i = 0; i < MAX_JOBS; i++) {
        if (!jobs[i].thread_id) {
            strcpy(jobs[i].job, job);
            pthread_create(&jobs[i].thread_id, NULL, execute_job, &jobs[i]);
            break;
        }
    }
    pthread_mutex_unlock(&jobs_mutex);
}

int main() {
    char buffer[10];
    while (1) {
        printf("Enter job (q to quit): ");
        gets(buffer);
        if (strchr(buffer, 'q') || strlen(buffer) == 0)
            break;
        add_job(buffer);
    }
    return 0;
}
