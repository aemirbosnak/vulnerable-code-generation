//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>

#define NUM_PROCS 5
#define TIME_QUANTUM 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_process(int process_id) {
    printf("Executing process %d\n", process_id);
    sleep(TIME_QUANTUM);
}

int main() {
    int i, j, current_process = 0, completed_processes = 0;
    struct process processes[NUM_PROCS];

    // Initialize processes
    for (i = 0; i < NUM_PROCS; i++) {
        processes[i].id = i + 1;
        processes[i].burst_time = rand() % 10 + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    // Print initial process list
    printf("Initial process list:\n");
    for (i = 0; i < NUM_PROCS; i++) {
        printf("Process %d: Burst time = %d\n", processes[i].id, processes[i].burst_time);
    }

    // Execute processes
    while (completed_processes < NUM_PROCS) {
        // Find next process to execute
        for (i = 0; i < NUM_PROCS; i++) {
            if (processes[i].burst_time > 0 && processes[i].waiting_time == 0) {
                current_process = i;
                break;
            }
        }

        // Execute current process
        execute_process(current_process);

        // Update process information
        processes[current_process - 1].burst_time--;
        processes[current_process - 1].waiting_time += TIME_QUANTUM;
        processes[current_process - 1].turnaround_time += TIME_QUANTUM;

        // Check if process is completed
        if (processes[current_process - 1].burst_time == 0) {
            completed_processes++;
        }

        // Print current process list
        printf("\nCurrent process list:\n");
        for (i = 0; i < NUM_PROCS; i++) {
            printf("Process %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
        }
    }

    return 0;
}