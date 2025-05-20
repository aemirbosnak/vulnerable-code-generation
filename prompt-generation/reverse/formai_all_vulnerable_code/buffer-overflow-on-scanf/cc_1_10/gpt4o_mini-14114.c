//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;             // Process ID
    int burst_time;    // Total burst time required
    int waiting_time;  // Waiting time
    int turnaround_time; // Turnaround time
} Process;

void findAverageTime(Process processes[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        processes[i].waiting_time = 0;  // Initialize waiting time
    }

    int time = 0; // Current time
    while (1) {
        int all_done = 1;  // Flag to check if all processes are completed
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                all_done = 0; // At least one process is pending
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time;
                    remaining_time[i] = 0; // Process completed
                }
            }
        }
        if (all_done) {
            break; // Exit loop if all processes are done
        }
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, quantum;

    printf("Welcome to the Round Robin CPU Scheduling Simulation!\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process*)malloc(n * sizeof(Process));

    // Input process burst times
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign Process ID
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    // Input time quantum
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Calculate waiting times and turnaround times
    findAverageTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    
    // Print the results
    printProcesses(processes, n);

    free(processes);  // Freeing allocated memory
    return 0;
}