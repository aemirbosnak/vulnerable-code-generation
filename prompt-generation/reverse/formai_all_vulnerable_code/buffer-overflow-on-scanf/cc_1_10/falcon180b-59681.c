//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *process_table, int n, int quantum) {
    int i, j, sum_waiting_time = 0, sum_turnaround_time = 0, completed_processes = 0;
    int current_time = 0, next_process_index = 0;

    for (i = 0; i < n; i++) {
        process_table[i].waiting_time = 0;
        process_table[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        if (next_process_index >= n) {
            next_process_index = 0;
        }

        if (process_table[next_process_index].burst_time > quantum) {
            process_table[next_process_index].burst_time -= quantum;
            current_time += quantum;
        } else {
            process_table[next_process_index].burst_time = 0;
            current_time += process_table[next_process_index].burst_time;
        }

        completed_processes++;

        for (j = 0; j < n; j++) {
            if (process_table[j].burst_time > 0 && process_table[j].waiting_time > 0 && process_table[j].waiting_time <= current_time) {
                process_table[j].burst_time -= quantum;
                current_time += quantum;
                process_table[j].waiting_time -= quantum;
            }
        }
    }

    for (i = 0; i < n; i++) {
        sum_waiting_time += process_table[i].waiting_time;
        sum_turnaround_time += process_table[i].turnaround_time;
    }

    printf("Average waiting time: %d\n", sum_waiting_time / n);
    printf("Average turnaround time: %d\n", sum_turnaround_time / n);
}

int main() {
    struct process process_table[MAX];
    int n, i, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times of the processes:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &process_table[i].burst_time);
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    execute_processes(process_table, n, quantum);

    return 0;
}