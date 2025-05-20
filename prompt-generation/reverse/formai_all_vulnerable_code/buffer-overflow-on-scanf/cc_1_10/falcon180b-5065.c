//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
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
    int current_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        int smallest_burst_time = MAX;
        int smallest_index = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= smallest_burst_time) {
                smallest_burst_time = processes[i].burst_time;
                smallest_index = i;
            }
        }

        if (smallest_index == -1) {
            current_time += TIME_QUANTUM;
        } else {
            processes[smallest_index].burst_time -= TIME_QUANTUM;
            current_time += TIME_QUANTUM;

            if (processes[smallest_index].burst_time > 0) {
                processes[smallest_index].waiting_time += current_time - processes[smallest_index].turnaround_time - processes[smallest_index].burst_time;
            } else {
                processes[smallest_index].turnaround_time = current_time - processes[smallest_index].turnaround_time - processes[smallest_index].burst_time;
                completed_processes++;
            }
        }
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");

    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}