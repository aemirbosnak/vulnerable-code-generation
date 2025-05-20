//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

struct process {
    int pid;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

int main() {
    int n, quantum;
    struct process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].pid = i + 1;
    }

    int time = 0;
    int completed_processes = 0;
    while (completed_processes < n) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].waiting_time = time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = time;
                    completed_processes++;
                }
            }
        }
    }

    float avg_waiting_time = 0, avg_turnaround_time = 0;
    printf("PID  Burst Time  Waiting Time  Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%-4d%-12d%-14d%-16d\n", processes[i].pid, processes[i].burst_time, 
            processes[i].waiting_time, processes[i].turnaround_time);
        avg_waiting_time += processes[i].waiting_time;
        avg_turnaround_time += processes[i].turnaround_time;
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}