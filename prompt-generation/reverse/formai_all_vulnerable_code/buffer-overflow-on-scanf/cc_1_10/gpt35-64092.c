//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
#include <stdio.h>

int n, bt[20], wt[20], tat[20];

void find_waiting_time(int p[], int n) {
    if(n == 0){
        return;
    }
    static int i = 0, j = 0;
    int time_slice, rem_bt[n];
    printf("\nEnter Time Slice for Process %d: ", p[i]);
    scanf("%d", &time_slice);
    rem_bt[i] = bt[i];
    if (rem_bt[i] > time_slice){
        rem_bt[i] -= time_slice;
        printf("\nProcess %d will execute again with %d burst time", p[i], rem_bt[i]);
        for (j = 0; j < n; j++){
            if (j != i && rem_bt[j] > 0){
                wt[j] += time_slice;
            }
        }
    }
    else{
        printf("\nProcess %d completed execution", p[i]);
        for (j = 0; j < n; j++){
            if (j != i && rem_bt[j] > 0){
                wt[j] += rem_bt[i];
            }
        }
        rem_bt[i] = 0;
    }
    i = (i + 1) % n;
    find_waiting_time(p, n-1);
}

void find_turn_around_time(int p[], int n) {
    for (int i = 0; i < n; i++){
        tat[i] = bt[i] + wt[i];
    }
}

void find_avg_time(int p[], int n) {
    int total_wt = 0, total_tat = 0;
    find_waiting_time(p, n);
    find_turn_around_time(p, n);
    printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time");
    for (int i = 0; i < n; i++){
        total_wt += wt[i];
        total_tat += tat[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage Waiting Time = %.2f", (float)total_wt / (float)n);
    printf("\nAverage Turn Around Time = %.2f", (float)total_tat / (float)n);
}

int main() {
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int p[n];
    for (int i = 0; i < n; ++i){
        printf("\nEnter Burst Time for Process %d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
        wt[i] = 0;
    }
    find_avg_time(p, n);
    return 0;
}