//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a process
struct Process {
    int id;
    int burst_time;
    int priority;
    int arrival_time;
};

// Define the structure for a CPU Scheduling algorithm
struct CPU_Scheduling_Algorithm {
    void (*schedule)(struct Process *processes, int num_processes);
};

// Define the FCFS (First-Come-First-Served) CPU Scheduling algorithm
void fcfs(struct Process *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: Burst Time = %d, Priority = %d, Arrival Time = %d\n", processes[i].id, processes[i].burst_time, processes[i].priority, processes[i].arrival_time);
    }
}

// Define the RR (Round-Robin) CPU Scheduling algorithm
void rr(struct Process *processes, int num_processes, int time_slice) {
    int current_process = 0;
    int current_time = 0;
    int time_remaining = 0;

    while (current_time < num_processes) {
        if (time_remaining == 0) {
            current_process = (current_process + 1) % num_processes;
            time_remaining = time_slice;
        }

        printf("Process %d: Burst Time = %d, Priority = %d, Arrival Time = %d\n", processes[current_process].id, processes[current_process].burst_time, processes[current_process].priority, processes[current_process].arrival_time);
        time_remaining--;
        current_time++;
    }
}

// Define the SRT (Shortest Remaining Time) CPU Scheduling algorithm
void srt(struct Process *processes, int num_processes) {
    int current_process = 0;
    int current_time = 0;
    int time_remaining = 0;

    while (current_time < num_processes) {
        if (time_remaining == 0) {
            current_process = 0;
            time_remaining = processes[current_process].burst_time;
        }

        printf("Process %d: Burst Time = %d, Priority = %d, Arrival Time = %d\n", processes[current_process].id, processes[current_process].burst_time, processes[current_process].priority, processes[current_process].arrival_time);
        time_remaining--;
        current_time++;
    }
}

int main() {
    // Initialize the processes
    struct Process processes[3] = {
        {1, 10, 3, 0},
        {2, 5, 5, 10},
        {3, 3, 2, 15}
    };

    // Define the CPU Scheduling algorithms
    struct CPU_Scheduling_Algorithm algorithms[3] = {
        {fcfs},
        {rr},
        {srt}
    };

    // Schedule the processes using the algorithms
    for (int i = 0; i < 3; i++) {
        algorithms[i].schedule(processes, 3);
        printf("\n");
    }

    return 0;
}