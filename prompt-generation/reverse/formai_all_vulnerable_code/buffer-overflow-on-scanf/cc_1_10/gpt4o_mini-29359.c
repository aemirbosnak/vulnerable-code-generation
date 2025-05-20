//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++)
        remaining_time[i] = processes[i].burst_time;

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t = t + remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time - processes[i].arrival_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++)
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
}

void printScheduling(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].process_id, 
                processes[i].burst_time, 
                processes[i].arrival_time,
                processes[i].waiting_time, 
                processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Please ensure it's between 1 and %d.\n", MAX_PROCESSES);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].process_id = i + 1;
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printScheduling(processes, n);

    return 0;
}