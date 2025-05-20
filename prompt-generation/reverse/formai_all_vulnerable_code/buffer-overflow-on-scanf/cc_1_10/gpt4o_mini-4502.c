//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;         // Process ID
    int burstTime;   // Burst Time
    int arrivalTime; // Arrival Time
    int waitingTime; // Waiting Time
    int turnaroundTime; // Turnaround Time
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remainingBurst[MAX_PROCESSES];
    
    for (int i = 0; i < n; i++)
        remainingBurst[i] = processes[i].burstTime;

    int t = 0; 
    bool done;

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remainingBurst[i] > 0) {
                done = false; // There is a pending process
                if (remainingBurst[i] > quantum) {
                    t += quantum;
                    remainingBurst[i] -= quantum;
                } else {
                    t = t + remainingBurst[i];
                    processes[i].waitingTime = t - processes[i].burstTime - processes[i].arrivalTime;
                    remainingBurst[i] = 0;
                }
            }
        }
    } while (!done);
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
}

void printProcessDetails(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].pid, 
            processes[i].burstTime, 
            processes[i].arrivalTime, 
            processes[i].waitingTime, 
            processes[i].turnaroundTime);
    }
}

void roundRobinScheduling(Process processes[], int n, int quantum) {
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printProcessDetails(processes, n);
}

int main() {
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    if(n > MAX_PROCESSES) {
        printf("Max processes allowed: %d\n", MAX_PROCESSES);
        return 1;
    }

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Assigning Process ID
        printf("Enter Burst Time for Process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burstTime);
        printf("Enter Arrival Time for Process %d: ", processes[i].pid);
        scanf("%d", &processes[i].arrivalTime);
        processes[i].waitingTime = 0; // Initialize waiting time
        processes[i].turnaroundTime = 0; // Initialize turnaround time
    }

    printf("Enter Time Quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);

    roundRobinScheduling(processes, n, quantum);

    return 0;
}