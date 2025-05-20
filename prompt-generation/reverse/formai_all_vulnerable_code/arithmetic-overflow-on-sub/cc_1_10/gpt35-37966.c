//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int burstTime;
    int arrivalTime;
    int priority;
    int waitingTime;
    int turnAroundTime;
} process;

void swap(process *p1, process *p2) {
    process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void bubbleSort(process *processes, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

void computeWaitingTime(process *processes, int n) {
    int i;
    processes[0].waitingTime = 0;
    for (i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

void computeTurnAroundTime(process *processes, int n) {
    int i;
    for (i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void computeAverageTime(process *processes, int n) {
    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;
    int i;

    computeWaitingTime(processes, n);
    computeTurnAroundTime(processes, n);

    for (i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += processes[i].turnAroundTime;
    }

    printf("Average Waiting Time: %f\n", (float) totalWaitingTime / (float) n);
    printf("Average Turnaround Time: %f\n", (float) totalTurnAroundTime / (float) n);
}

int main() {
    int n, i;
    process *processes;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    processes = (process *) malloc(n * sizeof(process));

    for (i = 0; i < n; i++) {
        printf("Enter the Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);

        printf("Enter the Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);

        printf("Enter the Priority for Process %d: ", i + 1);
        scanf("%d", &processes[i].priority);

        processes[i].processID = i + 1;
    }

    bubbleSort(processes, n);
    computeAverageTime(processes, n);

    return 0;
}