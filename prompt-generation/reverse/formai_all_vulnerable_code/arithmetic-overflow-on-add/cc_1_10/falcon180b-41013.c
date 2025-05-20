//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_PROCESS_NAME_LENGTH 20
#define MAX_PROCESS_PRIORITY 10

typedef struct process {
    char name[MAX_PROCESS_NAME_LENGTH];
    int priority;
    int time_slice;
    int remaining_time_slice;
    int total_time_slices;
} Process;

void initialize_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        processes[i].priority = rand() % MAX_PROCESS_PRIORITY;
        processes[i].time_slice = rand() % 10;
        processes[i].remaining_time_slice = processes[i].time_slice;
        processes[i].total_time_slices = 0;
    }
}

void print_processes(Process* processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %s: priority %d, time slice %d, remaining time slice %d, total time slices %d\n",
               processes[i].name, processes[i].priority, processes[i].time_slice, processes[i].remaining_time_slice, processes[i].total_time_slices);
    }
}

void run_process(Process* current_process, int quantum) {
    if (current_process->remaining_time_slice > 0) {
        current_process->remaining_time_slice--;
        current_process->total_time_slices++;
    } else {
        current_process->remaining_time_slice = current_process->time_slice;
        current_process->total_time_slices++;
    }
}

void round_robin_scheduling(Process* processes, int num_processes, int quantum) {
    int current_process_index = 0;
    while (1) {
        run_process(&processes[current_process_index], quantum);
        if (processes[current_process_index].total_time_slices >= num_processes * processes[current_process_index].time_slice) {
            break;
        }
        current_process_index = (current_process_index + 1) % num_processes;
    }
}

int main() {
    srand(time(NULL));

    Process processes[MAX_PROCESSES];
    int num_processes = rand() % MAX_PROCESSES;

    initialize_processes(processes, num_processes);
    print_processes(processes, num_processes);

    int quantum = rand() % 100;
    printf("Using a time quantum of %d\n", quantum);

    round_robin_scheduling(processes, num_processes, quantum);

    return 0;
}