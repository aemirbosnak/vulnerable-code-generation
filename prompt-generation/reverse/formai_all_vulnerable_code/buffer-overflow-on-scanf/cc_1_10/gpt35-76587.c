//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
/*
Title: Unique CPU Scheduling Algorithm Example Program
Author: [Insert Name Here]

Description: This program simulates a unique CPU scheduling algorithm,
             which prioritizes processes with shorter burst times to 
             ensure faster completion times and improved efficiency.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10 // Maximum number of processes
#define TIME_QUANTUM 2 // Time quantum for each process in milliseconds

// Structure representing a single process
typedef struct process {
    int pid; // Process ID
    int burst_time; // Burst time of process
    int remaining_time; // Remaining time of process
    int priority; // Priority value of process
} Process;

// Function to initialize a process
Process initProcess(int pid, int burst_time, int priority) {
    Process p;
    p.pid = pid;
    p.burst_time = burst_time;
    p.remaining_time = burst_time;
    p.priority = priority;
    return p;
}

// Function to get the index of the process with the shortest remaining time
int getShortestTimeProcess(Process* processes, int n) {
    int shortest_time = processes[0].remaining_time;
    int shortest_time_index = 0;
    for (int i = 1; i < n; i++) {
        if (processes[i].remaining_time < shortest_time) {
            shortest_time = processes[i].remaining_time;
            shortest_time_index = i;
        }
    }
    return shortest_time_index;
}

// Function to simulate the unique CPU scheduling algorithm
void scheduleProcesses(Process* processes, int n) {
    int current_time = 0;
    int num_completed_processes = 0;
    printf("Time\tProcess\n");
    while (num_completed_processes < n) {
        int shortest_time_index = getShortestTimeProcess(processes, n);
        if (processes[shortest_time_index].remaining_time <= TIME_QUANTUM) {
            current_time += processes[shortest_time_index].remaining_time;
            processes[shortest_time_index].remaining_time = 0;
            printf("%dms\t%d\n", current_time, processes[shortest_time_index].pid);
            num_completed_processes++;
        } else {
            current_time += TIME_QUANTUM;
            processes[shortest_time_index].remaining_time -= TIME_QUANTUM;
            printf("%dms\t%d*\n", current_time, processes[shortest_time_index].pid);
        }
    }
}

// Function to print details of all the processes
void printProcesses(Process* processes, int n) {
     printf("PID\tBurst Time\tPriority\n");
     for (int i = 0; i < n; i++) {
         printf("%d\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].priority);
     }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Maximum number of processes reached. Exiting program...\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        int pid, burst_time, priority;
        printf("Enter details of process #%d:\n", i+1);
        printf("PID: ");
        scanf("%d", &pid);
        printf("Burst Time: ");
        scanf("%d", &burst_time);
        printf("Priority: ");
        scanf("%d", &priority);
        processes[i] = initProcess(pid, burst_time, priority);
    }
    printf("Input Details:\n");
    printProcesses(processes, n);
    printf("\n");
    scheduleProcesses(processes, n);
    return 0;
}