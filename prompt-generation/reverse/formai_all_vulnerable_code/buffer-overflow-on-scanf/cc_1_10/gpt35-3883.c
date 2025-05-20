//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
/* This program implements a unique CPU scheduling algorithm that ensures fair distribution of CPU time among processes. The algorithm combines the concepts of Round Robin and Priority Scheduling, where the priority of a process is based on the number of time it has been scheduled to run. */

#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10 // Maximum number of processes that can be handled by the CPU
#define TIME_QUANTUM 2 // Time quantum for the Round Robin scheduling algorithm

typedef struct process {
    int id; // ID of the process
    int arrival_time; // Time at which the process arrives
    int burst_time; // Time required by the process to complete execution
    int priority; // Priority of the process
    int time_left; // Time left for the process to complete execution
    int time_scheduled; // Time at which the process was last scheduled to run
} Process;

/* Function to initialize a process */
void init_process(Process *p, int id, int arrival_time, int burst_time) {
    p->id = id;
    p->arrival_time = arrival_time;
    p->burst_time = burst_time;
    p->priority = 0;
    p->time_left = burst_time;
    p->time_scheduled = arrival_time;
}

/* Function to execute a process for a given time */
void execute_process(Process *p, int time) {
    p->time_left -= time;
    p->time_scheduled += time;
}

/* Function to find the process with the highest priority */
int get_highest_priority_process(Process *processes, int n) {
    int i, max_priority = 0, max_priority_idx = -1;
    for (i = 0; i < n; i++) {
        if (processes[i].time_left > 0 && processes[i].priority > max_priority) {
            max_priority = processes[i].priority;
            max_priority_idx = i;
        }
    }
    return max_priority_idx;
}

int main() {
    Process processes[MAX_PROCESSES]; // Array to hold the processes
    int n, i, j, total_time = 0;

    // Read input from user
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the arrival time and burst time of each process:\n");
    for (i = 0; i < n; i++) {
        int arrival_time, burst_time;
        printf("Process %d: ", i + 1);
        scanf("%d %d", &arrival_time, &burst_time);
        init_process(&processes[i], i + 1, arrival_time, burst_time);
        total_time += burst_time;
    }

    // Execute processes
    for (i = 0; i < total_time;) {
        // Increment priorities of all processes that have not been scheduled to run for a while
        for (j = 0; j < n; j++) {
            if (processes[j].priority >= 0 && i - processes[j].time_scheduled > 2 * TIME_QUANTUM) {
                processes[j].priority++;
            }
        }

        // Find the process with the highest priority
        int idx = get_highest_priority_process(processes, n);

        if (idx == -1) {
            printf("Idle at time %d\n", i);
            i++;
            continue;
        }

        // Execute the process for TIME_QUANTUM time
        int time_executed = processes[idx].time_left < TIME_QUANTUM ? processes[idx].time_left : TIME_QUANTUM;
        execute_process(&processes[idx], time_executed);
        i += time_executed;

        // Reset priority of the process
        processes[idx].priority = 0;

        // Display the status of the process
        printf("Process %d ran for %d units from time %d\n", processes[idx].id, time_executed, i - time_executed);
    }

    return 0;
}