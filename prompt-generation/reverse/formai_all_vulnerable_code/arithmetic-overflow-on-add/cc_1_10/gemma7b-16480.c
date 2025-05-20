//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int pid;
    char name[20];
    int cpu_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculate_cpu_time(Process *process) {
    process->waiting_time = 0;
    process->turnaround_time = process->cpu_time + process->waiting_time;
}

void simulate_cpu(Process *processes) {
    int i = 0;
    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].waiting_time++;
        if (processes[i].waiting_time >= processes[i].cpu_time) {
            calculate_cpu_time(&processes[i]);
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Create and initialize processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i + 1;
        sprintf(processes[i].name, "Process %d", processes[i].pid);
        processes[i].cpu_time = rand() % 5 + 1;
    }

    // Simulate CPU scheduling
    simulate_cpu(processes);

    // Print results
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process: %s\n", processes[i].name);
        printf("CPU Time: %d\n", processes[i].cpu_time);
        printf("Waiting Time: %d\n", processes[i].waiting_time);
        printf("Turnaround Time: %d\n", processes[i].turnaround_time);
        printf("\n");
    }

    return 0;
}