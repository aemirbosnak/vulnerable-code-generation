//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

int main(void) {
    int quantum;
    int num_processes;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process *processes = malloc(num_processes * sizeof(Process));

    for (int i = 0; i < num_processes; i++) {
        printf("Enter the priority and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].priority, &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("\n");

    int time = 0;

    while (1) {
        int all_finished = 1;

        for (int i = 0; i < num_processes; i++) {
            if (processes[i].burst_time > 0) {
                all_finished = 0;

                if (processes[i].burst_time > quantum) {
                    processes[i].burst_time -= quantum;
                    time += quantum;
                } else {
                    time += processes[i].burst_time;
                    processes[i].burst_time = 0;
                    processes[i].turnaround_time = time;
                }
            }
        }

        if (all_finished) {
            break;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[j].priority > processes[i].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }

        printf("Process %d: waiting time = %d, turnaround time = %d\n", processes[i].id, processes[i].turnaround_time - processes[i].priority - processes[i].waiting_time, processes[i].turnaround_time - processes[i].priority);
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average waiting time = %.2f\n", (float)total_waiting_time / (float)num_processes);
    printf("Average turnaround time = %.2f\n", (float)total_turnaround_time / (float)num_processes);

    free(processes);

    return 0;
}