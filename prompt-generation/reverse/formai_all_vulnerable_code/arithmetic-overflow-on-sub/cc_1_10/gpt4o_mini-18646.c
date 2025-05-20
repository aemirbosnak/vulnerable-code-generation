//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;        // Process ID
    int arrival;   // Arrival time
    int burst;     // Burst time
    int priority;  // Priority level
    int completion; // Completion time
    int turnaround; // Turnaround time
    int waiting;   // Waiting time
} Process;

void calculateMetrics(Process proc[], int n) {
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt += proc[i].waiting;
        total_tat += proc[i].turnaround;
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt/n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat/n);
}

void displayProcesses(Process proc[], int n) {
    printf("\nProcess ID | Arrival | Burst | Waiting | Turnaround | Completion\n");
    for (int i = 0; i < n; i++) {
        printf("     %d     |   %d    |  %d   |   %d    |     %d      |     %d\n", 
                proc[i].id, proc[i].arrival, proc[i].burst, 
                proc[i].waiting, proc[i].turnaround, proc[i].completion);
    }
}

void priorityScheduling(Process proc[], int n) {
    int total_time = 0;
    // Sort processes by arrival time and then by priority
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if ((proc[j].arrival > proc[j+1].arrival) || 
               (proc[j].arrival == proc[j+1].arrival && proc[j].priority > proc[j+1].priority)) {
                Process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(total_time < proc[i].arrival) {
            total_time = proc[i].arrival; // wait for the process to arrive
        }
        proc[i].completion = total_time + proc[i].burst;
        proc[i].turnaround = proc[i].completion - proc[i].arrival;
        proc[i].waiting = proc[i].turnaround - proc[i].burst;
        
        total_time += proc[i].burst;
    }
}

int main() {
    Process proc[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].arrival);
        printf("Enter burst time for Process %d: ", proc[i].id);
        scanf("%d", &proc[i].burst);
        printf("Enter priority for Process %d (lower number has higher priority): ", proc[i].id);
        scanf("%d", &proc[i].priority);
    }

    priorityScheduling(proc, n);
    displayProcesses(proc, n);
    calculateMetrics(proc, n);

    return 0;
}