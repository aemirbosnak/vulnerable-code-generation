//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid; // Process ID
    int burst_time; // Burst time
    int remaining_time; // Remaining time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
} Process;

void find_average_times(Process processes[], int n, int quantum) {
    int total_time = 0;
    int completed = 0;
    
    // Create a Gantt chart array
    int gantt[MAX_PROCESSES * 2];
    int index = 0;

    while (completed < n) {
        int flag = 0; // Flag to check if any process was executed in this round
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    total_time += quantum;
                    processes[i].remaining_time -= quantum;
                    gantt[index++] = processes[i].pid; // Log PID to Gantt chart
                } else {
                    total_time += processes[i].remaining_time;
                    processes[i].waiting_time = total_time - processes[i].burst_time; // Calculate waiting time
                    processes[i].turnaround_time = total_time; // Calculate turnaround time
                    gantt[index++] = processes[i].pid; // Log PID to Gantt chart
                    processes[i].remaining_time = 0; // Mark process as completed
                    completed++;
                }
                flag = 1; // Mark that at least one process ran
            }
        }
        // If no process ran in this turn, just increment total time
        if (!flag) {
            total_time++;
        }
    }
}

void print_gantt_chart(int gantt[], int n) {
    printf("Gantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", gantt[i]);
    }
    printf("|\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

void print_process_times(Process processes[], int n) {
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n; // Number of processes
    int quantum; // Time quantum
    Process processes[MAX_PROCESSES];

    // Input number of processes
    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    // Error check
    if (n > MAX_PROCESSES) {
        printf("Error: Exceeded maximum number of processes.\n");
        return -1;
    }

    // Input burst time and initialize processes
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time; // Initialize remaining time
    }

    // Input time quantum
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Execute scheduling
    find_average_times(processes, n, quantum);

    // Print Gantt Chart
    print_gantt_chart(processes, n);

    // Print Process Times
    print_process_times(processes, n);

    return 0;
}