//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
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
    int quantum = TIME_QUANTUM;

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > max_bt) {
            max_bt = processes[i].burst_time;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j++) {
            if (j == quantum) {
                sum_wt++;
            }

            if (i == 0) {
                printf("CPU is idle\n");
            } else {
                printf("Process %d is being executed\n", processes[i].pid);
            }

            if (j == processes[i].burst_time - 1) {
                printf("Process %d has completed its execution\n\n", processes[i].pid);
            }

            fflush(stdout);
            sleep(1);
        }
    }

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = processes[i].burst_time - max_bt;
        sum_tat += processes[i].turnaround_time;
    }

    printf("Average waiting time: %.2f\n", (float) sum_wt / n);
    printf("Average turnaround time: %.2f\n", (float) sum_tat / n);
}

int main() {
    int n, i;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}