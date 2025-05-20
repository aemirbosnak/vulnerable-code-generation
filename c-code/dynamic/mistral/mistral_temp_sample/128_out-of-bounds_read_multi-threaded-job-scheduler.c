#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define JOB_SIZE 256

typedef struct Job {
    char name[JOB_SIZE];
    void (*func)(void*);
    void* arg;
} Job;

Job jobs[MAX_JOBS];
pthread_t threads[MAX_JOBS];
pthread_mutex_t job_list_mutex;
int job_count = 0;

void unsafe_job(void* arg) {
    int i = *(int*)arg;
    printf("Running job: %s\n", jobs[i].name);
    char buffer[JOB_SIZE];
    strcpy(buffer, jobs[i].name);
    printf("Buffer size: %zu\n", strlen(buffer) + 1);
    printf("%c\n", buffer[strlen(buffer)]); // OOB read
}

void add_job(Job job) {
    pthread_mutex_lock(&job_list_mutex);
    jobs[job_count] = job;
    job_count++;
    pthread_mutex_unlock(&job_list_mutex);
}

void* scheduler(void* arg) {
    int i;
    for (i = 0; i < job_count; i++) {
        unsafe_job((void*)i);
    }
    return NULL;
}

int main() {
    pthread_mutex_init(&job_list_mutex, NULL);

    add_job((Job){.name = "Job 1", .func = unsafe_job, .arg = (void*)0});
    add_job((Job){.name = "Job 2", .func = unsafe_job, .arg = (void*)1});
    add_job((Job){.name = "Job 3", .func = unsafe_job, .arg = (void*)2});

    pthread_create(&threads[0], NULL, scheduler, NULL);

    return 0;
}
