//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to compare two processes based on their arrival times
int compareArrivalTime(const void *a, const void *b) {
    return ((struct Process *)a)->arrivalTime - ((struct Process *)b)->arrivalTime;
}

// Function to calculate waiting time and turnaround time for each process
void calculateTimes(struct Process processes[], int n) {
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;
    processes[0].waitingTime = 0; // First process always has 0 waiting time

    // Calculate waiting time for each subsequent process
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i-1].waitingTime + processes[i-1].burstTime;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalWaitingTime += processes[i].waitingTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
    }

    printf("Average Waiting Time: %.2fms\n", (float)totalWaitingTime/n);
    printf("Average Turnaround Time: %.2fms\n", (float)totalTurnaroundTime/n);
}

// Function to print process details
void printProcessDetails(struct Process processes[], int n) {
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id,
               processes[i].burstTime,
               processes[i].arrivalTime,
               processes[i].waitingTime,
               processes[i].turnaroundTime);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    // Input burst time and arrival time for each process
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process IDs starting from 1
        printf("Enter Burst Time and Arrival Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burstTime, &processes[i].arrivalTime);
    }

    // Sort processes based on arrival time
    qsort(processes, n, sizeof(struct Process), compareArrivalTime);

    // Calculate waiting and turnaround times
    calculateTimes(processes, n);

    // Print process details
    printProcessDetails(processes, n);

    free(processes); // Free allocated memory
    return 0;
}