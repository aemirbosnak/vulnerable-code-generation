//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;          // Process ID
    int burst_time;   // Burst time of the process
    int arrival_time; // Arrival time of the process
    int waiting_time; // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
} Process;

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int rem_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        rem_burst[i] = processes[i].burst_time;

    int t = 0; // Current time
    bool done = false;

    while (!done) {
        done = true;
        for (int i = 0; i < n; i++) {
            if (rem_burst[i] > 0) {
                done = false;
                if (rem_burst[i] > quantum) {
                    t += quantum;
                    rem_burst[i] -= quantum;
                } else {
                    t = t + rem_burst[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    rem_burst[i] = 0;
                }
            }
        }
    }
}

void roundRobinScheduling(Process processes[], int n, int quantum) {
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printf("\nPID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].pid, 
            processes[i].burst_time, 
            processes[i].arrival_time, 
            processes[i].waiting_time, 
            processes[i].turnaround_time);
    }
}

void sortByArrivalTime(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n > MAX_PROCESSES) {
        printf("Number of processes should not exceed %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter Burst Time and Arrival Time for Process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].waiting_time = 0; // Initial waiting time
    }

    printf("Enter time quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);

    // Sort processes by arrival time
    sortByArrivalTime(processes, n);
    
    printf("\nExecuting Round Robin Scheduling...\n");
    roundRobinScheduling(processes, n, quantum);

    return 0;
}