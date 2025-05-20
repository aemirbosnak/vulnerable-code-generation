//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Process {
    int pid;  // Process ID
    int burst_time;  // Burst Time
    int arrival_time;  // Arrival Time
    int completion_time;  // Completion Time
    int turnaround_time;  // Turnaround Time
    int waiting_time;  // Waiting Time
} Process;

// Function to print the Gantt Chart
void printGanttChart(Process processes[], int n) {
    printf(" ");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst_time-1; j++) printf(" ");
        printf("P%d", processes[i].pid);
        for (int j = 0; j < processes[i].burst_time-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < processes[i].burst_time; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    printf("0");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < processes[i].burst_time; j++) printf("  ");
        if(processes[i].completion_time > 9) printf("\b");  // Backspace to remove 1 space
        printf("%d", processes[i].completion_time);
    }
    printf("\n");
}

// Function to sort the processes by their arrival time
bool sortByArrivalTime(Process p1, Process p2) {
    return (p1.arrival_time < p2.arrival_time);
}

// Function that implements the first-come, first-served (FCFS) scheduling algorithm
void fcfs(Process processes[], int n) {
    // Sort the processes by their arrival time
    qsort(processes, n, sizeof(Process), sortByArrivalTime);

    // Calculate the completion time of each process and the total waiting time and turnaround time
    int total_waiting_time = 0, total_turnaround_time = 0;
    for(int i = 0, curr_time = 0; i < n; i++) {
        curr_time = curr_time + processes[i].burst_time;
        processes[i].completion_time = curr_time;
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    // Calculate the average waiting time and average turnaround time
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\n");
    printf("*********************************************************\n");
    printf("First-Come, First-Served (FCFS) Scheduling Algorithm:\n");
    printf("*********************************************************\n");
    printf("PID  BT  AT  CT  WT  TAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%-3d %-3d %-3d %-3d %-3d %-3d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].completion_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("*********************************************************\n");
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("*********************************************************\n");
    printf("\n");

    // Print the Gantt Chart
    printGanttChart(processes, n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Allocate memory to store the processes
    Process *processes = (Process*)malloc(n * sizeof(Process));

    printf("Enter the details of each process (PID, Burst Time, Arrival Time):\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i].pid, &processes[i].burst_time, &processes[i].arrival_time);
    }

    // Run the FCFS scheduling algorithm
    fcfs(processes, n);

    // Free the dynamically allocated memory
    free(processes);

    return 0;
}