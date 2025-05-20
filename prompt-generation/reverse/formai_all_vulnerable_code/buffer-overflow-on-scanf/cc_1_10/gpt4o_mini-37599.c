//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;         // Process ID
    int burst_time;  // Burst time
    int arrival_time; // Arrival time
} Process;

void findWaitingTime(Process processes[], int n, int bt[], int wt[], int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
    }

    int t = 0; // current time
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    wt[i] = t - bt[i] - processes[i].arrival_time;
                    rem_bt[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
}

void findTurnAroundTime(Process processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void calculateAverageTime(Process processes[], int n, int quantum) {
    int bt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        bt[i] = processes[i].burst_time;
    }

    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, wt[i], tat[i]);
    }

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if (n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1; // Assigning process ID

        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
    }

    printf("Enter time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);

    calculateAverageTime(processes, n, quantum);

    return 0;
}