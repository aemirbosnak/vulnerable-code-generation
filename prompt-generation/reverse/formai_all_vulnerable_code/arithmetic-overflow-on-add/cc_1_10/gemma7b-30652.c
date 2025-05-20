//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_TIME 100

struct process {
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;
};

void schedule(struct process processes[]) {
    int i, j, time = 0, completed = 0, quantum = 5;

    // Calculate the completion time and waiting time for each process
    for (i = 0; i < MAX_PROCESS; i++) {
        processes[i].completion_time = processes[i].arrival_time + processes[i].burst_time;
        processes[i].waiting_time = processes[i].arrival_time - time;
    }

    // Create a round robin queue
    int queue[MAX_PROCESS];
    for (i = 0; i < MAX_PROCESS; i++) {
        queue[i] = -1;
    }

    // Add processes to the queue
    for (i = 0; i < MAX_PROCESS; i++) {
        if (processes[i].arrival_time <= time) {
            queue[i] = processes[i].arrival_time;
        }
    }

    // Start the scheduling loop
    while (!completed) {
        // Find the process with the smallest remaining burst time
        int min_burst_time = MAX_TIME;
        int min_burst_time_process = -1;
        for (i = 0; i < MAX_PROCESS; i++) {
            if (queue[i] != -1 && processes[i].burst_time < min_burst_time) {
                min_burst_time = processes[i].burst_time;
                min_burst_time_process = i;
            }
        }

        // If the process is completed, update its completion time and waiting time
        if (min_burst_time_process != -1) {
            processes[min_burst_time_process].completion_time = time + quantum;
            processes[min_burst_time_process].waiting_time = processes[min_burst_time_process].completion_time - processes[min_burst_time_process].arrival_time;
            completed++;
        }

        // Increment time
        time += quantum;
    }
}

int main() {
    struct process processes[MAX_PROCESS];

    // Create the processes
    processes[0].arrival_time = 0;
    processes[0].burst_time = 10;
    processes[1].arrival_time = 5;
    processes[1].burst_time = 5;
    processes[2].arrival_time = 12;
    processes[2].burst_time = 8;

    schedule(processes);

    // Print the results
    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process %d: Arrival Time %d, Completion Time %d, Waiting Time %d, Turnaround Time %d\n", i, processes[i].arrival_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turn_around_time);
    }

    return 0;
}