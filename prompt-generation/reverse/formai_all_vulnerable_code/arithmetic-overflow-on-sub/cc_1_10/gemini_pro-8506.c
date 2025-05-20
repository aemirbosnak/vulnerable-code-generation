//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
    int start_time;
    int end_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n, i, j, quantum;
    struct process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Error: Maximum number of processes is %d\n", MAX_PROCESSES);
        return 1;
    }

    printf("Enter the arrival time, burst time, and priority of each process (in that order):\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    printf("Enter the quantum for round robin scheduling: ");
    scanf("%d", &quantum);

    // Sort processes by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate turnaround time and waiting time for each process
    int current_time = 0;
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    for (i = 0; i < n; i++) {
        // Start time of the process
        processes[i].start_time = current_time;

        // End time of the process
        processes[i].end_time = current_time + processes[i].burst_time;

        // Turnaround time of the process
        processes[i].turnaround_time = processes[i].end_time - processes[i].arrival_time;

        // Waiting time of the process
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        // Update current time
        current_time = processes[i].end_time;

        // Update total turnaround time and total waiting time
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
    }

    // Print the scheduling results
    printf("\nScheduling Results:\n");
    printf("%-5s %-10s %-10s %-10s %-10s %-10s %-10s\n", "PID", "Arrival Time", "Burst Time", "Priority", "Start Time", "End Time", "Turnaround Time");
    for (i = 0; i < n; i++) {
        printf("%-5d %-10d %-10d %-10d %-10d %-10d %-10d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].start_time, processes[i].end_time, processes[i].turnaround_time);
    }

    // Print the average turnaround time and average waiting time
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);

    return 0;
}