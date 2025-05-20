//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int pid;
    char name[20];
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void calculateTurnaroundTime(Process *process) {
    process->turnaroundTime = process->waitingTime + process->burstTime;
}

void simulateCPU(Process *processes) {
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < MAX_PROCESSES) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            Process *process = &processes[i];

            if (process->waitingTime <= currentTime && process->burstTime > 0) {
                process->waitingTime = 0;
                process->burstTime--;
                currentTime++;

                if (process->burstTime == 0) {
                    completedProcesses++;
                }
            }
        }

        if (completedProcesses == MAX_PROCESSES) {
            printf("All processes completed!\n");
        } else {
            printf("Current time: %d\n", currentTime);
            printf("Processes waiting: %d\n", MAX_PROCESSES - completedProcesses);
            printf("------------------------\n");
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    // Initialize processes
    processes[0].pid = 1;
    strcpy(processes[0].name, "Alice");
    processes[0].burstTime = 5;

    processes[1].pid = 2;
    strcpy(processes[1].name, "Bob");
    processes[1].burstTime = 8;

    processes[2].pid = 3;
    strcpy(processes[2].name, "Charlie");
    processes[2].burstTime = 3;

    processes[3].pid = 4;
    strcpy(processes[3].name, "Dave");
    processes[3].burstTime = 4;

    processes[4].pid = 5;
    strcpy(processes[4].name, "Eve");
    processes[4].burstTime = 6;

    // Calculate turnaround time for each process
    for (int i = 0; i < MAX_PROCESSES; i++) {
        calculateTurnaroundTime(&processes[i]);
    }

    // Simulate CPU
    simulateCPU(processes);

    return 0;
}