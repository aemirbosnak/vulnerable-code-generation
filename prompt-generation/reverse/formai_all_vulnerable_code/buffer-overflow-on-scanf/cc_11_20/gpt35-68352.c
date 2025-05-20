//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROCESSES 50

typedef struct {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
} Process;

int main() {
    int num_processes, i, j, remaining_time, total_waiting_time = 0, total_turnaround_time = 0, time_quantum;
    bool is_completed[MAX_PROCESSES] = {false};
    Process processes[MAX_PROCESSES], temp;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Input burst time and priority for each process
    for (i = 0; i < num_processes; i++) {
        printf("Enter the burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i + 1;
    }

    // Sort the processes based on priority
    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].priority > processes[j].priority) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    // Initialize waiting time and remaining time for each process
    for (i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        remaining_time += processes[i].burst_time;
    }

    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);

    int current_time = 0, time_elapsed = 0;
    while (remaining_time > 0) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0 && processes[i].priority <= processes[0].priority) {
                if (processes[i].burst_time < time_quantum) {
                    time_elapsed = processes[i].burst_time;
                } else {
                    time_elapsed = time_quantum;
                }

                processes[i].burst_time -= time_elapsed;
                remaining_time -= time_elapsed;
                current_time += time_elapsed;

                if (processes[i].burst_time == 0) {
                    is_completed[i] = true;
                    processes[i].turnaround_time = current_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                }
            }
        }
    }

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%3d\t\t%3d\t\t%3d\n", processes[i].pid, processes[i].burst_time, processes[i].priority,
            processes[i].waiting_time, processes[i].turnaround_time);
    }

    float average_waiting_time = (float) total_waiting_time / (float) num_processes;
    float average_turnaround_time = (float) total_turnaround_time / (float) num_processes;
    printf("Average waiting time: %f\nAverage turnaround time: %f\n",
            average_waiting_time, average_turnaround_time);

    return 0;
}