//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int process_id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to calculate the waiting and turnaround times
void calculateWaitAndTurnaroundTime(Process processes[], int n) {
    int total_waiting_time = 0;
    
    // First process has no waiting time
    processes[0].waiting_time = 0;

    // Calculate waiting time for each process
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_waiting_time += processes[i].waiting_time;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)(total_waiting_time + (processes[n-1].burst_time)) / n);
}

// Function to sort processes based on Burst Time (Shortest Job First)
void sortProcessesByBurstTime(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                // Swap processes
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to display the processes
void displayProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, 
                                            processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;

    // Input the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Dynamically allocate memory for processes
    Process* processes = (Process*)malloc(n * sizeof(Process));
    if (processes == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1; // Process IDs starting from 1
        printf("Enter Burst Time for Process %d: ", processes[i].process_id);
        scanf("%d", &processes[i].burst_time);
    }

    // Sort processes based on burst time
    sortProcessesByBurstTime(processes, n);

    // Calculate waiting and turnaround times
    calculateWaitAndTurnaroundTime(processes, n);

    // Display the processes
    displayProcesses(processes, n);

    // Free allocated memory
    free(processes);
    
    return 0;
}