//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void simulate_cpu_scheduling(Process processes[]) {
    int quantum = 5;
    int time_slice = 0;
    int completed_processes = 0;

    while (!completed_processes) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].burst_time > 0) {
                processes[i].waiting_time++;
            }
        }

        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].burst_time <= quantum && processes[i].waiting_time > 0) {
                processes[i].burst_time--;
                processes[i].waiting_time = 0;
                completed_processes++;
            }
        }

        time_slice++;
    }

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].turnaround_time = time_slice - processes[i].waiting_time;
    }

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create processes
    processes[0].process_id = 1;
    processes[0].burst_time = 8;
    processes[1].process_id = 2;
    processes[1].burst_time = 4;
    processes[2].process_id = 3;
    processes[2].burst_time = 6;
    processes[3].process_id = 4;
    processes[3].burst_time = 2;
    processes[4].process_id = 5;
    processes[4].burst_time = 5;

    simulate_cpu_scheduling(processes);

    return 0;
}