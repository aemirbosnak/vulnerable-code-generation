//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    char name;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_statistics(Process *processes) {
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < MAX_PROCESSES; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Total waiting time: %d\n", total_waiting_time);
    printf("Total turnaround time: %d\n", total_turnaround_time);
}

int main() {
    Process processes[MAX_PROCESSES];

    // Initialize processes
    processes[0].process_id = 1;
    processes[0].name = 'A';
    processes[0].burst_time = 5;

    processes[1].process_id = 2;
    processes[1].name = 'B';
    processes[1].burst_time = 3;

    processes[2].process_id = 3;
    processes[2].name = 'C';
    processes[2].burst_time = 8;

    processes[3].process_id = 4;
    processes[3].name = 'D';
    processes[3].burst_time = 2;

    processes[4].process_id = 5;
    processes[4].name = 'E';
    processes[4].burst_time = 4;

    // Calculate statistics
    calculate_statistics(processes);

    return 0;
}