//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 100

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to calculate waiting and turnaround times for processes
void calculateTimes(Process processes[], int n) {
    int total_wt = 0, total_tat = 0;

    processes[0].waiting_time = 0; // First process has no waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        total_wt += processes[i].waiting_time;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        total_tat += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

// Function to implement First-Come First-Served (FCFS) Scheduling
void FCFS(Process processes[], int n) {
    printf("\nFirst-Come First-Served (FCFS) Scheduling:\n");
    calculateTimes(processes, n);
    
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

// Function to implement Shortest Job First (SJF) Scheduling
void SJF(Process processes[], int n) {
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burst_time > processes[j + 1].burst_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    
    printf("\nShortest Job First (SJF) Scheduling:\n");
    calculateTimes(processes, n);
    
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

// Function to compare processes based on arrival time for sorting
int compare(const void *a, const void *b) {
    return ((Process *)a)->arrival_time > ((Process *)b)->arrival_time;
}

// Main function
int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d:\n", i + 1);
        processes[i].id = i + 1;
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
    }

    // Sort processes by arrival time before scheduling
    qsort(processes, n, sizeof(Process), compare);

    FCFS(processes, n);
    SJF(processes, n);

    return 0;
}