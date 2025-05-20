//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>

struct Job {
    char name;
    int deadline;
    int profit;
};

int findMaxDeadline(struct Job jobs[], int n) {
    int max = 0;
    for(int i = 0; i < n; i++) {
        if(jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

void sortJobs(struct Job jobs[], int n) {
    struct Job temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(jobs[j].profit < jobs[j+1].profit) {
                temp = jobs[j];
                jobs[j] = jobs[j+1];
                jobs[j+1] = temp;
            }
        }
    }
}

void scheduleJobs(struct Job jobs[], int n) {
    int maxDeadline = findMaxDeadline(jobs, n);

    char schedule[maxDeadline];
    for(int i = 0; i < maxDeadline; i++) {
        schedule[i] = '-';
    }

    for(int i = 0; i < n; i++) {
        for(int j = jobs[i].deadline - 1; j >= 0; j--) {
            if(schedule[j] == '-') {
                schedule[j] = jobs[i].name;
                break;
            }
        }
    }

    printf("Scheduled Jobs:\n");
    for(int i = 0; i < maxDeadline; i++) {
        printf("%c ", schedule[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job jobs[n];
    for(int i = 0; i < n; i++) {
        printf("Enter job name: ");
        scanf(" %c", &jobs[i].name);

        printf("Enter job deadline: ");
        scanf("%d", &jobs[i].deadline);

        printf("Enter job profit: ");
        scanf("%d", &jobs[i].profit);
    }

    sortJobs(jobs, n);
    scheduleJobs(jobs, n);

    return 0;
}