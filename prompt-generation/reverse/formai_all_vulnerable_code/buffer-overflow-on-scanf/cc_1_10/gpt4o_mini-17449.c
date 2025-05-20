//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;         // Process ID
    int burst;     // Burst Time
    int arrival;    // Arrival Time
    int waiting;    // Waiting Time
    int turnaround; // Turnaround Time
} Process;

// Function to sort processes based on arrival time
void sortProcesses(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival > processes[j + 1].arrival) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate waiting and turnaround times
void calculateTimes(Process processes[], int n) {
    processes[0].waiting = 0; // First process has no waiting time

    // Calculate waiting times
    for (int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst;
    }

    // Calculate turnaround times
    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
    }
}

// Function to print process details
void printProcessDetails(Process processes[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    printf("---------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, processes[i].arrival, processes[i].burst,
               processes[i].waiting, processes[i].turnaround);
    }
}

// Main function demonstrating the SJF CPU Scheduling Algorithm
int main() {
    Process processes[MAX_PROCESSES];
    int n;

    // Input number of processes
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    // Input each process's ID, arrival time, and burst time
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assign ID from 1 to n
        printf("Enter arrival and burst time for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].arrival, &processes[i].burst);
    }

    // Sort processes by arrival time
    sortProcesses(processes, n);

    // Calculate waiting and turnaround times
    calculateTimes(processes, n);

    // Print the process details
    printProcessDetails(processes, n);

    // Calculate and print average waiting and turnaround times
    float totalWaiting = 0, totalTurnaround = 0;
    for (int i = 0; i < n; i++) {
        totalWaiting += processes[i].waiting;
        totalTurnaround += processes[i].turnaround;
    }
    printf("\nAverage Waiting Time: %.2f", totalWaiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaround / n);

    return 0;
}