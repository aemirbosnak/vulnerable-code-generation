//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSES 10
#define MAX_PROCESSES 100
#define MAX_PRIORITY 100
#define MAX_TIME_QUANTUM 10

typedef struct process {
    int pid;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int time_quantum;
} Process;

void init_processes(Process *processes) {
    int i;
    for (i = 0; i < NUM_PROCESSES; i++) {
        processes[i].pid = i + 1;
        processes[i].priority = rand() % MAX_PRIORITY + 1;
        processes[i].burst_time = rand() % MAX_TIME_QUANTUM + 1;
    }
}

int compare_priority(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;
    return p1->priority - p2->priority;
}

int compare_burst_time(const void *a, const void *b) {
    const Process *p1 = a;
    const Process *p2 = b;
    return p2->burst_time - p1->burst_time;
}

void print_processes(Process *processes, int num_processes) {
    int i;
    for (i = 0; i < num_processes; i++) {
        printf("PID: %d, Priority: %d, Burst Time: %d\n", processes[i].pid, processes[i].priority, processes[i].burst_time);
    }
}

int main() {
    Process processes[NUM_PROCESSES];
    init_processes(processes);
    qsort(processes, NUM_PROCESSES, sizeof(Process), compare_priority);

    int i, j, quantum = 0;
    for (i = 0; i < NUM_PROCESSES; i++) {
        for (j = 0; j < processes[i].burst_time; j++) {
            if (quantum == MAX_TIME_QUANTUM) {
                quantum = 0;
            }
            printf("CPU is executing process %d for time quantum %d\n", processes[i].pid, quantum);
            quantum++;
        }
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    qsort(processes, NUM_PROCESSES, sizeof(Process), compare_burst_time);
    print_processes(processes, NUM_PROCESSES);

    return 0;
}