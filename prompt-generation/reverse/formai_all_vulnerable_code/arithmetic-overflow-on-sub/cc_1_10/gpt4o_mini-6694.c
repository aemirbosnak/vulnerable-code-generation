//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: optimized
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

void calculateWaitingTime(Process processes[], int n, int wt[]) {
    wt[0] = 0; // First process has no waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = processes[i-1].burst_time + wt[i-1];
    }
}

void calculateTurnaroundTime(Process processes[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = processes[i].burst_time + wt[i];
    }
}

void findAvgTime(Process processes[], int n) {
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    
    calculateWaitingTime(processes, n, wt);
    calculateTurnaroundTime(processes, n, wt, tat);
    
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].arrival_time, wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter burst time and arrival time for Process %d: ", processes[i].id);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
    }

    // Sort processes according to arrival time using selection sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    findAvgTime(processes, n);
    return 0;
}