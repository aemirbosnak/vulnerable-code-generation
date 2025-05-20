//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct job {
    int id;
    int profit;
    int deadline;
} Job;

int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    return jobB->profit - jobA->profit;
}

void printSchedule(Job arr[], int n) {
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].deadline > maxDeadline) {
            maxDeadline = arr[i].deadline;
        }
    }
    int schedule[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        schedule[i] = -1;
    }
    int totalProfit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (schedule[j] == -1) {
                schedule[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }
    printf("Job Schedule: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (schedule[i] != -1) {
            printf("%d ", schedule[i]);
        }
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job arr[n];
    printf("Enter the profit and deadline of each job:\n");
    for (int i = 0; i < n; i++) {
        arr[i].id = i + 1;
        scanf("%d %d", &arr[i].profit, &arr[i].deadline);
    }
    qsort(arr, n, sizeof(Job), compare);
    printSchedule(arr, n);
    return 0;
}