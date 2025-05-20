//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int priority;
} process_t;

int main() {
    int n, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    process_t *processes;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    processes = (process_t *)malloc(n * sizeof(process_t));

    printf("Enter the arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Sort the processes by arrival time
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                process_t temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Round robin scheduling algorithm
    int time = 0;
    int quantum = 2;
    while (1) {
        int completed = 1;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                completed = 0;
                if (processes[i].remaining_time <= quantum) {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    avg_waiting_time += time - processes[i].arrival_time - processes[i].burst_time;
                    avg_turnaround_time += time - processes[i].arrival_time;
                } else {
                    processes[i].remaining_time -= quantum;
                    time += quantum;
                }
            }
        }
        if (completed) {
            break;
        }
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    printf("Average waiting time: %.2f ms\n", avg_waiting_time);
    printf("Average turnaround time: %.2f ms\n", avg_turnaround_time);

    free(processes);
    return 0;
}