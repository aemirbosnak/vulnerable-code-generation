//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnAroundTime;
} Process;

void calculateTimes(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].burstTime + processes[i].waitingTime;
    }
}

void printGanttChart(Process processes[], int n, int timeQuantum) {
    int totalTime = 0;
    printf("\nGantt Chart:\n");
    while (1) {
        int done = 1; // Flag to check if all processes are done
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                done = 0; // At least one process is still remaining
                if (processes[i].remainingTime > timeQuantum) {
                    totalTime += timeQuantum;
                    processes[i].remainingTime -= timeQuantum;
                    printf("| P%d ", processes[i].id);
                } else {
                    totalTime += processes[i].remainingTime;
                    processes[i].waitingTime += totalTime - processes[i].burstTime;
                    processes[i].remainingTime = 0;
                    printf("| P%d ", processes[i].id);
                }
            }
        }
        if (done) {
            break; // All processes are done
        }
    }
    printf("|\nTotal time taken: %d\n", totalTime);
}

void calculateAverageTime(Process processes[], int n) {
    float averageWaitingTime = 0;
    float averageTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        averageWaitingTime += processes[i].waitingTime;
        averageTurnAroundTime += processes[i].turnAroundTime;
    }

    printf("Average Waiting Time: %.2f\n", averageWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", averageTurnAroundTime / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, timeQuantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process P%d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; 
        processes[i].waitingTime = 0; // Initial waiting time
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    printGanttChart(processes, n, timeQuantum);
    
    calculateTimes(processes, n);
    calculateAverageTime(processes, n);
    
    printf("\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("      %d     |     %d     |      %d      |     %d\n", 
                processes[i].id, processes[i].burstTime, processes[i].waitingTime, processes[i].turnAroundTime);
    }

    return 0;
}