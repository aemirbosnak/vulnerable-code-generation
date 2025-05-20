//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int pid;
    char name[20];
    int cpu_burst;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_waiting_time(Process *processes) {
    int i = 0;
    for (processes; i < MAX_PROCESSES; i++) {
        processes[i].waiting_time = processes[i].cpu_burst - 1;
    }
}

void calculate_turnaround_time(Process *processes) {
    int i = 0;
    for (processes; i < MAX_PROCESSES; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].cpu_burst;
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create processes
    processes[0].pid = 1;
    strcpy(processes[0].name, "Process A");
    processes[0].cpu_burst = 5;

    processes[1].pid = 2;
    strcpy(processes[1].name, "Process B");
    processes[1].cpu_burst = 3;

    processes[2].pid = 3;
    strcpy(processes[2].name, "Process C");
    processes[2].cpu_burst = 2;

    // Calculate waiting time and turnaround time
    calculate_waiting_time(processes);
    calculate_turnaround_time(processes);

    // Print results
    printf("Process\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%s\t%d\t%d\n", processes[i].name, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}