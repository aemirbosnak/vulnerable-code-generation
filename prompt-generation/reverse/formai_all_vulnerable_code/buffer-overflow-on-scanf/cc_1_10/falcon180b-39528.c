//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define DELAY 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n) {
    int i, j, sum_waiting_time = 0, sum_turnaround_time = 0;
    int quantum = DELAY;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    int completed_processes = 0;

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].burst_time <= quantum) {
                    processes[i].burst_time = 0;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= quantum;
                    sum_waiting_time += quantum;
                    sum_turnaround_time += quantum;
                }
            }
        }
    }

    printf("Average waiting time: %.2f\n", (float) sum_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float) sum_turnaround_time / n);
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the details of %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}