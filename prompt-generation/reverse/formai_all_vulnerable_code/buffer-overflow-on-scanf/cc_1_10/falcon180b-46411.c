//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

process create_process(int pid, int burst_time) {
    process p;
    p.pid = pid;
    p.burst_time = burst_time;
    p.waiting_time = 0;
    p.turnaround_time = 0;
    return p;
}

void execute_processes(process* processes, int n, int quantum) {
    int i, j, completed_processes = 0;
    int current_time = 0;

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].waiting_time == 0) {
                if (current_time + quantum >= processes[i].burst_time) {
                    processes[i].burst_time -= quantum;
                    processes[i].turnaround_time = current_time + quantum - processes[i].burst_time;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= current_time;
                    current_time += quantum;
                    processes[i].waiting_time += quantum;
                }
            } else if (processes[i].waiting_time > 0) {
                processes[i].waiting_time--;
            }
        }
    }
}

void print_processes(process* processes, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("PID %d: Burst Time %d, Waiting Time %d, Turnaround Time %d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, i;
    process* processes;
    int quantum = 2;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    processes = (process*) malloc(n * sizeof(process));

    for (i = 0; i < n; i++) {
        printf("Enter PID for process %d: ", i+1);
        scanf("%d", &processes[i].pid);
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n, quantum);
    print_processes(processes, n);

    free(processes);
    return 0;
}