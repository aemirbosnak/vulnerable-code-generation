//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;                // Process ID
    int burst_time;       // Burst time
    int arrival_time;     // Arrival time
    int completion_time;  // Completion time
    int waiting_time;     // Waiting time
    int turnaround_time;  // Turnaround time
} Process;

void calculateWaitingTime(Process processes[], int n) {
    processes[0].waiting_time = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].completion_time - processes[i].arrival_time;
        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0; // If there is no waiting time
        }
    }
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void calculateCompletionTime(Process processes[], int n) {
    processes[0].completion_time = processes[0].arrival_time + processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        processes[i].completion_time = processes[i].arrival_time + processes[i].burst_time + processes[i - 1].completion_time;
    }
}

void sortProcesses(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void displayProcesses(Process processes[], int n) {
    printf("Process ID\tBurst Time\tArrival Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].burst_time, 
               processes[i].arrival_time, 
               processes[i].completion_time, 
               processes[i].waiting_time, 
               processes[i].turnaround_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // ID process from 1 to n
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
    }

    sortProcesses(processes, n);
    calculateCompletionTime(processes, n);
    calculateWaitingTime(processes, n);
    calculateTurnaroundTime(processes, n);
    displayProcesses(processes, n);

    return 0;
}