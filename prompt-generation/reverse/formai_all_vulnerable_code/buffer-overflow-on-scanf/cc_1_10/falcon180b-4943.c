//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100
#define INITIAL_QUANTUM 5

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n) {
    int quantum = INITIAL_QUANTUM;
    int completed_processes = 0;
    int current_time = 0;

    while (completed_processes < n) {
        int i;
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].burst_time <= quantum) {
                    processes[i].burst_time = 0;
                    processes[i].waiting_time += quantum;
                    processes[i].turnaround_time += quantum;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= quantum;
                    current_time += quantum;
                }
            }
        }
    }
}

void print_processes(struct process *processes, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Process %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i;
    char *input;
    int id, burst_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        input = fgets(processes[i].id, sizeof(processes[i].id), stdin);
        processes[i].id = atoi(input);
        input = fgets(processes[i].burst_time, sizeof(processes[i].burst_time), stdin);
        processes[i].burst_time = atoi(input);
    }

    execute_processes(processes, n);

    printf("Processes completed in the following order:\n");
    for (i = 0; i < n; i++) {
        if (processes[i].burst_time == 0) {
            printf("Process %d\n", processes[i].id);
        }
    }

    print_processes(processes, n);

    return 0;
}