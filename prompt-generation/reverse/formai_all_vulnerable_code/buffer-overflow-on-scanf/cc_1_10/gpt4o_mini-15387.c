//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_PROCESSES 10
#define MAX_BURST_TIME 10

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_burst_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
        processes[i].waiting_time = 0; // Initialize waiting time
    }

    int complete = 0, time = 0;
    
    while (complete < n) {
        // A paranoid check on time!
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                // Time to plot the process!
                if (remaining_burst_time[i] > quantum) {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    time += remaining_burst_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_burst_time[i] = 0;
                    complete++;
                }
            }
        }
        // A paranoid verification of process states!
        for (int j = 0; j < n; j++) {
            if (remaining_burst_time[j] < 0) {
                printf("Error: Remaining burst time cannot be negative!\n");
                exit(1);
            }
        }
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void printProcessDetails(Process processes[], int n) {
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].id, 
                processes[i].burst_time, 
                processes[i].arrival_time, 
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }
}

void generateProcesses(Process processes[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].burst_time = rand() % MAX_BURST_TIME + 1; // Random burst time between 1 and MAX_BURST_TIME
        processes[i].arrival_time = rand() % 5; // Random arrival time between 0 and 4
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Danger! Invalid number of processes!\n");
        return 1;
    }
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    if (quantum <= 0) {
        printf("Danger! Quantum must be positive!\n");
        return 1;
    }

    generateProcesses(processes, n);

    // A paranoid view of the generated processes
    printf("Generated Processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process ID: %d, Burst Time: %d, Arrival Time: %d\n", 
                processes[i].id, 
                processes[i].burst_time, 
                processes[i].arrival_time);
    }

    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printProcessDetails(processes, n);

    return 0;
}