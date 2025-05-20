//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid;          // Process ID
    int burst_time;   // Burst time
    int arrival_time; // Arrival time
    int waiting_time; // Waiting time
    int turnaround_time; // Turnaround time
} Process;

void findWaitingTime(Process proc[], int n, int bt[], int wt[]) {
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(Process proc[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(Process proc[], int n) {
    int bt[MAX_PROCESSES]; // Burst times
    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burst_time;
    }

    int wt[MAX_PROCESSES]; // Waiting times
    findWaitingTime(proc, n, bt, wt);

    int tat[MAX_PROCESSES]; // Turnaround times
    findTurnAroundTime(proc, n, bt, wt, tat);

    float total_wait = 0, total_tat = 0;
    printf("\nPID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wait += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, bt[i], proc[i].arrival_time, wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wait/n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);
}

void sortProcesses(Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].arrival_time > proc[j].arrival_time) {
                Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

int main() {
    Process proc[MAX_PROCESSES];
    int n;

    printf("Enter the number of processes (max %d): ", MAX_PROCESSES);
    scanf("%d", &n);
    if(n > MAX_PROCESSES || n <= 0) {
        printf("Invalid number of processes!\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Arrival Time for Process %d:\n", i + 1);
        proc[i].pid = i + 1; 
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
    }

    // Sort processes by arrival time
    sortProcesses(proc, n);

    // Calculate average waiting time and turnaround time
    findavgTime(proc, n);

    return 0;
}