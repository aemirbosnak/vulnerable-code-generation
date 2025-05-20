//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void calculateWaitingTime(struct Process proc[], int n, int quantum, int waiting_time[]) {
    int t = 0; // Current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                done = 0; // There are still processes to schedule
                if (proc[i].remaining_time > quantum) {
                    t += quantum; // Process runs for quantum
                    proc[i].remaining_time -= quantum; // Decrease remaining time
                } else {
                    t = t + proc[i].remaining_time; // Process finishes
                    waiting_time[i] = t - proc[i].burst_time; // Calculate waiting time
                    proc[i].remaining_time = 0; // Mark as finished
                }
            }
        }
        if (done) {
            break; // All processes are done
        }
    }
}

void calculateTurnaroundTime(struct Process proc[], int n, int waiting_time[], int turnaround_time[]) {
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = proc[i].burst_time + waiting_time[i]; // Turnaround time formula
    }
}

void printSchedule(struct Process proc[], int n, int waiting_time[], int turnaround_time[]) {
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
}

int main() {
    int n; // Number of processes
    int quantum; // Time quantum for round robin
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    struct Process proc[n];
    
    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assign process id
        printf("Enter Burst Time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        proc[i].remaining_time = proc[i].burst_time; // Initialize remaining time
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
    int waiting_time[n], turnaround_time[n];
    
    calculateWaitingTime(proc, n, quantum, waiting_time);
    calculateTurnaroundTime(proc, n, waiting_time, turnaround_time);
    printSchedule(proc, n, waiting_time, turnaround_time);
    
    return 0;
}