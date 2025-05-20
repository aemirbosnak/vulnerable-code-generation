//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

// Romeo and Juliet CPU Scheduling Algorithms

// Process structure
typedef struct Process {
    int pid;             // Process ID
    int arrival_time;    // Arrival time
    int burst_time;      // Burst time
    int remaining_time;  // Remaining time
    int waiting_time;    // Waiting time
    int turnaround_time; // Turnaround time
} Process;

// Array of processes
Process processes[10];

// Number of processes
int num_processes;

// Function to sort processes by arrival time
void sort_processes_by_arrival_time() {
    for (int i = 0; i < num_processes; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to sort processes by remaining time
void sort_processes_by_remaining_time() {
    for (int i = 0; i < num_processes; i++) {
        for (int j = i + 1; j < num_processes; j++) {
            if (processes[i].remaining_time > processes[j].remaining_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculate_waiting_and_turnaround_time() {
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    int current_time = 0;

    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time += processes[i].burst_time;

        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }

        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time += processes[i].burst_time;
    }
}

// Function to print the results
void print_results() {
    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

// Main function
int main() {
    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Get the arrival time and burst time for each process
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    // Sort the processes by arrival time
    sort_processes_by_arrival_time();

    // Calculate waiting time and turnaround time
    calculate_waiting_and_turnaround_time();

    // Print the results
    print_results();

    return 0;
}