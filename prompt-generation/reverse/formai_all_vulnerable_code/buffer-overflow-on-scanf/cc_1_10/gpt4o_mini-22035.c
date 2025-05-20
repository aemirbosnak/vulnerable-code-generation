//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
} Process;

void findWaitingTime(Process proc[], int n, int bt[], int wt[]) {
    wt[0] = 0;
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
    int bt[MAX], wt[MAX], tat[MAX];
    
    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burst_time;
    }
    
    findWaitingTime(proc, n, bt, wt);
    findTurnAroundTime(proc, n, bt, wt, tat);

    printf("\nPID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, wt[i], tat[i]);
    }
}

void sortProcesses(Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (proc[j].arrival_time > proc[j + 1].arrival_time) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

int main() {
    Process proc[MAX];
    int n;

    printf("Enter number of processes (max %d): ", MAX);
    scanf("%d", &n);

    if(n < 1 || n > MAX) {
        printf("Invalid number of processes. Please enter a number between 1 and 10.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1;
        printf("Enter Burst Time for Process P%d: ", proc[i].id);
        scanf("%d", &proc[i].burst_time);
        printf("Enter Arrival Time for Process P%d: ", proc[i].id);
        scanf("%d", &proc[i].arrival_time);
    }

    sortProcesses(proc, n);

    findavgTime(proc, n);

    return 0;
}