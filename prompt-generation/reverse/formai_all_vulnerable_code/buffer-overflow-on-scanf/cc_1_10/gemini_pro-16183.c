//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the process structure
typedef struct process {
    int pid;             // Process ID
    int arrival_time;    // Arrival time
    int burst_time;      // Burst time
    int priority;        // Priority
    int remaining_time;  // Remaining time
    int waiting_time;   // Waiting time
    int turnaround_time; // Turnaround time
} process;

// Function to compare processes by arrival time
int compare_arrival_time(const void *a, const void *b) {
    const process *p1 = (const process *)a;
    const process *p2 = (const process *)b;

    return p1->arrival_time - p2->arrival_time;
}

// Function to compare processes by priority
int compare_priority(const void *a, const void *b) {
    const process *p1 = (const process *)a;
    const process *p2 = (const process *)b;

    return p1->priority - p2->priority;
}

// Function to find the waiting time for each process
void calculate_waiting_time(process processes[], int n) {
    int i, j;

    // Initialize the waiting time for each process to 0
    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
    }

    // Calculate the waiting time for each process
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            processes[i].waiting_time += processes[j].burst_time;
        }
    }
}

// Function to find the turnaround time for each process
void calculate_turnaround_time(process processes[], int n) {
    int i;

    // Calculate the turnaround time for each process
    for (i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

// Function to print the scheduling results
void print_results(process processes[], int n) {
    int i;

    printf("Scheduling Results:\n");
    printf("---------------------\n");
    printf("PID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",
               processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    process processes[100];

    // Get the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get the details of each process
    for (int i = 0; i < n; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("PID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    // Sort the processes by arrival time
    qsort(processes, n, sizeof(process), compare_arrival_time);

    // Calculate the waiting time and turnaround time for each process
    calculate_waiting_time(processes, n);
    calculate_turnaround_time(processes, n);

    // Print the scheduling results
    print_results(processes, n);

    return 0;
}