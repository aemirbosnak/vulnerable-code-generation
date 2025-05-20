//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
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
        if (processes[i].burst_time > quantum) {
            for (j = 0; j < processes[i].burst_time / quantum; j++) {
                printf("Process %d is executing...\n", processes[i].id);
                fflush(stdout);
                sleep(TIME_QUANTUM);
            }
            processes[i].burst_time %= quantum;
        } else {
            printf("Process %d is executing...\n", processes[i].id);
            fflush(stdout);
            sleep(processes[i].burst_time);
        }

        processes[i].waiting_time = processes[i].burst_time;
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;

        sum_waiting_time += processes[i].waiting_time;
        sum_turnaround_time += processes[i].turnaround_time;
    }

    printf("\nAverage waiting time: %.2f\n", (float) sum_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float) sum_turnaround_time / n);
}

int main() {
    int n;
    struct process processes[MAX];

    printf("Enter number of processes (maximum %d): ", MAX);
    scanf("%d", &n);

    printf("\nEnter details of %d processes:\n", n);

    for (int i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}