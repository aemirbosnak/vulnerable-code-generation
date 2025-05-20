//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;         // Process ID
    int burstTime;  // Burst time
    int remainingTime; // Remaining time
    int completionTime; // Completion time
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum, int waitingTime[]) {
    int remainingProcesses = n, time = 0;

    while (remainingProcesses > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    time += processes[i].remainingTime;
                    waitingTime[i] = time - processes[i].burstTime; // Calculate waiting time
                    processes[i].remainingTime = 0;
                    processes[i].completionTime = time;
                    remainingProcesses--;
                }
            }
        }
    }
}

void displayResults(Process processes[], int n, int waitingTime[]) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tCompletion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-12d\t%-10d\t%-13d\t%d\n", 
               processes[i].id, 
               processes[i].burstTime, 
               waitingTime[i], 
               processes[i].completionTime);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;
    int waitingTime[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign process ID
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; // Initialize remaining time
        processes[i].completionTime = 0; // Initialize completion time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    calculateWaitingTime(processes, n, quantum, waitingTime);
    displayResults(processes, n, waitingTime);

    return 0;
}