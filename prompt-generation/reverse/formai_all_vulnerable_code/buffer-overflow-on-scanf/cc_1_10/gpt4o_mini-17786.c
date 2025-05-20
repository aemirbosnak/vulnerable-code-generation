//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;          // Process ID
    int arrival;     // Arrival Time
    int burst;       // Burst Time
    int waiting;     // Waiting Time
    int turnaround;  // Turnaround Time
} Process;

// Function to compare two processes based on their arrival time (used for sorting)
int compareArrival(const void *a, const void *b) {
    return ((Process *)a)->arrival - ((Process *)b)->arrival;
}

// Function to calculate the waiting and turnaround times
void calculateTimes(Process processes[], int n) {
    int total_wait = 0, total_turnaround = 0;
    processes[0].waiting = 0; // First process has 0 waiting time

    // Compute wait time and turn around time
    for (int i = 1; i < n; i++) {
        processes[i].waiting = processes[i - 1].waiting + processes[i - 1].burst;
        total_wait += processes[i].waiting;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround = processes[i].burst + processes[i].waiting;
        total_turnaround += processes[i].turnaround;
    }

    // Display statistics
    printf("\nAverage Waiting Time: %.2f\n", (float)total_wait / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

// Function to print processes
void printProcesses(Process processes[], int n) {
    printf("\nProcess ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrival, processes[i].burst,
               processes[i].waiting, processes[i].turnaround);
    }
}

// Main function to schedule CPU processes
int main() {
    int n;

    printf("Welcome to the Artistic CPU Scheduler!\n");
    printf("How many processes do you want to schedule? (Max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Exceeded maximum number of processes. Please decrease the count.\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst);
        processes[i].waiting = 0; // Default waiting time
        processes[i].turnaround = 0; // Default turnaround time
    }

    // Sort processes based on arrival time
    qsort(processes, n, sizeof(Process), compareArrival);

    // Calculate waiting and turnaround times
    calculateTimes(processes, n);

    // Print the results
    printProcesses(processes, n);

    printf("\nArtistic Scheduling Completed! Enjoy your mystical program!\n");
    return 0;
}