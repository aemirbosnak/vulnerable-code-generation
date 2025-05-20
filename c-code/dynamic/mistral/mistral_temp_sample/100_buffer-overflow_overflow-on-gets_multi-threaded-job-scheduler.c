#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 16

typedef struct Job {
    char name[BUFFER_SIZE];
    void (*function)(void*);
    void* argument;
} Job;

Job jobs[MAX_JOBS];
pthread_mutex_t job_list_mutex = PTHREAD_MUTEX_INITIALIZER;

void job_function(void* arg) {
    printf("Running job: %s\n", ((Job*)arg)->name);
}

void add_job(Job job) {
    pthread_mutex_lock(&job_list_mutex);
    for (int i = 0; i < MAX_JOBS; ++i) {
        if (!jobs[i].function) {
            jobs[i] = job;
            pthread_create(&jobs[i].function, NULL, &job_function, &jobs[i]);
            break;
        }
    }
    pthread_mutex_unlock(&job_list_mutex);
}

int main() {
    char buffer[10];

    printf("Multi-threaded Job Scheduler\n");
    while (1) {
        printf("Enter job name (or 'q' to quit): ");
        gets(buffer);

        if (strcmp(buffer, "q") == 0) {
            break;
        }

        Job job;
        strcpy(job.name, buffer);
        job.function = NULL;
        job.argument = NULL;

        add_job(job);
    }

    return 0;
}
