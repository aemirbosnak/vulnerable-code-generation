//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnAroundTime;
} Process;

void calculateWaitingTime(Process processes[], int n, int waitingTime[]) {
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = processes[i - 1].burstTime + waitingTime[i - 1];
    }
}

void calculateTurnAroundTime(Process processes[], int n, int waitingTime[], int turnAroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void fcfs(Process processes[], int n) {
    int waitingTime[MAX_PROCESSES], turnAroundTime[MAX_PROCESSES];
    calculateWaitingTime(processes, n, waitingTime);
    calculateTurnAroundTime(processes, n, waitingTime, turnAroundTime);

    printf("\nFCFS Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, waitingTime[i], turnAroundTime[i]);
    }
}

void sjf(Process processes[], int n) {
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burstTime > processes[j].burstTime) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    fcfs(processes, n);
}

void roundRobin(Process processes[], int n, int quantum) {
    int waitingTime[MAX_PROCESSES] = {0};
    int remainingTime[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].burstTime;
    }

    int time = 0;
    bool done;
    while (true) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                done = false;
                if (remainingTime[i] > quantum) {
                    time += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    time += remainingTime[i];
                    waitingTime[i] = time - processes[i].burstTime;
                    remainingTime[i] = 0;
                }
            }
        }
        if (done) break;
    }

    int turnAroundTime[MAX_PROCESSES];
    calculateTurnAroundTime(processes, n, waitingTime, turnAroundTime);
    
    printf("\nRound Robin Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, waitingTime[i], turnAroundTime[i]);
    }
}

int main() {
    int n, choice, quantum;
    Process processes[MAX_PROCESSES];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
        processes[i].arrivalTime = 0; // For simplicity assume all arrive at 0
    }

    printf("Choose Scheduling Algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SJF\n");
    printf("3. Round Robin\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(processes, n);
            break;
        case 2:
            sjf(processes, n);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            roundRobin(processes, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}