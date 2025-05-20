//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time <= TIME_QUANTUM) {
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
            current_time += processes[i].burst_time;
            completed_processes++;
        } else {
            processes[i].waiting_time = processes[i].burst_time / TIME_QUANTUM;
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
            current_time += TIME_QUANTUM;
        }
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].waiting_time > 0) {
                processes[i].waiting_time--;
            } else if (processes[i].burst_time > 0) {
                if (processes[i].burst_time <= TIME_QUANTUM) {
                    processes[i].waiting_time = 0;
                    processes[i].turnaround_time = processes[i].burst_time;
                    current_time += processes[i].burst_time;
                    completed_processes++;
                } else {
                    processes[i].waiting_time = processes[i].burst_time / TIME_QUANTUM;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    current_time += TIME_QUANTUM;
                }
            }
        }
    }

    printf("\nExecution completed in %d time units.\n", current_time);
}

int main() {
    int n;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process details:\n");
    printf("Process ID\tBurst Time\n");

    int i;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &processes[i].pid, &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}