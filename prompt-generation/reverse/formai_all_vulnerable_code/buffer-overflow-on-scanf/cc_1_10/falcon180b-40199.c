//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
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

void execute_processes(struct process processes[], int n) {
    int i, j, sum_wt = 0, sum_tat = 0, max_bt = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        if (max_bt < processes[i].burst_time) {
            max_bt = processes[i].burst_time;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j++) {
            if (j >= TIME_QUANTUM) {
                sum_wt += TIME_QUANTUM;
                processes[i].waiting_time += TIME_QUANTUM;
            } else {
                processes[i].waiting_time += j;
            }

            if (processes[i].burst_time - j - processes[i].waiting_time <= TIME_QUANTUM) {
                processes[i].turnaround_time += processes[i].burst_time - j - processes[i].waiting_time;
            } else {
                processes[i].turnaround_time += TIME_QUANTUM;
            }
        }
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float) sum_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float) sum_tat / n);
}

int main() {
    int i, n;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].pid);

        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}