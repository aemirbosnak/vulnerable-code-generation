//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int deadline;
    int profit;
} Job;

int cmpfunc(const void *a, const void *b) {
    Job *jobA = (Job *) a;
    Job *jobB = (Job *) b;
    double ratioA = (double) jobA->profit / (double) jobA->deadline;
    double ratioB = (double) jobB->profit / (double) jobB->deadline;
    if (ratioA > ratioB)
        return -1;
    else if (ratioA < ratioB)
        return 1;
    else {
        if (jobA->deadline < jobB->deadline)
            return -1;
        else
            return 1;
    }
}

int main() {
    int numJobs;
    printf("Enter the number of jobs: ");
    scanf("%d", &numJobs);
    Job *jobs = (Job *) calloc(numJobs, sizeof(Job));
    for (int i = 0; i < numJobs; i++) {
        printf("Enter the deadline and profit for Job%d: ", i + 1);
        scanf("%d%d", &jobs[i].deadline, &jobs[i].profit);
    }
    qsort(jobs, numJobs, sizeof(Job), cmpfunc);
    printf("\nProcessing the jobs in order of their deadline/profit ratio:\n");
    for (int i = 0; i < numJobs; i++) {
        printf("Job%d (%d, %d)\n", i + 1, jobs[i].deadline, jobs[i].profit);
        for (int j = i + 1; j < numJobs; j++) {
            if (jobs[i].deadline <= jobs[j].deadline) {
                int tempDeadline = jobs[i].deadline;
                int tempProfit = jobs[i].profit;
                jobs[i].deadline = jobs[j].deadline;
                jobs[i].profit = jobs[j].profit;
                jobs[j].deadline = tempDeadline;
                jobs[j].profit = tempProfit;
            }
        }
    }
    free(jobs);
    return 0;
}