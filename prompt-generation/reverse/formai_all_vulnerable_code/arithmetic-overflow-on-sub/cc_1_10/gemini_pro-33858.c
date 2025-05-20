//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
    }

    // Sort the processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate the completion time, turnaround time, and waiting time for each process
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].completion_time = current_time + processes[i].burst_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        current_time += processes[i].burst_time;
    }

    // Print the Gantt chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d [%d-%d]\n", processes[i].pid, processes[i].arrival_time, processes[i].completion_time);
    }

    // Print the table of processes
    printf("\nTable of Processes:\n");
    printf("%-5s %-12s %-12s %-12s %-12s %-12s\n", "PID", "Arrival Time", "Burst Time", "Completion Time", "Turnaround Time", "Waiting Time");
    for (int i = 0; i < n; i++) {
        printf("%-5d %-12d %-12d %-12d %-12d %-12d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    // Calculate the average turnaround time and waiting time
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= n;
    avg_waiting_time /= n;

    // Print the average turnaround time and waiting time
    printf("\nAverage Turnaround Time: %.2f", avg_turnaround_time);
    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);

    return 0;
}