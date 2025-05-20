//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 10

// Process structure
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
} Process;

// Scheduling algorithms
enum {
    FCFS,
    SJF,
    SRTF,
    RR
};

// Function prototypes
void fcfs(Process* processes, int num_processes);
void sjf(Process* processes, int num_processes);
void srtf(Process* processes, int num_processes);
void rr(Process* processes, int num_processes);

// Main function
int main() {
    // Initialize processes
    Process processes[MAX_PROCESSES];
    int num_processes = 0;

    // Take input from user
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    for (int i = 0; i < num_processes; i++) {
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority for process %d: ", i);
        scanf("%d", &processes[i].priority);
        processes[i].pid = i;
    }

    // Call the scheduling algorithm
    int algorithm = FCFS;
    printf("Enter the scheduling algorithm: ");
    scanf("%d", &algorithm);

    switch (algorithm) {
        case FCFS:
            fcfs(processes, num_processes);
            break;
        case SJF:
            sjf(processes, num_processes);
            break;
        case SRTF:
            srtf(processes, num_processes);
            break;
        case RR:
            rr(processes, num_processes);
            break;
        default:
            printf("Invalid algorithm\n");
            return 1;
    }

    return 0;
}

// FCFS algorithm
void fcfs(Process* processes, int num_processes) {
    int start_time = 0;
    for (int i = 0; i < num_processes; i++) {
        int arrival_time = processes[i].arrival_time;
        int burst_time = processes[i].burst_time;
        int priority = processes[i].priority;
        int completion_time = start_time + burst_time;

        printf("Process %d: Arrival time = %d, Burst time = %d, Priority = %d, Completion time = %d\n", i, arrival_time, burst_time, priority, completion_time);

        start_time = completion_time;
    }
}

// SJF algorithm
void sjf(Process* processes, int num_processes) {
    int start_time = 0;
    for (int i = 0; i < num_processes; i++) {
        int arrival_time = processes[i].arrival_time;
        int burst_time = processes[i].burst_time;
        int priority = processes[i].priority;
        int completion_time = start_time + burst_time;

        printf("Process %d: Arrival time = %d, Burst time = %d, Priority = %d, Completion time = %d\n", i, arrival_time, burst_time, priority, completion_time);

        start_time = completion_time;
    }
}

// SRTF algorithm
void srtf(Process* processes, int num_processes) {
    int start_time = 0;
    for (int i = 0; i < num_processes; i++) {
        int arrival_time = processes[i].arrival_time;
        int burst_time = processes[i].burst_time;
        int priority = processes[i].priority;
        int completion_time = start_time + burst_time;

        printf("Process %d: Arrival time = %d, Burst time = %d, Priority = %d, Completion time = %d\n", i, arrival_time, burst_time, priority, completion_time);

        start_time = completion_time;
    }
}

// RR algorithm
void rr(Process* processes, int num_processes) {
    int start_time = 0;
    for (int i = 0; i < num_processes; i++) {
        int arrival_time = processes[i].arrival_time;
        int burst_time = processes[i].burst_time;
        int priority = processes[i].priority;
        int completion_time = start_time + burst_time;

        printf("Process %d: Arrival time = %d, Burst time = %d, Priority = %d, Completion time = %d\n", i, arrival_time, burst_time, priority, completion_time);

        start_time = completion_time;
    }
}