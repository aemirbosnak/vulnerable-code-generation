//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;         // Process ID
    int burstTime;   // Time required to complete the process
    int remainingTime; // Remaining time to complete process
    int waitingTime; // Waiting time for the process
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int time = 0;
    bool done;

    while (true) {
        done = true;

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                done = false; // There is a pending process
                if (processes[i].remainingTime > quantum) {
                    time += quantum; // Increment time by quantum
                    processes[i].remainingTime -= quantum; // Decrease remaining time
                } else {
                    time += processes[i].remainingTime; // Increase time by remaining time
                    processes[i].waitingTime = time - processes[i].burstTime; 
                    processes[i].remainingTime = 0; // Process completed
                }
            }
        }

        if (done) break; // All processes finished
    }
}

void calculateTurnAroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].waitingTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

void printAverageTimes(Process processes[], int n) {
    float totalWaitingTime = 0;
    float totalTurnAroundTime = 0;

    printf("\nProcess ID | Burst Time | Waiting Time | Turnaround Time\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        totalWaitingTime += processes[i].waitingTime;
        totalTurnAroundTime += (processes[i].waitingTime + processes[i].burstTime);
        printf("     %d     |     %d     |      %d      |       %d\n", 
               processes[i].pid, processes[i].burstTime, 
               processes[i].waitingTime, 
               processes[i].waitingTime + processes[i].burstTime);
    }

    printf("-------------------------------------------------------\n");
    printf("Average Waiting Time = %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time = %.2f\n", totalTurnAroundTime / n);
}

int main() {
    int n, quantum;

    printf("Welcome to the Energetic Round Robin CPU Scheduler!\n");
    printf("---------------------------------------------------\n");
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if(n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Please try again.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Assigning process IDs
        printf("Enter burst time for process %d: ", processes[i].pid);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].waitingTime = 0; // Initialize waiting time
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    
    printf("Calculating waiting times...\n");
    calculateWaitingTime(processes, n, quantum);
    printf("Calculating turnaround times...\n");
    calculateTurnAroundTime(processes, n);
    
    printAverageTimes(processes, n);
    
    printf("---------------------------------------------------\n");
    printf("All processes executed! Thank you for using the scheduler!\n");

    return 0;
}