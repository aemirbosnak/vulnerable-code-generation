//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Process structure
typedef struct {
    int id;           // Process ID
    int burst_time;   // Burst time
    int arrival_time; // Arrival time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
} Process;

// Function to calculate waiting time for all processes
void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time; 
        processes[i].waiting_time = 0;
    }
    
    int time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;  // There is a pending process
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];  // Add remaining time
                    processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0; // Process finished
                }
            }
        }
        if (done) break; // All processes are done
    }
}

// Function to calculate turnaround time for all processes
void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

// Function to find the average waiting and turnaround times
void findAverageTimes(Process processes[], int n, int quantum) {
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
            processes[i].id, processes[i].burst_time, processes[i].arrival_time, 
            processes[i].waiting_time, processes[i].turnaround_time);
    }
    
    printf("\nAverage Waiting Time: %.2f", total_waiting_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n > MAX_PROCESSES) {
        printf("Number of processes exceeds the maximum limit.\n");
        return 1;
    }

    // Input processes details
    for(int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process ID starting from 1
        printf("Enter burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    printf("Enter time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    findAverageTimes(processes, n, quantum);

    return 0;
}