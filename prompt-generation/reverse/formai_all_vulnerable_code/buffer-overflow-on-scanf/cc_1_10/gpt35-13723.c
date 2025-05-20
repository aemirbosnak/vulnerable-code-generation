//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Custom struct to represent a process
struct process {
    int pid;    // Process ID
    int burst_time;  // Time required to complete execution
    int priority;   // Priority of the process (lower value indicates higher priority)
};


// Function to implement Priority Scheduling algorithm
void priority_scheduling(struct process* processes, int num_processes) {
    int total_time = 0; // Variable to keep track of total waiting time for all processes
    // Sort the processes in ascending order of priority
    for(int i=0; i<num_processes; i++) {
        for(int j=i+1; j<num_processes; j++) {
            if(processes[i].priority > processes[j].priority) {
                struct process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    printf("Running processes using Priority Scheduling algorithm...\n");
    // Run the processes in order of priority
    for(int i=0; i<num_processes; i++) {
        printf("Executing process %d with burst time %d and priority %d\n", processes[i].pid, processes[i].burst_time, processes[i].priority);
        total_time += processes[i].burst_time * (num_processes-i);
    }
    printf("Average waiting time: %f\n", (float)total_time/num_processes);
}


int main() {
    int num_processes;
    printf("How many processes do you want to schedule? ");
    scanf("%d", &num_processes);
    struct process* processes = (struct process*)malloc(num_processes * sizeof(struct process));
    printf("\nEnter details of each process...\n");
    for(int i=0; i<num_processes; i++) {
        processes[i].pid = i+1;
        printf("Burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        printf("Priority of process %d: ", i+1);
        scanf("%d", &processes[i].priority);
    }
    priority_scheduling(processes, num_processes);
    free(processes);
    return 0;
}