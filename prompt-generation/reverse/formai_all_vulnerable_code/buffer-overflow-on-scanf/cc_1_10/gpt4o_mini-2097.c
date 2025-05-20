//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;           // Process ID
    int arrival_time; // Arrival time
    int burst_time;   // Burst time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
} Process;

void calculate_waiting_time(Process *processes, int n, int quantum) {
    int remaining_burst[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].burst_time;
    }
    
    int time = 0;
    bool done;
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = false; // There is a pending process
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_burst[i] = 0;
                }
            }
        }
    } while (!done);
}

void calculate_turnaround_time(Process *processes, int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void display_process_info(Process *processes, int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("--------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

void round_robin_scheduling(Process *processes, int n, int quantum) {
    calculate_waiting_time(processes, n, quantum);
    calculate_turnaround_time(processes, n);
    display_process_info(processes, n);
}

int main() {
    printf("Welcome to the CPU Scheduling Simulator!\n");
    int num_processes, quantum;

    printf("Enter the number of processes (1 to %d): ", MAX_PROCESSES);
    scanf("%d", &num_processes);
    if (num_processes < 1 || num_processes > MAX_PROCESSES) {
        printf("Invalid number of processes. Please run the program again.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        processes[i].id = i + 1; // Assign Process ID
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    printf("Enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    round_robin_scheduling(processes, num_processes, quantum);

    printf("\nSimulation complete! Thank you for using the CPU Scheduling Simulator.\n");
    return 0;
}