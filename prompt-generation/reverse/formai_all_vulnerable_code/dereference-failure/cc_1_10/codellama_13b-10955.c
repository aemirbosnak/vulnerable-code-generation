//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: expert-level
// CPU Scheduling Algorithm
// Author: Expert

#include <stdio.h>
#include <stdlib.h>

// Process Structure
struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int completed;
    int turnaround_time;
    int waiting_time;
};

// Process Queue
struct process* queue[100];

// Function to find the next process to be executed
struct process* find_next_process(struct process* queue[], int size) {
    struct process* next_process = NULL;
    int min_priority = 100;
    for (int i = 0; i < size; i++) {
        if (queue[i]->completed == 0 && queue[i]->priority < min_priority) {
            min_priority = queue[i]->priority;
            next_process = queue[i];
        }
    }
    return next_process;
}

// Function to simulate the CPU
void simulate_cpu(struct process* queue[], int size, int time_slice) {
    int total_time = 0;
    while (size > 0) {
        struct process* next_process = find_next_process(queue, size);
        if (next_process == NULL) {
            break;
        }
        total_time += time_slice;
        if (next_process->burst_time <= time_slice) {
            next_process->completed = 1;
            size--;
            next_process->turnaround_time = total_time - next_process->arrival_time;
            next_process->waiting_time = next_process->turnaround_time - next_process->burst_time;
        } else {
            next_process->burst_time -= time_slice;
        }
    }
}

// Main function
int main() {
    // Initialize the process queue
    int size = 5;
    struct process* queue[size];
    for (int i = 0; i < size; i++) {
        queue[i] = (struct process*)malloc(sizeof(struct process));
        queue[i]->pid = i;
        queue[i]->arrival_time = i * 5;
        queue[i]->priority = i;
        queue[i]->burst_time = i * 2;
        queue[i]->completed = 0;
        queue[i]->turnaround_time = 0;
        queue[i]->waiting_time = 0;
    }

    // Simulate the CPU
    simulate_cpu(queue, size, 1);

    // Print the results
    for (int i = 0; i < size; i++) {
        printf("Process %d: Arrival Time = %d, Priority = %d, Burst Time = %d, Completed = %d, Turnaround Time = %d, Waiting Time = %d\n",
            queue[i]->pid, queue[i]->arrival_time, queue[i]->priority, queue[i]->burst_time, queue[i]->completed, queue[i]->turnaround_time, queue[i]->waiting_time);
    }

    return 0;
}