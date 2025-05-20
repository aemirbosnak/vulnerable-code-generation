//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_SCHEDULE_SIZE 10

typedef struct Process {
    int pid;
    char name[20];
    int cpu_burst;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_PROCESSES];

void schedule() {
    // Create a random schedule
    int schedule_size = rand() % MAX_SCHEDULE_SIZE;
    int i = 0;
    for (i = 0; i < schedule_size; i++) {
        processes[i].cpu_burst = rand() % 10;
    }

    // Calculate waiting time and turnaround time for each process
    for (i = 0; i < MAX_PROCESSES; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = processes[i].cpu_burst + processes[i].waiting_time;
    }

    // Print the schedule
    printf("Process Schedule:\n");
    for (i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Name: %s, CPU Burst: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].pid, processes[i].name, processes[i].cpu_burst, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    // Initialize processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].pid = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].cpu_burst = rand() % 10;
    }

    // Schedule processes
    schedule();

    return 0;
}