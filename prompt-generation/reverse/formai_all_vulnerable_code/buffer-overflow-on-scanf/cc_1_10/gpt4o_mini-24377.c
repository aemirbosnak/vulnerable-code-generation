//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;            // Process ID
    int burst_time;   // Burst time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
} Process;

// Function Prototypes
void calculateWaitingTime(Process processes[], int n, int quantum);
void calculateTurnaroundTime(Process processes[], int n);
void displayProcessStats(Process processes[], int n);

// Main function
int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }
    
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);
    
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    
    displayProcessStats(processes, n);
    
    return 0;
}

// Calculate waiting time using Round Robin scheduling
void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;
    
    int t = 0; // Initialize time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There is at least one process remaining
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) break; // All processes are done
    }
}

// Calculate turnaround time
void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

// Display all processes' statistics
void displayProcessStats(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].burst_time, 
               processes[i].waiting_time, 
               processes[i].turnaround_time);
    }
    
    float total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }
    
    printf("\nAverage Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}