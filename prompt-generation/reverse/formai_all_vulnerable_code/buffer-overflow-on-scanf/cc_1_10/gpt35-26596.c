//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

// Process struct containing arrival time, burst time and remaining burst time
typedef struct Process {
    int arrivalTime;
    int burstTime;
    int remainingBurstTime;
} Process;

// Function to swap two processes
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the processes based on arrival time
void sort(Process *processes, int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(processes[j].arrivalTime > processes[j+1].arrivalTime) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

// Round Robin Scheduling Algorithm
void roundRobin(Process *processes, int n, int timeQuantum) {
    int time = 0;   // Current timestamp
    int completed = 0;  // Number of completed processes
    bool executed;   // Flag indicating whether the quantum was used or not

    printf("Round Robin CPU Scheduling Algorithm\n");
    printf("====================================\n");
    printf("Time  Process\n");

    while(completed < n) {
        executed = false;
        for(int i=0; i<n; i++) {
            if(processes[i].arrivalTime <= time && processes[i].remainingBurstTime > 0) {
                executed = true;
                if(processes[i].remainingBurstTime <= timeQuantum) {
                    // Process completed execution
                    time += processes[i].remainingBurstTime;
                    processes[i].remainingBurstTime = 0;
                    printf("%2d    P%d\n", time, i+1);
                    completed++;
                } else {
                    // Process executed for the given quantum
                    time += timeQuantum;
                    processes[i].remainingBurstTime -= timeQuantum;
                    printf("%2d    P%d\n", time, i+1);
                }
            }
        }

        if(!executed) {
            // If no process was executed in the current time slice, move to the next one
            time++;
            printf("%2d    Idle\n", time);
        }
    }

    printf("====================================\n");
}

// Function to calculate the average waiting time and average turnaround time
void calculateTime(Process *processes, int n) {
    int waitingTime[n];
    int turnaroundTime[n];
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for(int i=0; i<n; i++) {
        waitingTime[i] = processes[i].burstTime - processes[i].remainingBurstTime - processes[i].arrivalTime;
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, timeQuantum;

    printf("Enter the number of processes (maximum %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    for(int i=0; i<n; i++) {
        printf("Process %d Arrival Time: ", i+1);
        scanf("%d", &processes[i].arrivalTime);

        printf("Process %d Burst Time: ", i+1);
        scanf("%d", &processes[i].burstTime);

        processes[i].remainingBurstTime = processes[i].burstTime;
    }

    sort(processes, n);
    roundRobin(processes, n, timeQuantum);
    calculateTime(processes, n);

    return 0;
}