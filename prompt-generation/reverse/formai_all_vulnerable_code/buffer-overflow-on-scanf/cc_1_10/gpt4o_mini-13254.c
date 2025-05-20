//GPT-4o-mini DATASET v1.0 Category: Task Scheduler ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 2

typedef struct {
    int id;          // Process ID
    int burst_time;  // Burst time
    int remaining_time; // Remaining time
} Process;

void initialize_processes(Process processes[], int count) {
    for (int i = 0; i < count; i++) {
        processes[i].id = i + 1;  // Process IDs start from 1
        processes[i].burst_time = rand() % 10 + 1; // Random burst times between 1 and 10
        processes[i].remaining_time = processes[i].burst_time;
    }
}

void display_processes(Process processes[], int count) {
    printf("Process ID | Burst Time | Remaining Time\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("    %d      |     %d      |      %d\n",
               processes[i].id, processes[i].burst_time, processes[i].remaining_time);
    }
    printf("-------------------------------------------\n");
}

void round_robin_scheduling(Process processes[], int count) {
    int all_done = 0; // Flag to check if all processes are done

    // Continue running until all processes are completed
    while (!all_done) {
        all_done = 1; // Assume all are done initially

        for (int i = 0; i < count; i++) {
            if (processes[i].remaining_time > 0) {
                all_done = 0; // At least one process is still running
                if (processes[i].remaining_time > TIME_QUANTUM) {
                    printf("Process %d is running for %d units of time.\n", processes[i].id, TIME_QUANTUM);
                    sleep(TIME_QUANTUM); // Simulating running time
                    processes[i].remaining_time -= TIME_QUANTUM; // Reduce remaining time
                } else {
                    printf("Process %d is running for %d units of time and completed.\n", processes[i].id, processes[i].remaining_time);
                    sleep(processes[i].remaining_time); // Simulating remaining execution time
                    processes[i].remaining_time = 0; // Mark as completed
                }
            }
        }
    }
    printf("All processes have been completed!\n");
}

int main() {
    srand(time(NULL)); // Seed random number generator
    Process processes[MAX_PROCESSES];
    int process_count;

    printf("Enter number of processes (1 - %d): ", MAX_PROCESSES);
    scanf("%d", &process_count);

    while (process_count < 1 || process_count > MAX_PROCESSES) {
        printf("Please enter a valid number of processes (1 - %d): ", MAX_PROCESSES);
        scanf("%d", &process_count);
    }

    initialize_processes(processes, process_count);
    printf("\nInitial Process States:\n");
    display_processes(processes, process_count);

    round_robin_scheduling(processes, process_count);
    
    return 0;
}