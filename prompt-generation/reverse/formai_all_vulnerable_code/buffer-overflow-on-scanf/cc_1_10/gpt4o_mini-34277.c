//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

struct Process {
    int id;
    int burst_time;
    int arrival_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
};

// Function to find the waiting and turnaround times
void findWaitingAndTurnaroundTimes(struct Process proc[], int n, int quantum) {
    int time = 0;
    int completed = 0;
    int i;
    
    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (proc[i].remaining_time > quantum) {
                    time += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    time += proc[i].remaining_time;
                    proc[i].waiting_time = time - proc[i].burst_time - proc[i].arrival_time;
                    proc[i].turnaround_time = time - proc[i].arrival_time;
                    proc[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }
}

// Function to print the process details
void printProcesses(struct Process proc[], int n) {
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               proc[i].id, 
               proc[i].burst_time, 
               proc[i].arrival_time, 
               proc[i].waiting_time, 
               proc[i].turnaround_time);
    }
}

int main() {
    struct Process proc[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; // Assign process id
        printf("Enter burst time for P%d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        printf("Enter arrival time for P%d: ", proc[i].id);
        scanf("%d", &proc[i].arrival_time);
        proc[i].remaining_time = proc[i].burst_time; // Initialize remaining time
    }

    findWaitingAndTurnaroundTimes(proc, n, quantum);
    
    printProcesses(proc, n);
    
    return 0;
}