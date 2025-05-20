//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Process structure
typedef struct Process {
    int pid;            // Process ID
    int arrival_time;    // Arrival time
    int burst_time;     // Burst time
    int priority;       // Priority
    int remaining_time; // Remaining time
    int waiting_time;   // Waiting time
    int turnaround_time;// Turnaround time
} Process;

// Array of processes
Process processes[100];

// Number of processes
int num_processes;

// Function to compare processes by arrival time
int compare_arrival_time(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Function to compare processes by priority
int compare_priority(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->priority - p2->priority;
}

// Function to compare processes by shortest remaining time
int compare_shortest_remaining_time(const void *a, const void *b) {
    Process *p1 = (Process *)a;
    Process *p2 = (Process *)b;
    return p1->remaining_time - p2->remaining_time;
}

// Function to calculate waiting time
void calculate_waiting_time(Process *processes, int num_processes) {
    // Initialize waiting time of all processes to 0
    for (int i = 0; i < num_processes; i++) {
        processes[i].waiting_time = 0;
    }

    // Calculate waiting time for each process
    for (int i = 1; i < num_processes; i++) {
        processes[i].waiting_time = processes[i-1].waiting_time + processes[i-1].burst_time;
    }
}

// Function to calculate turnaround time
void calculate_turnaround_time(Process *processes, int num_processes) {
    // Calculate turnaround time for each process
    for (int i = 0; i < num_processes; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to print results
void print_results(Process *processes, int num_processes) {
    // Print header
    printf("%-10s %-10s %-10s %-10s %-10s %-10s\n", "PID", "Arrival Time", "Burst Time", "Priority", "Waiting Time", "Turnaround Time");

    // Print results for each process
    for (int i = 0; i < num_processes; i++) {
        printf("%-10d %-10d %-10d %-10d %-10d %-10d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

// Main function
int main() {
    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    // Get the details of each process
    for (int i = 0; i < num_processes; i++) {
        printf("Enter the details of process %d:\n", i+1);
        printf("PID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    // Sort processes by arrival time
    qsort(processes, num_processes, sizeof(Process), compare_arrival_time);

    // Calculate waiting time and turnaround time
    calculate_waiting_time(processes, num_processes);
    calculate_turnaround_time(processes, num_processes);

    // Print results
    print_results(processes, num_processes);

    return 0;
}