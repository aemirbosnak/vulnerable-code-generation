//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
};

// Function to compare two processes based on their arrival time
int compareArrival(const void *a, const void *b) {
    return ((struct Process *)a)->arrival_time - ((struct Process *)b)->arrival_time;
}

// Function to calculate waiting time and turnaround time
void calculateTimes(struct Process processes[], int n) {
    processes[0].waiting_time = 0; // First process always has 0 waiting time
    processes[0].turnaround_time = processes[0].burst_time; // Turnaround time is equal to burst time

    // Calculate waiting time and turnaround time for all processes
    for(int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].turnaround_time + processes[i - 1].arrival_time - processes[i].arrival_time;
        if(processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0; // Waiting time cannot be negative
        }
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to print process details
void printProcessDetails(struct Process processes[], int n) {
    printf("\nProcess ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    printf("---------------------------------------------------------\n");
    for(int i = 0; i < n; i++) {
        printf("    %d      |      %d      |     %d     |      %d      |        %d\n",
               processes[i].id, processes[i].arrival_time, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    // Input details for each process
    for(int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process IDs starting from 1
        printf("Enter arrival time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on arrival time
    qsort(processes, n, sizeof(struct Process), compareArrival);

    // Calculate waiting and turnaround times
    calculateTimes(processes, n);

    // Print process details in table format
    printProcessDetails(processes, n);

    // Free allocated memory
    free(processes);
    return 0;
}