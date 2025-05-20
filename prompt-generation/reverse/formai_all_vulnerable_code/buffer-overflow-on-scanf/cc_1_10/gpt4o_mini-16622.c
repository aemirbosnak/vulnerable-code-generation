//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int burstTime;
} Process;

void findWaitingTime(Process proc[], int n, int waitTime[]) {
    waitTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitTime[i] = waitTime[i - 1] + proc[i - 1].burstTime;
    }
}

void findTurnAroundTime(Process proc[], int n, int waitTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = proc[i].burstTime + waitTime[i];
    }
}

void findAvgTime(Process proc[], int n) {
    int waitTime[n], turnAroundTime[n];
    
    findWaitingTime(proc, n, waitTime);
    findTurnAroundTime(proc, n, waitTime, turnAroundTime);

    float totalWaitTime = 0, totalTurnAroundTime = 0;

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        totalWaitTime += waitTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].processID, proc[i].burstTime, waitTime[i], turnAroundTime[i]);
    }

    printf("\nAverage Waiting Time: %.2f", totalWaitTime / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnAroundTime / n);
}

int compare(const void* a, const void* b) {
    return ((Process*)a)->burstTime - ((Process*)b)->burstTime;
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of processes must be positive.\n");
        return 1;
    }

    Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        proc[i].processID = i + 1;
        scanf("%d", &proc[i].burstTime);
    }

    // Sort processes by burst time
    qsort(proc, n, sizeof(Process), compare);

    findAvgTime(proc, n);

    return 0;
}