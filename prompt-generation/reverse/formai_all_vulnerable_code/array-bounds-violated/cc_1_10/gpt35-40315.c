//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10 // Maximum number of processes
#define MAX_STRING_LENGTH 20 // Maximum length of process names

// Process structure
struct Process {
    char name[MAX_STRING_LENGTH];
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to calculate waiting time and turnaround time
void calculate_times(int n, struct Process processes[]) {
    int completion_time[MAX_PROCESSES];
    int total_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    // Calculate completion time for each process
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            completion_time[i] = processes[i].burst_time;
        } else {
            completion_time[i] = completion_time[i-1] + processes[i].burst_time;
        }

        processes[i].turnaround_time = completion_time[i] - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }

    // Calculate total waiting time and turnaround time
    for(int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_time += completion_time[i];
    }

    // Print results
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
    printf("CPU Utilization: %.2f%%\n", (float)total_time / completion_time[n-1] * 100);
}

// First Come, First Serve (FCFS) Scheduling Algorithm
void fcfs_scheduling(int n, struct Process processes[]) {
    calculate_times(n, processes);
}

// Shortest Job First (SJF) Scheduling Algorithm
void sjf_scheduling(int n, struct Process processes[]) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(processes[i].burst_time > processes[j].burst_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    calculate_times(n, processes);
}

// Round Robin (RR) Scheduling Algorithm
void rr_scheduling(int n, struct Process processes[], int quantum) {
    int time = 0;
    int completion_time[MAX_PROCESSES] = {0};
    int remaining_burst_time[MAX_PROCESSES];
    int total_waiting_time = 0;
    int total_turnaround_time = 0;

    for(int i = 0; i < n; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
    }

    while(1) {
        int done = 1;

        for(int i = 0; i < n; i++) {
            if(remaining_burst_time[i] > 0) {
                done = 0;

                if(remaining_burst_time[i] > quantum) {
                    time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    time += remaining_burst_time[i];
                    processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].turnaround_time = time - processes[i].arrival_time;
                    remaining_burst_time[i] = 0;
                }
            }
        }

        if(done == 1) break;
    }

    calculate_times(n, processes);
}

int main() {
    int n, algorithm, quantum;
    struct Process processes[MAX_PROCESSES];

    // Take input for number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Take input for each process
    for(int i = 0; i < n; i++) {
        printf("Enter name of process %d: ", i+1);
        scanf("%s", processes[i].name);

        printf("Enter arrival time of process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
    }

    // Take input for scheduling algorithm
    printf("Select a scheduling algorithm:\n");
    printf("1. First Come, First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF)\n");
    printf("3. Round Robin (RR)\n");
    printf("Enter choice: ");
    scanf("%d", &algorithm);

    switch(algorithm) {
        case 1:
            fcfs_scheduling(n, processes);
            break;
        case 2:
            sjf_scheduling(n, processes);
            break;
        case 3:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            rr_scheduling(n, processes, quantum);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}