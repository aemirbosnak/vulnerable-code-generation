//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INITIAL_QUANTUM 2

typedef struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void add_process(Process *processes, int num_processes, int id, int burst_time) {
    processes[num_processes].id = id;
    processes[num_processes].burst_time = burst_time;
}

void execute_processes(Process *processes, int num_processes, int quantum) {
    int completed_processes = 0;
    int current_time = 0;
    int index = 0;

    while (completed_processes < num_processes) {
        if (processes[index].burst_time > quantum) {
            processes[index].burst_time -= quantum;
            current_time += quantum;
        } else {
            processes[index].burst_time = 0;
            current_time += processes[index].burst_time;
            completed_processes++;
            index++;
        }
    }
}

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    srand(time(NULL));
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process *processes = malloc(num_processes * sizeof(Process));

    for (int i = 0; i < num_processes; i++) {
        add_process(processes, num_processes, i + 1, rand() % 10 + 1);
    }

    int quantum = INITIAL_QUANTUM;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    execute_processes(processes, num_processes, quantum);

    print_processes(processes, num_processes);

    free(processes);

    return 0;
}