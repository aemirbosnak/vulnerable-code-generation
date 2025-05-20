//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_QUANTA 5

typedef struct {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

void execute_processes(process *processes, int num_processes, int quantum) {
    int current_time = 0;
    int completed_processes = 0;
    int current_process = 0;

    while (completed_processes < num_processes) {
        if (current_time >= processes[current_process].burst_time) {
            completed_processes++;
            current_time = 0;
            current_process = (current_process + 1) % num_processes;
        } else {
            if (current_time >= quantum) {
                processes[current_process].waiting_time += quantum;
                current_time = 0;
                current_process = (current_process + 1) % num_processes;
            } else {
                current_time++;
            }
        }
    }
}

void print_processes(process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: burst time = %d, waiting time = %d, turnaround time = %d\n",
               processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    srand(time(NULL));

    process processes[MAX_PROCESSES];

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].id = i;
        processes[i].burst_time = rand() % 101;
    }

    int num_processes = rand() % (MAX_PROCESSES - 1) + 1;

    for (int i = 0; i < num_processes; i++) {
        processes[i].burst_time = rand() % 101;
    }

    int quantum = rand() % MAX_QUANTA + 1;

    execute_processes(processes, num_processes, quantum);

    print_processes(processes, num_processes);

    return 0;
}