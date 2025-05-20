//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define DELAY 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *processes, int n, int quantum) {
    int completed_processes = 0;
    int current_time = 0;
    int current_process = 0;

    while (completed_processes < n) {
        if (processes[current_process].burst_time == 0) {
            processes[current_process].waiting_time += current_time - processes[current_process].waiting_time;
            processes[current_process].turnaround_time += current_time - processes[current_process].turnaround_time;
            completed_processes++;
            current_process = (current_process + 1) % n;
        } else {
            if (processes[current_process].burst_time > quantum) {
                processes[current_process].burst_time -= quantum;
                current_time += quantum;
            } else {
                processes[current_process].burst_time = 0;
                current_time += processes[current_process].burst_time;
            }
        }
    }
}

void print_processes(struct process *processes, int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("Process %d:\n", processes[i].id);
        printf("Burst time: %d\n", processes[i].burst_time);
        printf("Waiting time: %d\n", processes[i].waiting_time);
        printf("Turnaround time: %d\n", processes[i].turnaround_time);
        printf("\n");
    }
}

void round_robin_scheduling(struct process *processes, int n, int quantum) {
    int i;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    execute_processes(processes, n, quantum);

    print_processes(processes, n);
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");

    for (i = 0; i < n; i++) {
        printf("Enter process %d burst time: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    round_robin_scheduling(processes, n, 2);

    return 0;
}