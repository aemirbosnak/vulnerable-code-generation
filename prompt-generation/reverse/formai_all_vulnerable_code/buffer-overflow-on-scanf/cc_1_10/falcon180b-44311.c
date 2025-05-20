//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sched.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, sum_wt = 0, sum_tat = 0, current_time = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > TIME_QUANTUM) {
            for (j = 0; j < processes[i].burst_time / TIME_QUANTUM; j++) {
                if (i == 0) {
                    current_time += TIME_QUANTUM;
                } else {
                    sum_wt += TIME_QUANTUM;
                    current_time += TIME_QUANTUM;
                }

                printf("PID %d is executing from time %d to %d\n", processes[i].pid, current_time - TIME_QUANTUM, current_time);
            }
            processes[i].turnaround_time = current_time - processes[i].burst_time - processes[i].waiting_time;
        } else {
            if (i == 0) {
                current_time += processes[i].burst_time;
            } else {
                sum_wt += processes[i].burst_time;
                current_time += processes[i].burst_time;
            }

            printf("PID %d is executing from time %d to %d\n", processes[i].pid, current_time - processes[i].burst_time, current_time);
            processes[i].turnaround_time = current_time - processes[i].burst_time - processes[i].waiting_time;
        }

        sum_tat += processes[i].turnaround_time;
    }

    printf("\nAverage waiting time: %.2f\n", (float) sum_wt / n);
    printf("Average turnaround time: %.2f\n", (float) sum_tat / n);
}

int main() {
    struct process processes[MAX];
    int n, i;

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