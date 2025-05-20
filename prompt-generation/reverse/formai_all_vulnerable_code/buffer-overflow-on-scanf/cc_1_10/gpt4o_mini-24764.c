//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;              // Process ID
    int burst_time;     // Time required by the process
    int remaining_time; // Time left for the process to finish
    int wait_time;      // Time process has waited in the ready queue
} Process;

void calculate_waiting_time(Process processes[], int n, int quantum) {
    int remaining_processes = n;
    int time = 0;

    while (remaining_processes > 0) {
        bool process_done_in_this_cycle = false;
        
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum; // Advance time by quantum
                    processes[i].remaining_time -= quantum;
                } else {
                    time += processes[i].remaining_time; // Advance time by remaining time
                    processes[i].wait_time = time - processes[i].burst_time; // Calculate wait time
                    processes[i].remaining_time = 0;
                    remaining_processes--;
                    process_done_in_this_cycle = true;
                }
            }
        }

        // If no process was done in this cycle, increment time to avoid infinite loop
        if (!process_done_in_this_cycle) {
            time++;
        }
    }
}

void print_processes(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].wait_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES) {
        printf("Number of processes exceeds the maximum limit of %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process IDs start from 1
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].wait_time = 0; // Initialize waiting time to 0
    }

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    calculate_waiting_time(processes, n, quantum);
    print_processes(processes, n);

    return 0;
}