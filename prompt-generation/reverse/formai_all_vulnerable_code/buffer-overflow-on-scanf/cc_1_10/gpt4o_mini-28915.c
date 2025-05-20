//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to sort processes by arrival time
void sortProcessesByArrival(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

// Function to calculate waiting time and turnaround time
void calculateTimes(Process processes[], int n) {
    int total_waiting_time = 0, total_turnaround_time = 0;
    
    processes[0].completion_time = processes[0].arrival_time + processes[0].burst_time;
    for (int i = 1; i < n; i++) {
        processes[i].completion_time = processes[i - 1].completion_time + processes[i].burst_time;
    }
    
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

// Function to implement First-Come, First-Served (FCFS) Scheduling
void fcfsScheduling(Process processes[], int n) {
    sortProcessesByArrival(processes, n);
    calculateTimes(processes, n);

    printf("\nFCFS Scheduling:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }
}

// Function to simulate Shortest Job Next (SJN) Scheduling
void sjnScheduling(Process processes[], int n) {
    sortProcessesByArrival(processes, n);
    int completed = 0, current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    while (completed < n) {
        int idx = -1;
        int min_burst_time = 9999;

        // Find the process with the smallest burst time that has arrived
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
                if (processes[i].burst_time < min_burst_time) {
                    min_burst_time = processes[i].burst_time;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            current_time += processes[idx].burst_time;
            processes[idx].completion_time = current_time;
            processes[idx].turnaround_time = processes[idx].completion_time - processes[idx].arrival_time;
            processes[idx].waiting_time = processes[idx].turnaround_time - processes[idx].burst_time;
            total_waiting_time += processes[idx].waiting_time;
            total_turnaround_time += processes[idx].turnaround_time;
            processes[idx].burst_time = 0;  // Mark as completed
            completed++;
        } else {
            current_time++;  // No process is ready, increment time
        }
    }

    printf("\nSJN Scheduling:\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
               processes[i].id, processes[i].arrival_time,
               processes[i].burst_time, processes[i].completion_time,
               processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }

    fcfsScheduling(processes, n);
    sjnScheduling(processes, n);

    return 0;
}