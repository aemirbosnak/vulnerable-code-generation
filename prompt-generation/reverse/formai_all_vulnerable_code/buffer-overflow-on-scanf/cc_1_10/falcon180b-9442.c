//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_TIME_QUANTUM 10

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n, int quantum) {
    int i, j, current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (current_time >= processes[i].waiting_time) {
                    if (processes[i].burst_time <= quantum) {
                        processes[i].burst_time = 0;
                        processes[i].waiting_time = 0;
                        processes[i].turnaround_time = current_time - processes[i].waiting_time - processes[i].burst_time;
                        completed_processes++;
                    } else {
                        processes[i].burst_time -= quantum;
                        processes[i].waiting_time += quantum;
                        current_time += quantum;
                    }
                } else {
                    current_time += quantum;
                    processes[i].waiting_time -= quantum;
                }
            }
        }
    }
}

void print_processes(struct process *processes, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Process %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n", i+1, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int i;
    struct process processes[MAX_PROCESS];

    printf("Enter the number of processes: ");
    scanf("%d", &i);

    if (i <= 0 || i > MAX_PROCESS) {
        printf("Invalid number of processes.\n");
        exit(1);
    }

    printf("Enter the burst time for each process:\n");
    for (int j = 0; j < i; j++) {
        scanf("%d", &processes[j].burst_time);
    }

    execute_processes(processes, i, MAX_TIME_QUANTUM);

    printf("Processes completed:\n");
    print_processes(processes, i);

    return 0;
}