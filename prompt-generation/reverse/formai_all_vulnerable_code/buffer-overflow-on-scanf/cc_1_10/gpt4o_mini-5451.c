//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int remaining_time;
} Process;

void findWaitingTime(Process proc[], int n, int bt[], int wt[], int quantum) {
    int remaining_processes = n, time = 0;
    
    while (remaining_processes > 0) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                found = 1;
                if (proc[i].remaining_time > quantum) {
                    time += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    time += proc[i].remaining_time;
                    wt[i] = time - proc[i].burst_time - proc[i].arrival_time;
                    proc[i].remaining_time = 0;
                    remaining_processes--;
                }
            }
        }
        if (!found) time++; // If no processes are left, increase time
    }
}

void calculateTurnaroundTime(Process proc[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(Process proc[], int n, int quantum) {
    int bt[MAX], wt[MAX], tat[MAX];

    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burst_time;
        proc[i].remaining_time = proc[i].burst_time; // Remaining time is initially equal to burst time
    }

    findWaitingTime(proc, n, bt, wt, quantum);
    calculateTurnaroundTime(proc, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", proc[i].process_id, proc[i].burst_time, wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    Process proc[MAX];
    int n, quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        proc[i].process_id = i + 1;
        printf("Enter burst time for process %d: ", proc[i].process_id);
        scanf("%d", &proc[i].burst_time);
        proc[i].arrival_time = 0; // For simplicity, all processes arrive at time 0
    }

    printf("Enter the time quantum for Round Robin scheduling: ");
    scanf("%d", &quantum);
    
    findavgTime(proc, n, quantum);
    
    return 0;
}