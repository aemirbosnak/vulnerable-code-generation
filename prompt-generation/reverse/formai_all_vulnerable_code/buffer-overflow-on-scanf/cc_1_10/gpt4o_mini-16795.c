//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    int t = 0; // Current time
    while (1) {
        int done = 1; // Flag to check if all processes are done
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There is at least one pending process
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t = t + remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time;
                    remaining_time[i] = 0; 
                }
            }
        }
        if (done == 1)
            break; // All processes are done
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void displayProcesses(Process processes[], int n) {
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].burst_time, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    int n; // Number of processes
    int quantum; // Quantum time for Round Robin Scheduling

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Please restart the program.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];

    printf("Enter burst times for %d processes:\n", n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("Enter time quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);

    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    displayProcesses(processes, n);

    return 0;
}