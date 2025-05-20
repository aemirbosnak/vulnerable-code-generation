//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

// Structure for the Process Control Block (PCB)
struct PCB {
    int pid; // Process ID
    int arrival_time; // Arrival time of the process
    int burst_time; // Burst time required by the process
    int waiting_time; // Time the process waits for CPU
    int turnaround_time; // Time taken by the process to complete
    int remaining_time; // Remaining time for completion of the process
    int priority; // Priority value of the process
    bool completed; // Flag to mark process completion
};

// Function to calculate the waiting time and turnaround time for each process
void calculate_times(struct PCB processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    for(int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    float avg_waiting_time = (float) total_waiting_time / n;
    float avg_turnaround_time = (float) total_turnaround_time / n;
    printf("\n\nAverage Waiting Time: %f\n", avg_waiting_time);
    printf("Average Turnaround Time: %f\n", avg_turnaround_time);
}

// Function to perform priority scheduling algorithm
void priority_scheduling(struct PCB processes[], int n) {
    // Sort processes in ascending order of arrival time
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(processes[j].arrival_time > processes[j+1].arrival_time) {
                struct PCB temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    int current_time = 0;
    while(true) {
        bool all_processes_completed = true;
        // Select process with highest priority
        int highest_priority_index = -1, highest_priority = 0;
        for(int i = 0; i < n; i++) {
            if(!processes[i].completed && processes[i].arrival_time <= current_time && processes[i].priority > highest_priority) {
                highest_priority = processes[i].priority;
                highest_priority_index = i;
            }
            if(!processes[i].completed)
                all_processes_completed = false;
        }
        if(all_processes_completed)
            break;

        // Execute selected process
        processes[highest_priority_index].waiting_time = current_time - processes[highest_priority_index].arrival_time;
        current_time += processes[highest_priority_index].burst_time;
        processes[highest_priority_index].turnaround_time = current_time - processes[highest_priority_index].arrival_time;
        processes[highest_priority_index].completed = true;
    }
}

int main() {
    struct PCB processes[MAX_PROCESSES];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority value for process %d: ", i+1);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
        processes[i].pid = i+1;
        processes[i].completed = false;
    }
    priority_scheduling(processes, n);
    calculate_times(processes, n);
    return 0;
}