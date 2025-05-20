//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_TIME_Quantum 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int execution_time;
    int waiting_time;
    int turnaround_time;
} Process;

void round_robin(Process processes[], int num_processes) {
    int current_time = 0;
    int next_process_id = 0;
    while (current_time < processes[0].arrival_time) {
        current_time++;
    }

    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time++;
    }

    while (next_process_id < num_processes) {
        processes[next_process_id].waiting_time = 0;
        current_time += processes[next_process_id].execution_time;
        next_process_id++;
    }

    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].execution_time;
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    // Create processes
    processes[num_processes].process_id = 1;
    processes[num_processes].arrival_time = 0;
    processes[num_processes].execution_time = 3;
    num_processes++;

    processes[num_processes].process_id = 2;
    processes[num_processes].arrival_time = 2;
    processes[num_processes].execution_time = 4;
    num_processes++;

    processes[num_processes].process_id = 3;
    processes[num_processes].arrival_time = 1;
    processes[num_processes].execution_time = 2;
    num_processes++;

    round_robin(processes, num_processes);

    // Print results
    for (int i = 0; i < num_processes; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}