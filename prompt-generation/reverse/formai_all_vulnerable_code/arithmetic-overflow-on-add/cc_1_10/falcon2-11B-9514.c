//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIORITY 5
#define MAX_JOB 10

struct job {
    int priority;
    int arrivalTime;
    int burstTime;
    int currentTime;
    int finishTime;
};

void printJob(struct job job) {
    printf("Priority: %d\n", job.priority);
    printf("Arrival Time: %d\n", job.arrivalTime);
    printf("Burst Time: %d\n", job.burstTime);
    printf("Current Time: %d\n", job.currentTime);
    printf("Finish Time: %d\n\n", job.finishTime);
}

void sortJobs(struct job jobs[MAX_JOB], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (jobs[j].priority > jobs[j + 1].priority) {
                struct job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int findLongestJob(struct job jobs[MAX_JOB], int n) {
    int maxBurst = 0;
    int maxJob = 0;
    int maxIndex = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i].burstTime > maxBurst) {
            maxBurst = jobs[i].burstTime;
            maxJob = i;
            maxIndex = i;
        }
    }

    return maxIndex;
}

void scheduleJobs(struct job jobs[MAX_JOB], int n) {
    int i = 0;
    int longestJob = findLongestJob(jobs, n);

    while (i < n) {
        if (jobs[i].burstTime == jobs[longestJob].burstTime) {
            jobs[i].currentTime = jobs[i].arrivalTime;
        } else {
            jobs[i].currentTime = 0;
        }

        if (jobs[i].arrivalTime <= jobs[longestJob].arrivalTime) {
            jobs[longestJob].finishTime = jobs[i].currentTime + jobs[i].burstTime;
            i++;
        } else {
            jobs[longestJob].finishTime = jobs[i].currentTime + jobs[i].burstTime;
            i++;
        }
    }

    for (int j = 0; j < n; j++) {
        printf("Job %d:\n", j + 1);
        printJob(jobs[j]);
        printf("\n");
    }
}

int main() {
    struct job jobs[MAX_JOB];
    int n = 0;
    int i = 0;

    while (scanf("%d", &jobs[n].priority)!= EOF) {
        if (i >= MAX_JOB) {
            printf("Error: Too many jobs!\n");
            return 1;
        }

        scanf("%d %d %d", &jobs[n].arrivalTime, &jobs[n].burstTime, &jobs[n].currentTime);
        jobs[n].finishTime = jobs[n].arrivalTime + jobs[n].burstTime;

        n++;
        i++;
    }

    sortJobs(jobs, n);
    scheduleJobs(jobs, n);

    return 0;
}