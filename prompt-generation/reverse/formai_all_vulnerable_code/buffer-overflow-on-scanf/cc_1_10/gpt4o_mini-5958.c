//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;             // Process ID
    int burst_time;     // Burst time of the process
    int arrival_time;   // Arrival time of the process
    int waiting_time;   // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }
    
    int complete = 0, t = 0;
    while (complete < n) {
        int done = 0;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 1;
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].turnaround_time = t - processes[i].arrival_time;
                    remaining_time[i] = 0;
                    complete++;
                }
            }
        }
        
        if (!done) {
            t++;
        }
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

void displayProcessSchedule(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].burst_time,
               processes[i].arrival_time, processes[i].waiting_time,
               processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;
    
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    if (n > MAX_PROCESSES) {
        printf("Number of processes exceeds maximum limit.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time and arrival time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }
    
    printf("Enter time quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);
    
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    
    displayProcessSchedule(processes, n);

    return 0;
}