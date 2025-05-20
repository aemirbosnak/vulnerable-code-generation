//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

typedef struct {
    int process_id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void findWaitingTime(Process proc[], int n, int bt[], int wt[]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnAroundTime(Process proc[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(Process proc[], int n) {
    int bt[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burst_time;
    }
    int wt[MAX_PROCESSES], tat[MAX_PROCESSES];

    findWaitingTime(proc, n, bt, wt);
    findTurnAroundTime(proc, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    printf("Processes | Burst Time | Waiting",
           " Time | Turn-Around Time\n");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t     | %d\t    | %d\t  | %d\n",
               proc[i].process_id, bt[i], wt[i], tat[i]);
    }
    printf("----------------------------------------------------\n");

    printf("Average waiting time = %.2f\n", total_wt / n);
    printf("Average turn-around time = %.2f\n", total_tat / n);
}

void sortProcessesByArrivalTime(Process proc[], int n) {
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

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        proc[i].process_id = i + 1;
        printf("Enter Burst time for Process %d: ", proc[i].process_id);
        scanf("%d", &proc[i].burst_time);
        printf("Enter Arrival time for Process %d: ", proc[i].process_id);
        scanf("%d", &proc[i].arrival_time);
    }

    sortProcessesByArrivalTime(proc, n);
    findavgTime(proc, n);

    return 0;
}