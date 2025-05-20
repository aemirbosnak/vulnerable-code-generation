//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MAX_PROCESSES 20

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n) {
    for (int i = 0; i < n; i++) {
        printf("Process %d is executing...\n", processes[i].pid);
        fflush(stdout);
        sleep(processes[i].burst_time / 100);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];
    int n, i, j, sum_wt = 0, sum_tat = 0;
    float avg_wt, avg_tat;
    int quantum = 2;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        printf("Enter process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j += quantum) {
            if (j == 0) {
                execute_processes(processes, n);
            }
            printf("Process %d is waiting...\n", processes[i].pid);
            fflush(stdout);
            sleep(1);
        }
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        sum_wt += processes[i].waiting_time;
        sum_tat += processes[i].turnaround_time;
    }

    avg_wt = (float) sum_wt / n;
    avg_tat = (float) sum_tat / n;

    printf("\nAverage waiting time: %.2f\n", avg_wt);
    printf("Average turnaround time: %.2f\n", avg_tat);

    return 0;
}