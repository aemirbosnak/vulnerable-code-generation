//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
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

void execute_processes(struct process *processes, int n) {
    int quantum = TIME_QUANTUM;
    int current_time = 0;
    int completed_processes = 0;
    int i;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        int min_burst_time = MAX;
        int min_index = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= min_burst_time) {
                min_burst_time = processes[i].burst_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            quantum = MAX;
        } else {
            processes[min_index].burst_time -= quantum;

            if (processes[min_index].burst_time == 0) {
                completed_processes++;
            } else {
                processes[min_index].waiting_time += quantum;
            }
        }

        current_time += quantum;
    }
}

void print_processes(struct process *processes, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Process %d: Burst Time %d, Waiting Time %d, Turnaround Time %d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");

    int i;
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    printf("\nProcesses after execution:\n");
    print_processes(processes, n);

    return 0;
}