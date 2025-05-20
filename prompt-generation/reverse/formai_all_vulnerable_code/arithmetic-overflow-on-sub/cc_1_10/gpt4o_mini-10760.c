//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;         // Process ID
    int burst;     // Burst Time
    int arrival;   // Arrival Time
    int priority;  // Priority Level
    int wait_time; // Waiting Time
    int turnaround_time; // Turnaround Time
} Process;

void findWaitingTime(Process processes[], int n) {
    int service_time[MAX_PROCESSES];
    service_time[0] = processes[0].arrival;
    processes[0].wait_time = 0;

    for (int i = 1; i < n; i++) {
        service_time[i] = service_time[i - 1] + processes[i - 1].burst;
        processes[i].wait_time = service_time[i] - processes[i].arrival;
        if (processes[i].wait_time < 0) {
            processes[i].wait_time = 0; // No waiting time if it arrives before the previous process finishes
        }
    }
}

void findTurnaroundTime(Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst + processes[i].wait_time;
    }
}

void calculateAverageTimes(Process processes[], int n) {
    findWaitingTime(processes, n);
    findTurnaroundTime(processes, n);

    float total_wait_time = 0, total_turnaround_time = 0;

    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].id, processes[i].burst,
               processes[i].arrival, processes[i].wait_time,
               processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %.2f", total_wait_time / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_turnaround_time / n);
}

void sortProcessesByArrival(Process processes[], int n) {
    // Simple Selection Sort by Arrival Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival > processes[j].arrival) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);

    if (n > MAX_PROCESSES) {
        printf("Error: Number of processes exceeds the maximum limit of %d.\n", MAX_PROCESSES);
        return -1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Assigning Process IDs
        printf("Enter Burst Time and Arrival Time for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].burst, &processes[i].arrival);
        processes[i].priority = 1; // For simplicity, we assign a default priority of 1
    }

    // Sort processes based on Arrival Time
    sortProcessesByArrival(processes, n);

    // Calculate and display Average Waiting and Turnaround Times
    calculateAverageTimes(processes, n);

    return 0;
}