//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int processID;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateTimes(Process processes[], int n, int timeQuantum) {
    int time = 0;
    int remainingProcesses = n;

    while (remainingProcesses > 0) {
        int allComplete = 1; // Flag to check if all processes are completed

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                allComplete = 0; // At least one process is not complete

                if (processes[i].remainingTime > timeQuantum) {
                    time += timeQuantum;
                    processes[i].remainingTime -= timeQuantum;
                } else {
                    time += processes[i].remainingTime;
                    processes[i].waitingTime = time - processes[i].burstTime;
                    processes[i].turnaroundTime = time;
                    processes[i].remainingTime = 0;
                    remainingProcesses--;
                }
            }
        }

        if (allComplete) {
            break; // Break if all processes are completed
        }
    }
}

void displayProcesses(Process processes[], int n) {
    printf("\nProcessID  BurstTime  WaitingTime  TurnaroundTime\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%9d  %9d  %11d  %14d\n", processes[i].processID,
                                                processes[i].burstTime,
                                                processes[i].waitingTime,
                                                processes[i].turnaroundTime);
    }
    printf("-------------------------------------------------\n");
}

int main() {
    int n, timeQuantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process *processes = (Process *)malloc(n * sizeof(Process));
    
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        processes[i].processID = i + 1;
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; // Initialize remaining time
        processes[i].waitingTime = 0; // Initialize waiting time
        processes[i].turnaroundTime = 0; // Initialize turnaround time
    }

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    calculateTimes(processes, n, timeQuantum);
    displayProcesses(processes, n);

    free(processes); // Free allocated memory
    return 0;
}