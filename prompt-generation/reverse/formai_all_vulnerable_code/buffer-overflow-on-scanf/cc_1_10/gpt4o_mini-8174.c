//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid;            // Process ID
    int burst_time;     // Burst time of the process
    int remaining_time; // Remaining time for the process
    int arrival_time;   // Arrival time of the process
    int waiting_time;   // Waiting time of the process
    int turnaround_time; // Turnaround time of the process
};

// Function declarations
void calculateWaitingTime(struct Process proc[], int n, int quantum);
void calculateTurnaroundTime(struct Process proc[], int n);
void findavgTime(struct Process proc[], int n, int quantum);

int main() {
    int n, quantum;

    printf("********** Shocked CPU Scheduling Simulation **********\n");
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Surprise! Enter burst time and arrival time for Process %d:\n", i + 1);
        proc[i].pid = i + 1;
        proc[i].remaining_time = 0;
        scanf("%d%d", &proc[i].burst_time, &proc[i].arrival_time);
        proc[i].remaining_time = proc[i].burst_time;
        proc[i].waiting_time = 0;
        proc[i].turnaround_time = 0;
    }
    
    printf("Whaaat!? Enter time quantum: ");
    scanf("%d", &quantum);

    findavgTime(proc, n, quantum);

    return 0;
}

void findavgTime(struct Process proc[], int n, int quantum) {
    calculateWaitingTime(proc, n, quantum);
    calculateTurnaroundTime(proc, n);
    
    printf("\n********** Results of Scheduling **********\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].pid, 
               proc[i].burst_time, 
               proc[i].arrival_time,
               proc[i].waiting_time,
               proc[i].turnaround_time);
    }
}

void calculateWaitingTime(struct Process proc[], int n, int quantum) {
    int waiting_time[n];
    for (int i = 0; i < n; i++) {
        waiting_time[i] = 0;
    }
    
    // Start the scheduling with some waiting times
    int t = 0; // Current time
    int finished = 0;

    while (finished < n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= t && proc[i].remaining_time > 0) {
                if (proc[i].remaining_time > quantum) {
                    t += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    t += proc[i].remaining_time;
                    waiting_time[i] += (t - proc[i].burst_time - proc[i].arrival_time);
                    proc[i].remaining_time = 0;
                    finished++;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        proc[i].waiting_time = waiting_time[i];
    }
}

void calculateTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}