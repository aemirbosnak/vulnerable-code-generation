//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;             // Process ID
    int burstTime;     // Burst Time
    int remainingTime; // Remaining Time
} Process;

void calculateWaitTime(Process processes[], int n, int quantum, int waitTime[]) {
    int remainingProcesses = n;

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > quantum) {
                    waitTime[i] += (quantum - (processes[i].burstTime - processes[i].remainingTime));
                    processes[i].remainingTime -= quantum;
                } else {
                    waitTime[i] += (processes[i].remainingTime - (processes[i].burstTime - processes[i].remainingTime));
                    processes[i].remainingTime = 0;
                    remainingProcesses--;
                }
            }
        }
    }
}

void findAverageTime(Process processes[], int n, int quantum) {
    int waitTime[MAX_PROCESSES] = {0};
    for (int i = 0; i < n; i++) {
        processes[i].remainingTime = processes[i].burstTime;
    }

    calculateWaitTime(processes, n, quantum, waitTime);

    printf("\nProcess ID | Burst Time | Wait Time\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("    %3d    |    %7d |   %7d\n", processes[i].id, processes[i].burstTime, waitTime[i]);
    }
}

int main() {
    int n, quantum;
    
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum allowed processes.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter the burst time for process %d: ", processes[i].id);
        scanf("%d", &(processes[i].burstTime));
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    findAverageTime(processes, n, quantum);

    return 0;
}