//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;         // Process ID
    int burstTime;  // Total Burst Time
    int remainingTime; // Remaining Time
} Process;

// Function to calculate waiting time and turn around time
void calculateTimes(Process processes[], int n, int quantum, int *waitingTime, int *turnAroundTime) {
    int time = 0;
    int done = 0;

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0) {
                if (processes[i].remainingTime > quantum) {
                    time += quantum;
                    processes[i].remainingTime -= quantum;
                } else {
                    time += processes[i].remainingTime;
                    waitingTime[i] = time - processes[i].burstTime;
                    turnAroundTime[i] = time;
                    processes[i].remainingTime = 0;
                    done++;
                }
            }
        }
    }
}

// Function to print process details
void printProcessDetails(Process processes[], int n, int waitingTime[], int turnAroundTime[]) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].burstTime, 
               waitingTime[i], 
               turnAroundTime[i]);
    }
}

int main() {
    int n, quantum;

    // Prompt user for number of processes and time quantum
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n < 1 || n > MAX_PROCESSES) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    Process processes[n];
    int waitingTime[n], turnAroundTime[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for Process %d: ", i + 1);
        processes[i].id = i + 1; // Assign process ID
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; // Initialize remaining time
    }

    // Input time quantum
    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    // Calculate waiting time and turn around time
    calculateTimes(processes, n, quantum, waitingTime, turnAroundTime);

    // Print process details
    printProcessDetails(processes, n, waitingTime, turnAroundTime);

    return 0;
}