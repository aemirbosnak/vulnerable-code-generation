//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Process structure
struct Process {
    int pid;         // Process ID
    int arrival_time; // Arrival time
    int burst_time;  // Burst time
    int priority;    // Priority
};

// Function to compare processes based on arrival time
int compare_arrival_time(const void *a, const void *b) {
    const struct Process *p1 = (const struct Process *)a;
    const struct Process *p2 = (const struct Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Function to compare processes based on burst time
int compare_burst_time(const void *a, const void *b) {
    const struct Process *p1 = (const struct Process *)a;
    const struct Process *p2 = (const struct Process *)b;
    return p1->burst_time - p2->burst_time;
}

// Function to compare processes based on priority
int compare_priority(const void *a, const void *b) {
    const struct Process *p1 = (const struct Process *)a;
    const struct Process *p2 = (const struct Process *)b;
    return p1->priority - p2->priority;
}

// Function to find the waiting time for each process
void calculate_waiting_time(struct Process processes[], int n) {
    int waiting_time[n];
    waiting_time[0] = 0; // Waiting time for the first process is always 0

    // Calculate waiting time for remaining processes
    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + processes[i - 1].burst_time;
    }

    // Print the waiting time for each process
    printf("\nWaiting time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: %d\n", processes[i].pid, waiting_time[i]);
    }
}

// Function to find the turnaround time for each process
void calculate_turnaround_time(struct Process processes[], int n) {
    int turnaround_time[n];

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = processes[i].burst_time + turnaround_time[i - 1];
    }

    // Print the turnaround time for each process
    printf("\nTurnaround time:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: %d\n", processes[i].pid, turnaround_time[i]);
    }
}

// Function to find the average waiting time
float calculate_average_waiting_time(struct Process processes[], int n) {
    int total_waiting_time = 0;

    // Calculate total waiting time
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].burst_time;
    }

    // Return the average waiting time
    return (float)total_waiting_time / n;
}

// Function to find the average turnaround time
float calculate_average_turnaround_time(struct Process processes[], int n) {
    int total_turnaround_time = 0;

    // Calculate total turnaround time
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].burst_time;
    }

    // Return the average turnaround time
    return (float)total_turnaround_time / n;
}

// Main function
int main() {
    // Create an array of processes
    struct Process processes[] = {
        {1, 0, 5, 2},
        {2, 2, 3, 1},
        {3, 4, 6, 3},
        {4, 6, 4, 4},
        {5, 8, 2, 2},
    };

    // Get the number of processes
    int n = sizeof(processes) / sizeof(processes[0]);

    // Sort the processes based on arrival time
    qsort(processes, n, sizeof(struct Process), compare_arrival_time);

    // Print the sorted processes
    printf("\nSorted processes:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: Arrival time: %d, Burst time: %d, Priority: %d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority);
    }

    // Calculate the waiting time for each process
    calculate_waiting_time(processes, n);

    // Calculate the turnaround time for each process
    calculate_turnaround_time(processes, n);

    // Calculate the average waiting time
    float average_waiting_time = calculate_average_waiting_time(processes, n);

    // Calculate the average turnaround time
    float average_turnaround_time = calculate_average_turnaround_time(processes, n);

    // Print the average waiting time and average turnaround time
    printf("\nAverage waiting time: %.2f\n", average_waiting_time);
    printf("Average turnaround time: %.2f\n", average_turnaround_time);

    return 0;
}