//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int wait_time;
    int turnaround_time;
} Process;

void calculateWaitTime(Process processes[], int n, int quantum) {
    int remaining_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_burst[i] = processes[i].burst_time;

    int time = 0;
    while (1) {
        int done = 1;
        
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = 0; 
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    processes[i].wait_time = time - processes[i].burst_time;
                    remaining_burst[i] = 0;
                }
            }
        }
        if (done == 1) break; 
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].wait_time + processes[i].burst_time;
}

void printProcessInfo(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("  %d\t\t  %d\t\t  %d\t\t     %d\n", processes[i].id, processes[i].burst_time, processes[i].wait_time, processes[i].turnaround_time);
    }
}

void roundRobinScheduling(Process processes[], int n, int quantum) {
    printf("=== Round Robin CPU Scheduling ===\n");
    calculateWaitTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printProcessInfo(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Welcome to the Round Robin CPU Scheduling Simulation! 🎉\n");
    printf("How many processes do you want to simulate? ");
    scanf("%d", &n);

    // Dynamic Input of processes and their burst times
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Setting Process ID as 1, 2, ...
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter the time quantum for the Round Robin scheduling: ");
    scanf("%d", &quantum);

    printf("\nInitiating Round Robin Scheduling with quantum %d...\n", quantum);
    roundRobinScheduling(processes, n, quantum);
    
    printf("\nThanks for using the CPU Scheduling Simulation! 😄\n");
    return 0;
}