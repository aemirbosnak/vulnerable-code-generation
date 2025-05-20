//MISTRAL-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

void create_processes(struct process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].arrival_time = rand() % 5;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }
}

void round_robin_scheduling(struct process *processes, int n, int quantum) {
    int time = 0, i = 0;
    int completed = 0;
    while (completed < n) {
        if (processes[i].arrival_time <= time && processes[i].burst_time > 0) {
            if (processes[i].burst_time <= quantum) {
                time += processes[i].burst_time;
                processes[i].turnaround_time = time - processes[i].arrival_time;
                processes[i].burst_time = 0;
                completed++;
            } else {
                time += quantum;
                processes[i].burst_time -= quantum;
            }
            i = (i + 1) % n;
        } else {
            i = (i + 1) % n;
        }
    }
}

void print_results(struct process *processes, int n) {
    printf("\nProcess ID | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d | %d | %d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    create_processes(processes, n);

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    round_robin_scheduling(processes, n, quantum);

    print_results(processes, n);

    return 0;
}