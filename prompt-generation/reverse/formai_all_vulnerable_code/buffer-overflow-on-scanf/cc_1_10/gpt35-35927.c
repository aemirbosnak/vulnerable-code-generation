//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pid;    // Process ID
    int bt;     // Burst Time
    int wt;     // Waiting Time
    int tat;    // Turnaround Time
} Process;

// Function to find the waiting time for all processes
void findWaitingTime(Process *proc, int n, int quantum) {
    int *bt_remaining = (int*)malloc(n * sizeof(int));
    int *tat = (int*)malloc(n * sizeof(int));
    int *status = (int*)malloc(n * sizeof(int));
    int cur_time = 0;
    int completed = 0;
    int i;
    for (i = 0; i < n; i++) {
        bt_remaining[i] = proc[i].bt;
        tat[i] = 0;
        status[i] = 0;
    }
    
    while (completed < n) {
        int flag = 0;
        for (i = 0; i < n; i++) {
            if (bt_remaining[i] > 0 && status[i] == 0) {
                flag = 1;
                if (bt_remaining[i] > quantum) {
                    cur_time += quantum;
                    bt_remaining[i] -= quantum;
                }
                else {
                    cur_time += bt_remaining[i];
                    tat[i] = cur_time;
                    proc[i].wt = tat[i] - proc[i].bt;
                    bt_remaining[i] = 0;
                    status[i] = 1;
                    completed++;
                }
            }
        }
        if (flag == 0)
            cur_time++;
    }
    free(bt_remaining);
    free(tat);
    free(status);
}

// Function to find the turnaround time for all processes
void findTurnaroundTime(Process *proc, int n) {
    int i;
    for (i = 0; i < n; i++)
        proc[i].tat = proc[i].bt + proc[i].wt;
}

// Function to calculate average waiting and turnaround times
void findAvgTime(Process *proc, int n, int quantum) {
    int total_wt = 0, total_tat = 0;
    int i;
    findWaitingTime(proc, n, quantum);
    findTurnaroundTime(proc, n);
    printf("P   Burst Time   Waiting Time   Turnaround Time\n");
    for (i = 0; i < n; i++) {
        total_wt += proc[i].wt;
        total_tat += proc[i].tat;
        printf("%d   %d            %d              %d\n", proc[i].pid, proc[i].bt,
               proc[i].wt, proc[i].tat);
    }
    printf("Average waiting time = %.2f\n",
           (float)total_wt / (float)n);
    printf("Average turnaround time = %.2f\n\n",
           (float)total_tat / (float)n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    Process *proc = (Process*)malloc(n * sizeof(Process));
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &proc[i].bt);
        proc[i].pid = i + 1;
    }
    int quantum;
    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);
    findAvgTime(proc, n, quantum);
    free(proc);
    return 0;
}