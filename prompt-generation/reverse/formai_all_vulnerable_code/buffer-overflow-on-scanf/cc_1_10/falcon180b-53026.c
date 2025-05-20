//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
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

void execute_processes(struct process processes[], int n) {
    int i, j, sum_waiting_time = 0, sum_turnaround_time = 0;
    int current_time = 0;

    for (i = 0; i < n; i++) {
        printf("\nProcess %d arrived at time %d", processes[i].pid, current_time);
        processes[i].waiting_time = current_time;

        for (j = 0; j < i; j++) {
            if (processes[i].burst_time <= processes[j].burst_time) {
                sum_waiting_time += processes[i].waiting_time;
                break;
            }
        }

        if (i == 0) {
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        }
        else {
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time - sum_waiting_time;
        }

        sum_waiting_time += processes[i].burst_time;
        sum_turnaround_time += processes[i].turnaround_time;

        printf("\nProcess %d started executing at time %d", processes[i].pid, current_time);
        printf("\nProcess %d completed execution at time %d", processes[i].pid, current_time + processes[i].burst_time);
        current_time += processes[i].burst_time;
    }

    printf("\nAverage waiting time: %f", (float) sum_waiting_time / n);
    printf("\nAverage turnaround time: %f", (float) sum_turnaround_time / n);
}

int main() {
    int i, n;
    struct process processes[MAX];

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process ID, burst time, and priority for each process:\n");

    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i+1);
        scanf("%d %d", &processes[i].pid, &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}