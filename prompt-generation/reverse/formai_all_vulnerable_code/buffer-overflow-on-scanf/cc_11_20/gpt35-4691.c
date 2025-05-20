//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include <stdio.h>

/*
 * This program demonstrates a unique CPU scheduling algorithm called "Round Robin with Priority", where each process is 
 * given a quantum of time to execute and their priority level is checked after each quantum to determine if 
 * they should receive a higher or lower priority for the next round of execution.
 */

// Structure to hold information about each process
struct process {
    int pid; // Process ID
    int priority; // Priority level (higher number means higher priority)
    int burst_time; // Amount of time needed to complete the process
    int wait_time; // Time spent waiting in the ready queue
    int turnaround_time; // Time taken from arrival to completion
    int remaining_time; // Time remaining to complete the process
    int quantum; // Quantum of time given to the process for execution (default = 4 units)
};

int main() {
    int total_time = 0; // Total time taken to complete all processes
    int num_processes, quantum, i, j, k;
    float average_wait_time = 0, average_turnaround_time = 0;
    struct process temp; // Temporary variable to swap two processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct process processes[num_processes]; // Array of structures to store information about each process
    for(i = 0; i < num_processes; i++) {
        printf("\n");
        printf("Enter details for Process %d:\n", i+1);
        processes[i].pid = i+1;
        printf("Enter priority (1-10): ");
        scanf("%d", &processes[i].priority);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].wait_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].quantum = 4;
        total_time += processes[i].burst_time;
    }
    printf("\nEnter quantum of time for each process: ");
    scanf("%d", &quantum);
    printf("\nProcess Execution Order:\n");
    printf("Time\tPriority\tProcess\n");
    for(i = 0; i < total_time; i += quantum) {
        for(j = 0; j < num_processes; j++) { // Iterate through all processes in the ready queue
            if(processes[j].remaining_time > 0) { // Check if process is not completed yet
                if(processes[j].quantum <= quantum) { // If remaining time of process is less than or equal to the quantum
                    for(k = 0; k < processes[j].remaining_time; k++) { // Execute the process for its remaining time
                        printf("%d\t%d\t\t%d\n", i+k, processes[j].priority, processes[j].pid);
                        processes[j].remaining_time--;
                    }
                } else { // If remaining time of process is greater than the quantum
                    for(k = 0; k < quantum; k++) { // Execute the process for the quantum
                        printf("%d\t%d\t\t%d\n", i+k, processes[j].priority, processes[j].pid);
                        processes[j].remaining_time--;
                    }
                    if(processes[j].priority < 10 && (i+quantum) % 10 == 0) { // Check if process priority needs to be increased
                        processes[j].priority++;
                    }
                }
                if(processes[j].remaining_time == 0) { // If process has completed execution
                    processes[j].wait_time = i - processes[j].burst_time;
                    processes[j].turnaround_time = i;
                }
            }
        }
    }
    // Calculate average wait time and turnaround time
    for(i = 0; i < num_processes; i++) {
        average_wait_time += processes[i].wait_time;
        average_turnaround_time += processes[i].turnaround_time - processes[i].wait_time;
    }
    average_wait_time /= num_processes;
    average_turnaround_time /= num_processes;
    printf("\nAverage Wait Time: %.2f", average_wait_time);
    printf("\nAverage Turnaround Time: %.2f", average_turnaround_time);
    return 0;
}