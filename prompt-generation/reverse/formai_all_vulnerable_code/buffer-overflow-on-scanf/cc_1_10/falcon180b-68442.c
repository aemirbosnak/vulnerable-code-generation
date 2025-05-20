//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_PROCESS_NAME 20
#define MAX_PROCESS_ARRAY_SIZE 100

typedef struct process {
    int id;
    char name[MAX_PROCESS_NAME];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void init_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Enter process name for process %d: ", i+1);
        scanf("%s", processes[i].name);
        printf("Enter burst time for process %s: ", processes[i].name);
        scanf("%d", &processes[i].burst_time);
    }
}

void execute_processes(Process *processes, int num_processes, int quantum) {
    int completed_processes = 0;
    int current_time = 0;
    int current_process = 0;

    while (completed_processes < num_processes) {
        if (processes[current_process].burst_time <= quantum) {
            processes[current_process].burst_time -= quantum;
            completed_processes++;
        } else {
            processes[current_process].burst_time -= quantum;
            current_time += quantum;
        }

        if (completed_processes < num_processes - 1) {
            current_process = (current_process + 1) % num_processes;
        } else {
            break;
        }
    }

    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = current_time - processes[i].burst_time + processes[i].waiting_time;
    }
}

void print_processes(Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %s completed in %d time units with turnaround time of %d\n", processes[i].name, processes[i].burst_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESS];
    int num_processes;

    printf("Enter number of processes (1-%d): ", MAX_PROCESS);
    scanf("%d", &num_processes);

    init_processes(processes, num_processes);

    printf("Enter time quantum: ");
    int quantum;
    scanf("%d", &quantum);

    execute_processes(processes, num_processes, quantum);

    print_processes(processes, num_processes);

    return 0;
}