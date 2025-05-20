#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define BUFFER_SIZE 100

typedef struct Job {
    char name[BUFFER_SIZE];
    void (*func)(void*);
    void* arg;
} Job;

Job jobs[MAX_JOBS];
pthread_t workers[MAX_JOBS];

void job_func(void* arg) {
    char* name = ((Job*)arg)->name;
    printf("%s: Running job\n", name);
    char *out_of_bounds = (char*)calloc(1, 100);
    strcpy(out_of_bounds, name);
    out_of_bounds[strlen(name) + 1] = 'X'; // Out of bounds write
    free(out_of_bounds);
}

void schedule_job(Job job) {
    pthread_create(&workers[job.name[0] % MAX_JOBS], NULL, job_func, &job);
}

int main() {
    jobs[0] = (Job){.name = "Job1", .func = job_func, .arg = (void*)&jobs[0]};
    jobs[1] = (Job){.name = "Job2", .func = job_func, .arg = (void*)&jobs[1]};

    for (int i = 0; i < 2; i++) {
        schedule_job(jobs[i]);
    }

    for (int i = 0; i < MAX_JOBS; i++) {
        pthread_join(workers[i], NULL);
    }

    return 0;
}
