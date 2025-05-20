//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;        // Process ID
    int bt;         // Burst Time
    int wt;         // Waiting Time
    int tat;        // Turnaround Time
} Process;

void findWaitingTime(Process proc[], int n, int bt[], int quantum) {
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; // Current time
    while (1) {
        int done = 1; // Check if all processes are done
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                done = 0; // There is still a process that needs time
                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t = t + rem_bt[i];
                    proc[i].wt = t - bt[i]; // Calculate waiting time
                    rem_bt[i] = 0;
                }
            }
        }
        if (done) // All processes are finished
            break;
    }
}

void findTurnAroundTime(Process proc[], int n) {
    for (int i = 0; i < n; i++)
        proc[i].tat = proc[i].bt + proc[i].wt; // Turnaround Time = Burst Time + Waiting Time
}

void calcAvgTime(Process proc[], int n, int quantum) {
    int bt[n];
    for (int i = 0; i < n; i++)
        bt[i] = proc[i].bt;

    findWaitingTime(proc, n, bt, quantum);
    findTurnAroundTime(proc, n);

    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
    }
    printf("Average Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

void displayProcesses(Process proc[], int n) {
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].wt, proc[i].tat);
    }
}

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process proc[n];

    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Process %d: ", proc[i].pid);
        scanf("%d", &proc[i].bt);
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    
    calcAvgTime(proc, n, quantum);
    displayProcesses(proc, n);
    
    return 0;
}