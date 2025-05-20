//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 3

typedef struct {
    int pid;            // Process ID
    char name[20];     // Cyber entity name
    int burst_time;    // Total time required
    int remaining_time; // Time remaining
    int wait_time;     // Waiting time
    int turnaround_time; // Turnaround time
} Process;

// Function prototypes
void add_process(Process* processes, int* count);
void round_robin(Process* processes, int count);
void display_processes(Process* processes, int count);

int main() {
    Process processes[MAX_PROCESSES];
    int process_count = 0;
    char choice;

    printf("=== Cyberpunk CPU Scheduling Simulator ===\n");

    while (true) {
        add_process(processes, &process_count);
        printf("Add another process? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') break;
    }

    printf("\nInitial list of cyber entities:\n");
    display_processes(processes, process_count);

    printf("\nExecuting Round Robin Scheduling...\n");
    round_robin(processes, process_count);
    
    return 0;
}

void add_process(Process* processes, int* count) {
    if (*count >= MAX_PROCESSES) {
        printf("Maximum number of processes reached!\n");
        return;
    }

    Process new_process;
    new_process.pid = *count + 1; // Assign PID sequentially
    printf("Enter name for cyber entity (Process %d): ", new_process.pid);
    scanf("%s", new_process.name);
    printf("Enter burst time for %s: ", new_process.name);
    scanf("%d", &new_process.burst_time);

    new_process.remaining_time = new_process.burst_time;
    new_process.wait_time = 0;
    new_process.turnaround_time = 0;
    
    processes[*count] = new_process;
    (*count)++;
}

void round_robin(Process* processes, int count) {
    int total_wait_time = 0, total_turnaround_time = 0;
    int time = 0;
    bool processes_remaining = true;

    while (processes_remaining) {
        processes_remaining = false;
        for (int i = 0; i < count; i++) {
            if (processes[i].remaining_time > 0) {
                processes_remaining = true; // There are processes remaining
                if (processes[i].remaining_time > TIME_QUANTUM) {
                    time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].wait_time = time - processes[i].burst_time;
                    processes[i].turnaround_time = time;
                    total_wait_time += processes[i].wait_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    processes[i].remaining_time = 0;
                    printf("Cyber entity %s completed at time %d\n", processes[i].name, time);
                }
            }
        }
    }

    printf("\n=== Scheduling Summary ===\n");
    for (int i = 0; i < count; i++) {
        printf("Cyber entity %s (PID %d) - Wait Time: %d, Turnaround Time: %d\n", 
               processes[i].name, processes[i].pid, processes[i].wait_time, processes[i].turnaround_time);
    }

    printf("\nTotal Waiting Time: %d\n", total_wait_time);
    printf("Average Waiting Time: %.2f\n", (float)total_wait_time / count);
    printf("Total Turnaround Time: %d\n", total_turnaround_time);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / count);
}

void display_processes(Process* processes, int count) {
    for (int i = 0; i < count; i++) {
        printf("Cyber Entity %d: %s | Burst Time: %d\n", 
               processes[i].pid, processes[i].name, processes[i].burst_time);
    }
}