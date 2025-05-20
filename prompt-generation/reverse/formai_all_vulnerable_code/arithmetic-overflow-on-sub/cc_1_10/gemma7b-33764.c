//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct process {
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int turnaround_time;
} process;

process processes[MAX_PROCESS];

void simulate_cpu(int quantum) {
    int i = 0;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (i = 1; i < MAX_PROCESS; i++) {
        processes[i].waiting_time = processes[i - 1].turnaround_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }

    printf("Process ID | Name | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("-------------------------------------------------------------------\n");

    for (i = 0; i < MAX_PROCESS; i++) {
        printf("%d | %s | %d | %d | %d |\n", processes[i].pid, processes[i].name, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int quantum = 3;
    time_t start_time, end_time;

    // Generate processes
    for (int i = 0; i < MAX_PROCESS; i++) {
        processes[i].pid = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burst_time = rand() % 5 + 1;
    }

    // Start timer
    start_time = time(NULL);

    // Simulate CPU
    simulate_cpu(quantum);

    // End timer
    end_time = time(NULL);

    // Calculate time taken
    int time_taken = end_time - start_time;

    // Print time taken
    printf("Time taken: %d seconds\n", time_taken);

    return 0;
}