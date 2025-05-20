//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process procs[], int n) {
    int i, j, min_bt = 999, pos = 0, completed_processes = 0;
    for (i = 0; i < n; i++) {
        if (procs[i].burst_time <= min_bt) {
            min_bt = procs[i].burst_time;
            pos = i;
        }
    }

    for (i = 0; i < n; i++) {
        if (procs[i].pid == pos) {
            for (j = 0; j < procs[i].burst_time; j++) {
                printf("Process %d is executing\n", pos);
                fflush(stdout);
            }
            procs[i].waiting_time = 0;
            procs[i].turnaround_time = procs[i].burst_time;
            completed_processes++;
        } else {
            procs[i].waiting_time += procs[pos].burst_time;
        }
    }

    if (completed_processes < n) {
        execute_processes(procs, n);
    }
}

void main() {
    struct process procs[MAX];
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &procs[i].burst_time);
    }

    execute_processes(procs, n);
}