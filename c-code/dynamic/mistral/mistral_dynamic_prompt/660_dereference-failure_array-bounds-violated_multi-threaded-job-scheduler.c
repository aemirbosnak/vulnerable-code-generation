#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Job {
    char* task;
    int thread_id;
} Job;

void* execute_job(void* job) {
    Job* job_data = (Job*) job;
    char* task = job_data->task;
    int thread_id = job_data->thread_id;

    printf("Thread %d: Running task: %s\n", thread_id, task);

    // Intentional array bounds violation
    char buffer[5];
    strcpy(buffer, task);
    printf("Thread %d: Result: %s\n", thread_id, buffer + strlen(buffer));

    free(job_data);
    return NULL;
}

void create_and_run_job(char* task, int thread_count) {
    Job* job = malloc(sizeof(Job));
    job->task = task;
    job->thread_id = pthread_self();

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, execute_job, job);

    if (--thread_count == 0) {
        pthread_exit(0);
    }
}

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <job_count> <task>\n", argv[0]);
        return 1;
    }

    int job_count = atoi(argv[1]);
    char* task = argv[2];

    pthread_t thread_ids[job_count];

    for (int i = 0; i < job_count; ++i) {
        create_and_run_job(task, job_count);
    }

    void* status;
    for (int i = 0; i < job_count; ++i) {
        pthread_join(thread_ids[i], &status);
    }

    return 0;
}
