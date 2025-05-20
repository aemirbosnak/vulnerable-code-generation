#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 64

typedef struct Job {
    char name[BUFFER_SIZE];
    void (*func)(void* arg);
    void* arg;
} Job;

Job job_list[MAX_JOBS];
pthread_mutex_t job_list_lock;
int jobs_count = 0;

void job_function(void* arg) {
    printf("Running job: %s\n", ((Job*)arg)->name);
    sleep(1);
}

void add_job(Job job) {
    pthread_mutex_lock(&job_list_lock);
    job_list[jobs_count++] = job;
    pthread_mutex_unlock(&job_list_lock);
}

void* run_jobs(void* arg) {
    int i;
    for (i = 0; i < jobs_count; i++) {
        (*(job_list[i].func))(job_list[i].arg);
    }
    return NULL;
}

int main() {
    int i;
    pthread_t job_thread;

    for (i = 0; i < 10; i++) {
        Job job;
        sprintf(job.name, "Job_%d", i);
        job.func = &job_function;
        job.arg = NULL;
        add_job(job);
    }

    pthread_create(&job_thread, NULL, &run_jobs, NULL);

    char input[BUFFER_SIZE];
    gets(input); // Vulnerable section with buffer overflow

    return 0;
}
