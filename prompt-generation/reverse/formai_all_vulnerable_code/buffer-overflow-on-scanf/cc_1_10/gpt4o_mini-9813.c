//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int processID;
    int burstTime;
    int arrivalTime;
} Process;

void findWaitingTimeFCFS(Process proc[], int n, int waitingTime[]) {
    waitingTime[0] = 0;
    for (int i = 1; i < n; i++) {
        waitingTime[i] = proc[i-1].burstTime + waitingTime[i-1];
    }
}

void findTurnAroundTimeFCFS(Process proc[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = proc[i].burstTime + waitingTime[i];
    }
}

void findWaitingTimeSJN(Process proc[], int n, int waitingTime[]) {
    int completed = 0, currentTime = 0, minBurstTimeIndex = 0;
    int isProcessDone[MAX] = {0};

    while (completed < n) {
        int minBurstTime = 999999;

        for (int j = 0; j < n; j++) {
            if (proc[j].arrivalTime <= currentTime && !isProcessDone[j] && proc[j].burstTime < minBurstTime) {
                minBurstTime = proc[j].burstTime;
                minBurstTimeIndex = j;
            }
        }

        if (minBurstTime != 999999) {
            waitingTime[minBurstTimeIndex] = currentTime - proc[minBurstTimeIndex].arrivalTime;
            currentTime += proc[minBurstTimeIndex].burstTime;
            isProcessDone[minBurstTimeIndex] = 1;
            completed++;
        } else {
            currentTime++;
        }
    }
}

void findTurnAroundTimeSJN(Process proc[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = proc[i].burstTime + waitingTime[i];
    }
}

void findWaitingTimeRR(Process proc[], int n, int quantum, int waitingTime[]) {
    int remBurstTime[MAX];
    for (int i = 0; i < n; i++) {
        remBurstTime[i] = proc[i].burstTime;
    }

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remBurstTime[i] > 0) {
                done = 0;
                if (remBurstTime[i] > quantum) {
                    t += quantum;
                    remBurstTime[i] -= quantum;
                } else {
                    t = t + remBurstTime[i];
                    waitingTime[i] = t - proc[i].burstTime;
                    remBurstTime[i] = 0;
                }
            }
        }
        if (done) break;
    }
}

void findTurnAroundTimeRR(Process proc[], int n, int waitingTime[], int turnaroundTime[]) {
    for (int i = 0; i < n; i++) {
        turnaroundTime[i] = proc[i].burstTime + waitingTime[i];
    }
}

void printSchedulingInfo(Process proc[], int n, int waitingTime[], int turnaroundTime[]) {
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].processID, proc[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }
}

int main() {
    Process proc[MAX];
    int n, choice, quantum;
    int waitingTime[MAX], turnaroundTime[MAX];

    printf("Enter the number of processes (max %d): ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time and arrival time for process %d: ", i + 1);
        proc[i].processID = i + 1;
        scanf("%d %d", &proc[i].burstTime, &proc[i].arrivalTime);
    }

    printf("\nChoose a Scheduling Algorithm:\n");
    printf("1. FCFS\n");
    printf("2. SJN (Shortest Job Next)\n");
    printf("3. RR (Round Robin)\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            findWaitingTimeFCFS(proc, n, waitingTime);
            findTurnAroundTimeFCFS(proc, n, waitingTime, turnaroundTime);
            break;
        case 2:
            findWaitingTimeSJN(proc, n, waitingTime);
            findTurnAroundTimeSJN(proc, n, waitingTime, turnaroundTime);
            break;
        case 3:
            printf("Enter time quantum for Round Robin: ");
            scanf("%d", &quantum);
            findWaitingTimeRR(proc, n, quantum, waitingTime);
            findTurnAroundTimeRR(proc, n, waitingTime, turnaroundTime);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    printSchedulingInfo(proc, n, waitingTime, turnaroundTime);

    return 0;
}