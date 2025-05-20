//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

// Function to calculate waiting time for FCFS
void findWaitingTimeFCFS(struct Process processes[], int n) {
    processes[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
    }
}

// Function to calculate turnaround time for FCFS
void findTurnaroundTimeFCFS(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
    }
}

// Function to implement FCFS Scheduling
void FCFS(struct Process processes[], int n) {
    findWaitingTimeFCFS(processes, n);
    findTurnaroundTimeFCFS(processes, n);
    
    printf("\nFCFS Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

// Function to calculate waiting time for SJF
void findWaitingTimeSJF(struct Process processes[], int n) {
    int completed[n];
    int total_completed = 0;
    int t = 0; // Current time
    while (total_completed < n) {
        int idx = -1;
        for (int j = 0; j < n; j++) {
            if (!completed[j] && processes[j].burst_time <= t) {
                if (idx == -1 || processes[j].burst_time < processes[idx].burst_time) {
                    idx = j;
                }
            }
        }
        
        if (idx != -1) {
            completed[idx] = 1;
            total_completed++;
            t += processes[idx].burst_time;
            processes[idx].waiting_time = t - processes[idx].burst_time;
            processes[idx].turnaround_time = processes[idx].waiting_time + processes[idx].burst_time;
        } else {
            t++; // Increment time if no process is ready
        }
    }
}

// Function to implement SJF Scheduling
void SJF(struct Process processes[], int n) {
    // Initialize completed processes
    int completed[n];
    for (int i = 0; i < n; i++) {
        completed[i] = 0;
    }

    findWaitingTimeSJF(processes, n);
    
    printf("\nSJF Scheduling:\n");
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

// Function to implement Round Robin Scheduling
void RoundRobin(struct Process processes[], int n, int quantum) {
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time;
    }

    int t = 0; // Current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0; // There are still processes to execute

                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    t += remaining_time[i];
                    processes[i].waiting_time = t - processes[i].burst_time;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    remaining_time[i] = 0;
                }
            }
        }
        if (done) break; // Exit if all processes are complete
    }

    printf("\nRound Robin Scheduling (Quantum = %d):\n", quantum);
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Burst Time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burst_time);
        processes[i].waiting_time = 0; // Initial waiting time
        processes[i].turnaround_time = 0; // Initial turnaround time
    }

    FCFS(processes, n);
    SJF(processes, n);

    int quantum;
    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);
    RoundRobin(processes, n, quantum);

    return 0;
}