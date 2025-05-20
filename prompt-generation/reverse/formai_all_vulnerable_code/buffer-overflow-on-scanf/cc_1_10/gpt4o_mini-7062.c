//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Structure to represent a process
struct Process {
    int id;               // Process ID
    int burst_time;      // Burst time
    int arrival_time;    // Arrival time
    int completion_time; // Completion time
    int turnaround_time; // Turnaround time
    int waiting_time;    // Waiting time
};

// Function to compare two processes based on arrival time (used for sorting)
int compare_arrival(const void *a, const void *b) {
    struct Process *p1 = (struct Process *)a;
    struct Process *p2 = (struct Process *)b;
    return p1->arrival_time - p2->arrival_time;
}

// Function to implement FCFS CPU Scheduling Algorithm
void fcfs(struct Process processes[], int n) {
    // Sort processes based on arrival time
    qsort(processes, n, sizeof(struct Process), compare_arrival);

    int current_time = 0;
    printf("\nFCFS Scheduling:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        // Update the current time if it is less than the arrival time of the next process
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        
        // Calculate the completion time
        processes[i].completion_time = current_time + processes[i].burst_time;
        // Calculate turnaround time and waiting time
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        // Move time forward
        current_time = processes[i].completion_time;
        
        // Display the process metrics
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].id, 
            processes[i].arrival_time, 
            processes[i].burst_time, 
            processes[i].completion_time, 
            processes[i].turnaround_time, 
            processes[i].waiting_time);
    }
}

// Function to implement SJF Scheduling Algorithm
void sjf(struct Process processes[], int n) {
    // Sort processes based on burst time first, then by arrival time
    qsort(processes, n, sizeof(struct Process), compare_arrival);
    
    int completed = 0, current_time = 0;
    int shortest_index = -1;

    printf("\nSJF Scheduling:\n");
    printf("Process ID\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    while (completed < n) {
        int min_burst = __INT_MAX__;
        shortest_index = -1;

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && 
                processes[i].completion_time <= 0 && 
                processes[i].burst_time < min_burst) {
                min_burst = processes[i].burst_time;
                shortest_index = i;
            }
        }

        if (shortest_index != -1) {
            current_time += processes[shortest_index].burst_time;
            processes[shortest_index].completion_time = current_time;
            processes[shortest_index].turnaround_time = processes[shortest_index].completion_time - processes[shortest_index].arrival_time;
            processes[shortest_index].waiting_time = processes[shortest_index].turnaround_time - processes[shortest_index].burst_time;

            completed++;
            // Display the completed process information
            printf("%d\t\t%d\t\t%d\t\t%d\n", 
                processes[shortest_index].id, 
                processes[shortest_index].completion_time, 
                processes[shortest_index].turnaround_time, 
                processes[shortest_index].waiting_time);
        } else {
            // No processes are ready to execute
            current_time++;
        }
    }
}

// Main function
int main() {
    struct Process processes[MAX_PROCESSES];
    int n;

    printf("Welcome to the Exciting World of CPU Scheduling!\n");
    printf("Enter the number of processes (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID starts from 1
        printf("Enter arrival time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].completion_time = -1; // Initial value for not completed
    }

    // Run FCFS scheduling
    fcfs(processes, n);
    
    // Reset completion time to allow SJF calculations
    for (int i = 0; i < n; i++) {
        processes[i].completion_time = -1;
    }

    // Run SJF scheduling
    sjf(processes, n);

    printf("\nThank you for experiencing CPU Scheduling with us!\n");
    return 0;
}