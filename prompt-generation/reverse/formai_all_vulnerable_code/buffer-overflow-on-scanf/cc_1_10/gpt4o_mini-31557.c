//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct Process {
    int id;         // Process ID
    int burstTime;  // Burst time
    int waitTime;   // Waiting time
    int turnAroundTime; // Turnaround time
} Process;

void calculateFCFS(Process proc[], int n) {
    int totalWaitTime = 0, totalTurnAroundTime = 0;
    proc[0].waitTime = 0; // First process has no wait time

    // Calculate waiting time and turnaround time for FCFS
    for (int i = 1; i < n; i++) {
        proc[i].waitTime = proc[i - 1].waitTime + proc[i - 1].burstTime;
        totalWaitTime += proc[i].waitTime;
    }
    
    for (int i = 0; i < n; i++) {
        proc[i].turnAroundTime = proc[i].waitTime + proc[i].burstTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
    }

    printf("FCFS Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burstTime, proc[i].waitTime, proc[i].turnAroundTime);
    }
    printf("Average Waiting Time: %.2f\n", (float)totalWaitTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);
}

void calculateSJN(Process proc[], int n) {
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].burstTime > proc[j + 1].burstTime) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }

    calculateFCFS(proc, n); // Use FCFS calculation on sorted processes
}

void calculateRR(Process proc[], int n, int quantum) {
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++) {
        remainingBurstTime[i] = proc[i].burstTime;
    }

    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remainingBurstTime[i] > 0) {
                done = 0;
                if (remainingBurstTime[i] > quantum) {
                    time += quantum;
                    remainingBurstTime[i] -= quantum;
                } else {
                    time += remainingBurstTime[i];
                    proc[i].turnAroundTime = time;
                    proc[i].waitTime = proc[i].turnAroundTime - proc[i].burstTime;
                    remainingBurstTime[i] = 0;
                }
            }
        }
        if (done == 1) break; // All processes are done
    }

    printf("Round Robin Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    int totalWaitTime = 0, totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitTime += proc[i].waitTime;
        totalTurnAroundTime += proc[i].turnAroundTime;
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burstTime, proc[i].waitTime, proc[i].turnAroundTime);
    }
    printf("Average Waiting Time: %.2f\n", (float)totalWaitTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnAroundTime / n);
}

int main() {
    int n, choice, quantum;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    Process *proc = (Process *)malloc(n * sizeof(Process));
    
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Process IDs starting from 1
        printf("Enter Burst Time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].burstTime);
    }
    
    printf("Choose Scheduling Algorithm:\n1. FCFS\n2. SJN\n3. Round Robin\nChoice: ");
    scanf("%d", &choice);
    
    if (choice == 3) {
        printf("Enter time quantum for Round Robin: ");
        scanf("%d", &quantum);
    }
    
    switch (choice) {
        case 1:
            calculateFCFS(proc, n);
            break;
        case 2:
            calculateSJN(proc, n);
            break;
        case 3:
            calculateRR(proc, n, quantum);
            break;
        default:
            printf("Invalid choice!\n");
    }
    
    free(proc); // Free allocated memory
    return 0;
}