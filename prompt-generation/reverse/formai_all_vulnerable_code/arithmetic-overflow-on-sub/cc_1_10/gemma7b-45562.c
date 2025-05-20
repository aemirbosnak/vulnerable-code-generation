//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 10

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
} Process;

void calculate_waiting_time(Process *processes) {
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i].waiting_time = processes[i].arrival_time - processes[i].burst_time;
    }
}

void calculate_turn_around_time(Process *processes) {
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i].turn_around_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

int main() {
    Process processes[MAX_PROCESS];

    // Create processes
    processes[0].process_id = 0;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 5;

    processes[1].process_id = 1;
    processes[1].arrival_time = 2;
    processes[1].burst_time = 3;

    processes[2].process_id = 2;
    processes[2].arrival_time = 4;
    processes[2].burst_time = 6;

    // Calculate waiting time and turn around time
    calculate_waiting_time(processes);
    calculate_turn_around_time(processes);

    // Print results
    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process ID: %d, Arrival Time: %d, Burst Time: %d, Waiting Time: %d, Turn Around Time: %d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turn_around_time);
    }

    return 0;
}