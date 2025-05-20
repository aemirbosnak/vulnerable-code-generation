#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 100
#define MAX_JOB_NAME_LENGTH 20

typedef struct Job {
    char name[MAX_JOB_NAME_LENGTH];
    void (*function)(void*);
    void* arg;
} Job;

Job jobs[MAX_JOBS];
pthread_t threads[MAX_JOBS];

void job_function(void* arg) {
    int count = *(int*)arg;
    int i;
    char job_name[MAX_JOB_NAME_LENGTH];

    // Integer overflow occurs here
    for (i = 0; i < count * 1000000; i++) {
        sprintf(job_name, "Job %d", i);
        printf("%s: Executing job %s\n", __func__, job_name);
    }
}

void schedule_job(const char* job_name, int count) {
    int i;
    for (i = 0; i < MAX_JOBS; i++) {
        if (!jobs[i].function) {
            strcpy(jobs[i].name, job_name);
            jobs[i].function = job_function;
            jobs[i].arg = (void*)&count;
            pthread_create(&threads[i], NULL, &jobs[i].function, &jobs[i].arg);
            break;
        }
    }
}

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        schedule_job("Job A", i * 100000);
    }

    for (i = 0; i < MAX_JOBS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
