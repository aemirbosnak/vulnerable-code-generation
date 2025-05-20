//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    char name[20];
    int cpu_burst_time;
    int waiting_time;
    int turn_around_time;
} Process;

void simulate_cpu_scheduling(Process processes[]) {
    int i, j, quantum_time = 0, total_waiting_time = 0, total_turn_around_time = 0;
    processes[0].waiting_time = 0;

    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].turn_around_time = processes[i].cpu_burst_time + processes[i].waiting_time;
    }

    for (j = 0; j < processes[0].cpu_burst_time; j++) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].waiting_time > 0) {
                processes[i].waiting_time--;
            }
        }

        quantum_time++;
    }

    for (i = 0; i < MAX_PROCESSES; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turn_around_time += processes[i].turn_around_time;
    }

    printf("Total waiting time: %d\n", total_waiting_time);
    printf("Total turn-around time: %d\n", total_turn_around_time);
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create processes
    processes[0].process_id = 1;
    strcpy(processes[0].name, "Process A");
    processes[0].cpu_burst_time = 5;

    processes[1].process_id = 2;
    strcpy(processes[1].name, "Process B");
    processes[1].cpu_burst_time = 3;

    processes[2].process_id = 3;
    strcpy(processes[2].name, "Process C");
    processes[2].cpu_burst_time = 2;

    processes[3].process_id = 4;
    strcpy(processes[3].name, "Process D");
    processes[3].cpu_burst_time = 4;

    processes[4].process_id = 5;
    strcpy(processes[4].name, "Process E");
    processes[4].cpu_burst_time = 6;

    // Simulate CPU scheduling
    simulate_cpu_scheduling(processes);

    return 0;
}