//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
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

void SJF(struct process *process_table, int n) {
    int i, j, min_bt = 999;
    int completed_processes = 0;

    for (i = 0; i < n; i++) {
        if (process_table[i].burst_time <= min_bt) {
            min_bt = process_table[i].burst_time;
        }
    }

    for (i = 0; i < n; i++) {
        if (process_table[i].burst_time == min_bt) {
            process_table[i].waiting_time = 0;
            process_table[i].turnaround_time = min_bt;
            printf("Process %d executed\n", process_table[i].pid);
            completed_processes++;
        }
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (process_table[i].burst_time > min_bt && process_table[i].waiting_time == 0) {
                process_table[i].waiting_time = min_bt;
            }
        }

        for (i = 0; i < n; i++) {
            if (process_table[i].burst_time > min_bt && process_table[i].waiting_time > 0) {
                process_table[i].waiting_time--;
            }
        }

        min_bt = 999;
        for (i = 0; i < n; i++) {
            if (process_table[i].burst_time <= min_bt && process_table[i].waiting_time == 0) {
                min_bt = process_table[i].burst_time;
            }
        }

        for (i = 0; i < n; i++) {
            if (process_table[i].burst_time == min_bt) {
                process_table[i].turnaround_time = min_bt + process_table[i].waiting_time;
                printf("Process %d executed\n", process_table[i].pid);
                completed_processes++;
            }
        }
    }
}

void main() {
    struct process process_table[MAX];
    int i, n, sum_bt = 0, sum_wt = 0, sum_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of the processes:\n");
    for (i = 0; i < n; i++) {
        printf("Enter the PID of process %d: ", i + 1);
        scanf("%d", &process_table[i].pid);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &process_table[i].burst_time);

        sum_bt += process_table[i].burst_time;
    }

    SJF(process_table, n);

    printf("\nAverage waiting time: %.2f\n", (float) sum_wt / n);
    printf("Average turnaround time: %.2f\n", (float) sum_tat / n);
}