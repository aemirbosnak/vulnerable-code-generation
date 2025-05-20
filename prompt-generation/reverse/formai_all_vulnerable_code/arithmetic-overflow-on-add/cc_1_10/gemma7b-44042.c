//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void schedule(Process processes[]) {
    int i, j, quantum = 0, completed = 0;
    processes[0].waiting_time = 0;

    while (!completed) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].burst_time > quantum) {
                processes[i].waiting_time++;
            } else {
                processes[i].burst_time -= quantum;
                processes[i].waiting_time = 0;
                completed++;
            }
        }

        quantum++;
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create processes
    processes[0].process_id = 1;
    processes[0].burst_time = 5;

    processes[1].process_id = 2;
    processes[1].burst_time = 3;

    processes[2].process_id = 3;
    processes[2].burst_time = 4;

    processes[3].process_id = 4;
    processes[3].burst_time = 2;

    processes[4].process_id = 5;
    processes[4].burst_time = 6;

    schedule(processes);

    // Print results
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}