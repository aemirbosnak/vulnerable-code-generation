//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: distributed
#include<stdio.h>

int n, time = 0;
int wt[20], tat[20], bt[20], rt[20];
int completed = 0;

void roundRobin(int quantum) {
    int i;
    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] > quantum) {
                    rt[i] -= quantum;
                    time += quantum;
                }
                else {
                    time += rt[i];
                    tat[i] = time - bt[i];
                    rt[i] = 0;
                    completed++;
                }
            }
        }
    }
}

void display() {
    int i;
    float avgtat = 0, avgwt = 0;
    printf("\n\tProcess Burst Time  \tWaiting Time\tTurnaround Time");

    for (i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\n\n\tAverage Waiting Time : %f", avgwt / n);
    printf("\n\tAverage Turnaround Time : %f", avgtat / n);
}

void main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int quantum;
    printf("\nEnter Time Quantum:");
    scanf("%d", &quantum);

    int i;
    printf("\nEnter Burst Time for each process: ");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    roundRobin(quantum);
    display();
}