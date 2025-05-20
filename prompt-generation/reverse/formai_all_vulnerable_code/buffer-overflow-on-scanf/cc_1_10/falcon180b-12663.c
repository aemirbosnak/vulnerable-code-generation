//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Job {
    int id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    struct Job *job1 = (struct Job *)a;
    struct Job *job2 = (struct Job *)b;

    if (job1->deadline < job2->deadline)
        return -1;
    else if (job1->deadline == job2->deadline) {
        if (job1->profit > job2->profit)
            return -1;
        else
            return 1;
    } else
        return 1;
}

void activitySelection(struct Job jobs[], int n) {
    qsort(jobs, n, sizeof(struct Job), compare);

    int count = 1;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline <= count) {
            printf("Job %d selected at time %d\n", jobs[i].id, count);
            count += jobs[i].deadline;
        }
    }
}

int main() {
    struct Job jobs[MAX];
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the details of job %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &jobs[i].id);
        printf("Deadline: ");
        scanf("%d", &jobs[i].deadline);
        printf("Profit: ");
        scanf("%d", &jobs[i].profit);
    }

    activitySelection(jobs, n);

    return 0;
}