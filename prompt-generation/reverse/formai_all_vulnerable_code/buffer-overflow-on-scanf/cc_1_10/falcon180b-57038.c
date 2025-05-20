//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct job {
    int id;
    int deadline;
    int profit;
};

void sort_jobs(struct job jobs[], int n) {
    int i, j;
    struct job temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(jobs[j].profit < jobs[j + 1].profit) {
                temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i, j, max_profit = 0;
    struct job jobs[MAX];

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    printf("Enter the details of %d jobs:\n", n);

    for(i = 0; i < n; i++) {
        printf("Enter job id, deadline and profit for job %d:\n", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    sort_jobs(jobs, n);

    for(i = 0, j = 0; i < n; i++) {
        if(j <= jobs[i].deadline) {
            j += jobs[i].profit;
        } else {
            j = jobs[i].deadline + 1;
        }
        max_profit = max_profit > j? max_profit : j;
    }

    printf("Maximum profit that can be obtained: %d\n", max_profit);

    return 0;
}