//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void calculateWaitingTime(Process processes[], int n, int quantum) {
    int remaining_time[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
        processes[i].waiting_time = 0; // Initialize waiting time
    }

    int completed = 0, time = 0;
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && processes[i].arrival_time <= time) {
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    time += remaining_time[i];
                    processes[i].waiting_time += (time - processes[i].burst_time - processes[i].arrival_time);
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }
    }
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

void welcome() {
    printf("Welcome to the CPU Scheduling Simulator!\n");
    printf("Let's dive into the Round Robin scheduling algorithm!\n");
}

void getProcessInput(Process processes[], int *n) {
    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", n);
    if (*n > MAX_PROCESSES) {
        printf("You can only enter up to %d processes. Exiting...\n", MAX_PROCESSES);
        exit(0);
    }

    for (int i = 0; i < *n; i++) {
        printf("Enter burst time and arrival time for Process %d: ", i + 1);
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;
    int quantum;

    welcome();
    getProcessInput(processes, &n);

    printf("Enter time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    calculateWaitingTime(processes, n, quantum);
    calculateTurnaroundTime(processes, n);
    printProcesses(processes, n);

    return 0;
}