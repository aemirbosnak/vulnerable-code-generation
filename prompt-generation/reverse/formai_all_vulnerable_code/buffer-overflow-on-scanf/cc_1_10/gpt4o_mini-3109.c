//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PROCESS 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_burst[MAX_PROCESS];
    for (int i = 0; i < n; i++) {
        remaining_burst[i] = processes[i].burst_time;
    }

    int time = 0;
    bool done;
    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (remaining_burst[i] > 0) {
                done = false;
                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    processes[i].waiting_time = time - processes[i].burst_time - processes[i].arrival_time;
                    remaining_burst[i] = 0;
                }
            }
        }
    } while (!done);
}

void calculateTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, 
               processes[i].burst_time, 
               processes[i].arrival_time, 
               processes[i].waiting_time, 
               processes[i].turnaround_time);
    }
}

void sortProcessesByArrival(Process processes[], int n) {
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

int main() {
    Process processes[MAX_PROCESS];
    int n, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESS);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESS) {
        fprintf(stderr, "Invalid number of processes.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        printf("Enter Arrival Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].arrival_time);
        processes[i].waiting_time = 0; 
        processes[i].turnaround_time = 0;
    }

    printf("Enter time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    // Sort processes by arrival time
    sortProcessesByArrival(processes, n);

    // Calculate waiting time and turnaround time
    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);

    // Print the processes
    printProcesses(processes, n);

    return EXIT_SUCCESS;
}