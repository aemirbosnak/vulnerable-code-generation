//MISTRAL-7B DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORKERS 10
#define MAX_JOBS 20
#define INF 10000

typedef struct Job {
    int id;
    int work;
} Job;

void swap(Job* a, Job* b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(Job jobs[], int n) {
    int i, j, minIndex;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (jobs[j].work < jobs[minIndex].work) {
                minIndex = j;
            }
        }
        swap(&jobs[i], &jobs[minIndex]);
    }
}

int maximumJobs(Job jobs[], int n, int workers) {
    int slot = 0, i;

    selectionSort(jobs, n);

    for (i = 0; i < n && slot < workers; i++) {
        if (workers >= jobs[i].work) {
            workers -= jobs[i].work;
            slot++;
        } else {
            int j = i + 1;
            while (j < n && jobs[j].work <= workers) {
                workers -= jobs[j].work;
                slot++;
                j++;
            }
            i--;
        }
    }

    return slot;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Job jobs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &jobs[i].work);
        jobs[i].id = i + 1;
    }

    printf("Maximum number of jobs that can be completed by %d workers: %d\n", m, maximumJobs(jobs, n, m));

    return 0;
}