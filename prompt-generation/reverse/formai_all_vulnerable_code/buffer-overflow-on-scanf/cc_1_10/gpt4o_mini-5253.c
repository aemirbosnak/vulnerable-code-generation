//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct {
    int id;             
    int burst_time;    
    int arrival_time;  
    int waiting_time;  
    int turnaround_time;
} Process;

void calculateWaitingTime(Process proc[], int n, int bt[], int wt[]) {
    wt[0] = 0; 
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i-1] + wt[i-1];
    }
}

void calculateTurnaroundTime(Process proc[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findavgTime(Process proc[], int n) {
    int bt[n]; 
    for (int i = 0; i < n; i++) {
        bt[i] = proc[i].burst_time; 
    }

    int wt[n], tat[n]; 

    calculateWaitingTime(proc, n, bt, wt);
    calculateTurnaroundTime(proc, n, bt, wt, tat);

    printf("PID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", proc[i].id, proc[i].burst_time, wt[i], tat[i]);
    }
}

void sortProcesses(Process proc[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (proc[j].arrival_time > proc[j+1].arrival_time) {
                Process temp = proc[j];
                proc[j] = proc[j+1];
                proc[j+1] = temp;
            }
}

int main() {
    int n;    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].id = i + 1; 
        printf("Enter Burst Time and Arrival Time for Process %d: ", proc[i].id);
        scanf("%d%d", &proc[i].burst_time, &proc[i].arrival_time);
        proc[i].waiting_time = 0;
        proc[i].turnaround_time = 0;
    }

    sortProcesses(proc, n);

    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d ", proc[i].id);
        sleep(proc[i].burst_time);
    }

    findavgTime(proc, n);
    return 0;
}