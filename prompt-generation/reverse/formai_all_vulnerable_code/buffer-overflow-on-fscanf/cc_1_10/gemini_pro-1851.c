//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Ada Lovelace CPU Scheduling Algorithms
//
// This program simulates the execution of a set of processes on a
// single-core CPU. The program uses three different CPU scheduling
// algorithms: first-come first-served (FCFS), shortest job first
// (SJF), and round-robin (RR).
//
// The program takes as input a text file containing the following
// information for each process:
//
// * Process ID
// * Arrival time
// * Burst time
//
// The program then simulates the execution of the processes using the
// specified CPU scheduling algorithm. The program outputs the following
// information for each process:
//
// * Process ID
// * Start time
// * Finish time
// * Turnaround time
// * Waiting time
//
// The program also outputs the average turnaround time and average
// waiting time for all processes.

// Process structure
typedef struct process {
    int pid;         // Process ID
    int arrival_time; // Arrival time
    int burst_time;  // Burst time
    int start_time;  // Start time
    int finish_time; // Finish time
    int turnaround_time; // Turnaround time
    int waiting_time;  // Waiting time
} process;

// CPU scheduling algorithm
typedef enum scheduling_algorithm {
    FCFS,
    SJF,
    RR
} scheduling_algorithm;

// Compare function for processes
int compare_processes(const void *a, const void *b) {
    const process *p1 = (const process *)a;
    const process *p2 = (const process *)b;

    return p1->arrival_time - p2->arrival_time;
}

// First-come first-served (FCFS) scheduling algorithm
void fcfs(process *processes, int num_processes) {
    // Sort the processes by arrival time
    qsort(processes, num_processes, sizeof(process), compare_processes);

    // Initialize the simulation time
    int time = 0;

    // Simulate the execution of the processes
    for (int i = 0; i < num_processes; i++) {
        // Set the start time of the process
        processes[i].start_time = time;

        // Increment the simulation time by the burst time of the process
        time += processes[i].burst_time;

        // Set the finish time of the process
        processes[i].finish_time = time;

        // Calculate the turnaround time and waiting time of the process
        processes[i].turnaround_time = processes[i].finish_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

// Shortest job first (SJF) scheduling algorithm
void sjf(process *processes, int num_processes) {
    // Sort the processes by burst time
    qsort(processes, num_processes, sizeof(process), compare_processes);

    // Initialize the simulation time
    int time = 0;

    // Simulate the execution of the processes
    for (int i = 0; i < num_processes; i++) {
        // Set the start time of the process
        processes[i].start_time = time;

        // Increment the simulation time by the burst time of the process
        time += processes[i].burst_time;

        // Set the finish time of the process
        processes[i].finish_time = time;

        // Calculate the turnaround time and waiting time of the process
        processes[i].turnaround_time = processes[i].finish_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}

// Round-robin (RR) scheduling algorithm
void rr(process *processes, int num_processes, int quantum) {
    // Initialize the simulation time and the current process
    int time = 0;
    int current_process = 0;

    // Simulate the execution of the processes
    while (current_process < num_processes) {
        // Set the start time of the process
        processes[current_process].start_time = time;

        // Increment the simulation time by the quantum
        time += quantum;

        // If the process has finished executing, set the finish time
        if (processes[current_process].burst_time <= quantum) {
            processes[current_process].finish_time = time;

            // Calculate the turnaround time and waiting time of the process
            processes[current_process].turnaround_time = processes[current_process].finish_time - processes[current_process].arrival_time;
            processes[current_process].waiting_time = processes[current_process].turnaround_time - processes[current_process].burst_time;

            // Move to the next process
            current_process++;
        } else {
            // If the process has not finished executing, decrement the burst time
            processes[current_process].burst_time -= quantum;

            // Move to the next process
            current_process = (current_process + 1) % num_processes;
        }
    }
}

// Print the results of the simulation
void print_results(process *processes, int num_processes) {
    // Calculate the average turnaround time and average waiting time
    float avg_turnaround_time = 0.0;
    float avg_waiting_time = 0.0;
    for (int i = 0; i < num_processes; i++) {
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
    }
    avg_turnaround_time /= num_processes;
    avg_waiting_time /= num_processes;

    // Print the results
    printf("Process ID\tArrival Time\tBurst Time\tStart Time\tFinish Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].start_time, processes[i].finish_time, processes[i].turnaround_time, processes[i].waiting_time);
    }
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average waiting time: %.2f\n", avg_waiting_time);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has specified a text file
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    // Open the text file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read the number of processes from the text file
    int num_processes;
    fscanf(input_file, "%d", &num_processes);

    // Allocate memory for the processes
    process *processes = (process *)malloc(num_processes * sizeof(process));

    // Read the process information from the text file
    for (int i = 0; i < num_processes; i++) {
        fscanf(input_file, "%d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time);
    }

    // Close the text file
    fclose(input_file);

    // Simulate the execution of the processes using the FCFS scheduling algorithm
    fcfs(processes, num_processes);

    // Print the results of the FCFS simulation
    printf("FCFS Scheduling Algorithm:\n");
    print_results(processes, num_processes);

    // Simulate the execution of the processes using the SJF scheduling algorithm
    sjf(processes, num_processes);

    // Print the results of the SJF simulation
    printf("SJF Scheduling Algorithm:\n");
    print_results(processes, num_processes);

    // Simulate the execution of the processes using the RR scheduling algorithm
    rr(processes, num_processes, 2);

    // Print the results of the RR simulation
    printf("RR Scheduling Algorithm:\n");
    print_results(processes, num_processes);

    // Free the memory allocated for the processes
    free(processes);

    return 0;
}