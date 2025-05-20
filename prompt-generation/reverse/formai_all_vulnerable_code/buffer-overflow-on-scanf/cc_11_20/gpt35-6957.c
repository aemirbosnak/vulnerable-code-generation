//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 100
#define TIME_QUANTUM 4

typedef struct {
    int pid; // Process ID
    int burst_time; // Burst time required by process
    int remaining_time; // Remaining burst time of process
    int arrival_time; // Arrival time of process
    int wait_time; // Waiting time of process
    int turnaround_time; // Total turnaround time of process
} process;

int main() {
    int total_processes, total_burst_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &total_processes);

    process processes[MAX_PROCESSES];

    for (int i = 0; i < total_processes; i++) {
        printf("\nProcess %d\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);

        printf("Enter arrival time: ");
        scanf("%d", &processes[i].arrival_time);

        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;

        total_burst_time += processes[i].burst_time;
    }

    int current_time = 0, completed_processes = 0;
    srand(time(NULL)); // Seed the random generator

    printf("\nStarting CPU scheduling...\n");

    // Run CPU scheduling until all processes are completed
    while (completed_processes < total_processes) {
        int current_process_index = -1;
        int min_remaining_time = MAX_PROCESSES;

        // Find the process with the shortest remaining burst time
        for (int i = 0; i < total_processes; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < min_remaining_time) {
                current_process_index = i;
                min_remaining_time = processes[i].remaining_time;
            }
        }

        if (current_process_index == -1) { // If no process is available to run, randomly select one
            current_process_index = rand() % total_processes;
        }

        // Run the current process for the time quantum or until it completes its burst time
        int time_remaining = TIME_QUANTUM;
        if (processes[current_process_index].remaining_time < TIME_QUANTUM) {
            time_remaining = processes[current_process_index].remaining_time;
        }

        for (int i = 0; i < time_remaining; i++) {
            printf("Time: %d, Running process %d\n", current_time + i, processes[current_process_index].pid);
        }

        processes[current_process_index].remaining_time -= time_remaining;
        current_time += time_remaining;

        // If process has completed, calculate wait time and turnaround time
        if (processes[current_process_index].remaining_time == 0) {
            processes[current_process_index].turnaround_time = current_time - processes[current_process_index].arrival_time;
            processes[current_process_index].wait_time = processes[current_process_index].turnaround_time - processes[current_process_index].burst_time;

            completed_processes++;
        }
    }

    printf("\nCPU scheduling complete!\n");

    // Calculate total wait time and total turnaround time for all processes
    int total_wait_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < total_processes; i++) {
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Print the results
    printf("\nAverage wait time: %.2f\n", (float) total_wait_time / total_processes);
    printf("Average turnaround time: %.2f\n", (float) total_turnaround_time / total_processes);
    printf("Total CPU time required: %d\n", total_burst_time);

    return 0;
}