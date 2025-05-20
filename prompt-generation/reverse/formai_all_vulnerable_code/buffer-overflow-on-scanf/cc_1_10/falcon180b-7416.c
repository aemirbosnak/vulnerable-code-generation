//Falcon-180B DATASET v1.0 Category: Task Scheduler ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_JOBS 100

struct job {
    int id;
    int priority;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int start_time;
    int end_time;
    int cpu_bursts;
};

void *execute_job(void *param) {
    struct job *job = (struct job *) param;
    int i;

    for (i = 0; i < job->burst_time; i++) {
        printf("Job %d is executing on CPU\n", job->id);
        sleep(1);
    }

    return NULL;
}

int main() {
    int i, j, max_jobs, cpu_bursts, quantum;
    struct job jobs[MAX_JOBS];
    pthread_t threads[MAX_JOBS];

    printf("Enter the number of jobs: ");
    scanf("%d", &max_jobs);

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    for (i = 0; i < max_jobs; i++) {
        printf("Enter job details for job %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &jobs[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &jobs[i].burst_time);
        jobs[i].id = i + 1;
        jobs[i].priority = i + 1;
        jobs[i].cpu_bursts = 0;
    }

    for (i = 0; i < max_jobs; i++) {
        for (j = 0; j < jobs[i].burst_time; j++) {
            pthread_create(&threads[i], NULL, execute_job, &jobs[i]);
            printf("Job %d is waiting to execute on CPU\n", jobs[i].id);
            sleep(1);
        }
    }

    for (i = 0; i < max_jobs; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}