//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS_NUMBER 10

typedef struct Process {
    int process_number;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_a_b(Process *processes) {
    for (int i = 0; i < MAX_PROCESS_NUMBER; i++) {
        processes[i].waiting_time = processes[i].burst_time - 1;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void print_processes(Process *processes) {
    for (int i = 0; i < MAX_PROCESS_NUMBER; i++) {
        printf("Process No. %d: ", processes[i].process_number);
        printf("Name: %s ", processes[i].name);
        printf("Burst Time: %d ", processes[i].burst_time);
        printf("Waiting Time: %d ", processes[i].waiting_time);
        printf("Turnaround Time: %d\n", processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESS_NUMBER];

    // Create processes
    processes[0].process_number = 1;
    strcpy(processes[0].name, "Process A");
    processes[0].burst_time = 5;

    processes[1].process_number = 2;
    strcpy(processes[1].name, "Process B");
    processes[1].burst_time = 3;

    processes[2].process_number = 3;
    strcpy(processes[2].name, "Process C");
    processes[2].burst_time = 2;

    // Calculate waiting and turnaround times
    calculate_a_b(processes);

    // Print processes
    print_processes(processes);

    return 0;
}