//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute(struct process *processes, int n, int quantum) {
    int i, j, completed_processes = 0;
    int current_time = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].burst_time <= quantum) {
                    processes[i].burst_time = 0;
                    processes[i].waiting_time += quantum - processes[i].burst_time;
                    processes[i].turnaround_time += processes[i].waiting_time + processes[i].burst_time;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= quantum;
                    current_time += quantum;
                }
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i, j, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process details:\n");
    for (i = 0; i < n; i++) {
        printf("Enter PID of process %d: ", i+1);
        scanf("%d", &processes[i].pid);

        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);

    execute(processes, n, quantum);

    return 0;
}