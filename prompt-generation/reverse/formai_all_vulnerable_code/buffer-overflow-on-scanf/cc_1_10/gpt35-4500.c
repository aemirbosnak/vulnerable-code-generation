//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void round_robin(int n, int bt[], int tq) {
    int i, j, remaining[n], wt[n], tat[n], t, total_tat=0, total_wt=0;
    for (i=0; i<n; i++)
        remaining[i] = bt[i];
    i = 0;
    while (1) {
        int completed = 1;
        for (j=0; j<n; j++) {
            if (remaining[j]>0) {
                completed = 0;
                if (remaining[j]>tq) {
                    t = tq;
                    remaining[j] -= tq;
                }
                else {
                    t = remaining[j];
                    remaining[j] = 0;
                }
                i += t;
                tat[j] = i;
                wt[j] = tat[j] - bt[j];
                if (wt[j]<0)
                    wt[j] = 0;
                total_tat += tat[j];
                total_wt += wt[j];
            }
        }
        if (completed==1)
            break;
    }
    printf("\nProcess Completion Times: ");
    for (i=0; i<n; i++)
        printf("%d ", tat[i]);
    printf("\nAverage Turnaround Time: %.2f", (float)total_tat/n);
    printf("\nAverage Waiting Time: %.2f", (float)total_wt/n);
}

int main() {
    int n, bt[100], tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time for each process:\n");
    for (int i=0; i<n; i++) {
        printf("P[%d]: ", i+1);
        scanf("%d", &bt[i]);
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    round_robin(n, bt, tq);
    return 0;
}