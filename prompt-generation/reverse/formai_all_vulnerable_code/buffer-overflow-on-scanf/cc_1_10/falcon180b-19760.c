//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, sum_waiting_time = 0, sum_turnaround_time = 0;
    int quantum = TIME_QUANTUM;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j++) {
            if (j % quantum == 0 && i!= 0) {
                sum_waiting_time++;
            }

            if (j == processes[i].burst_time - 1) {
                sum_turnaround_time = sum_turnaround_time + processes[i].burst_time;
            }
        }
    }

    printf("\nGantt Chart:\n");
    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float) sum_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float) sum_turnaround_time / n);
}

int main() {
    struct process processes[MAX];
    int n, i, sum_burst_time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process id and burst time:\n");

    for (i = 0; i < n; i++) {
        scanf("%d %d", &processes[i].id, &processes[i].burst_time);
        sum_burst_time += processes[i].burst_time;
    }

    execute_processes(processes, n);

    return 0;
}