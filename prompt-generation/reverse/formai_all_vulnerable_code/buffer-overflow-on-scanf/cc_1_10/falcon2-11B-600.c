//Falcon2-11B DATASET v1.0 Category: Task Scheduler ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#define MAX_JOBS 10

typedef struct job {
    char *name;
    void (*func)(void*);
    void *arg;
    int priority;
} job_t;

void *job_func(void *arg) {
    job_t *job = (job_t *)arg;
    job->func(job->arg);
    free(job);
    return NULL;
}

int compare_priority(const void *a, const void *b) {
    job_t *ja = (job_t *)a;
    job_t *jb = (job_t *)b;
    return ja->priority - jb->priority;
}

int main() {
    srand(time(NULL));

    job_t jobs[MAX_JOBS];
    int job_count = 0;

    pthread_t threads[MAX_JOBS];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    while (1) {
        printf("Enter the name of the job: ");
        scanf("%s", jobs[job_count].name);

        printf("Enter the function and its argument: ");
        scanf("%s %s", jobs[job_count].func, jobs[job_count].arg);

        printf("Enter the priority of the job (1-10): ");
        scanf("%d", &jobs[job_count].priority);

        job_count++;
        if (job_count >= MAX_JOBS) {
            break;
        }
    }

    qsort(jobs, job_count, sizeof(job_t), compare_priority);

    for (int i = 0; i < job_count; i++) {
        job_t *job = &jobs[i];
        pthread_create(&threads[i], &attr, job_func, job);
    }

    for (int i = 0; i < job_count; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}