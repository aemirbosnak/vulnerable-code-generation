//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void roundrobin(Process processes[], int num_processes) {
    int current_process = 0;
    int time_quantum = 5;

    while (processes[current_process].burst_time > 0) {
        printf("Process %d is running...\n", processes[current_process].process_id);
        processes[current_process].burst_time -= time_quantum;
        processes[current_process].waiting_time++;
        processes[current_process].turnaround_time++;

        current_process = (current_process + 1) % num_processes;
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create processes
    processes[0].process_id = 1;
    strcpy(processes[0].name, "Process A");
    processes[0].burst_time = 8;

    processes[1].process_id = 2;
    strcpy(processes[1].name, "Process B");
    processes[1].burst_time = 12;

    processes[2].process_id = 3;
    strcpy(processes[2].name, "Process C");
    processes[2].burst_time = 6;

    processes[3].process_id = 4;
    strcpy(processes[3].name, "Process D");
    processes[3].burst_time = 10;

    processes[4].process_id = 5;
    strcpy(processes[4].name, "Process E");
    processes[4].burst_time = 4;

    // Round Robin scheduling
    roundrobin(processes, MAX_PROCESSES);

    // Print results
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d: \n", processes[i].process_id);
        printf("Waiting Time: %d\n", processes[i].waiting_time);
        printf("Turnaround Time: %d\n", processes[i].turnaround_time);
        printf("\n");
    }

    return 0;
}