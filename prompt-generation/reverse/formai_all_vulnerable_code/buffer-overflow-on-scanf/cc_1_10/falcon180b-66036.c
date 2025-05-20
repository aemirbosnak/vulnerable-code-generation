//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute(struct process *processes, int n, int quantum) {
    int i, j, temp;
    int count = 0;
    int completed_processes = 0;
    int time_quantum = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (time_quantum + processes[i].burst_time <= quantum) {
                    time_quantum += processes[i].burst_time;
                    processes[i].burst_time = 0;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= quantum;
                    time_quantum = quantum;
                }
            }
        }
        count++;
    }

    printf("\n\nGantt chart for Round Robin Scheduling:\n");
    for (i = 0; i < n; i++) {
        printf("P%d ", processes[i].pid);
        for (j = 0; j < processes[i].turnaround_time; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void main() {
    int n, quantum, i;
    struct process processes[MAX];

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter the details of process %d:\n", i + 1);
        printf("Enter process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);

    execute(processes, n, quantum);
}