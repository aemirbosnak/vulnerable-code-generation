//GPT-4o-mini DATASET v1.0 Category: Greedy Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 100

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

Job jobs[MAX];
int n;

typedef struct {
    int index;
    int slot;
} ThreadData;

void *schedule_job(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    int index = data->index;
    int slot = data->slot;

    if (slot >= 0 && jobs[index].deadline > slot) {
        printf("Job %d with profit %d scheduled in slot %d\n", jobs[index].id, jobs[index].profit, slot + 1);
    }
    pthread_exit(NULL);
}

int compare_jobs(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

void job_sequencing() {
    pthread_t threads[MAX];
    ThreadData threadData[MAX];
    int slots[MAX] = { -1 };
    int max_deadline = 0;

    // Finding maximum deadline
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }

    // Scheduling jobs
    for (int i = 0; i < n; i++) {
        // Check from the latest slot to the first one
        for (int j = (jobs[i].deadline - 1 < max_deadline ? jobs[i].deadline - 1 : max_deadline - 1); j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                threadData[i].index = i;
                threadData[i].slot = j;
                pthread_create(&threads[i], NULL, schedule_job, (void *)&threadData[i]);
                break;
            }
        }
    }

    // Join threads
    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    // Input number of jobs
    printf("Enter number of jobs: ");
    scanf("%d", &n);

    // Input jobs data
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1; // Job ID
        printf("Enter deadline and profit for job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
    }

    // Sorting jobs based on profit
    qsort(jobs, n, sizeof(Job), compare_jobs);

    // Start job scheduling
    job_sequencing();

    return 0;
}