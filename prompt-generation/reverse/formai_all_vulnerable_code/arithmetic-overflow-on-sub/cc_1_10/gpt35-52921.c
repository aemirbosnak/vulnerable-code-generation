//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include<stdio.h>

int main() {
    int n, i, j, temp, bt[20], wt[20], tat[20], process[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times of the %d processes:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        process[i] = i + 1;
    }

    // Sorting the burst times in ascending order
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(bt[j] > bt[j+1]) {
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                temp = process[j];
                process[j] = process[j+1];
                process[j+1] = temp;
            }
        }
    }

    wt[0] = 0;
    for(i = 1; i < n; i++) {
        wt[i] = 0;
        for(j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        avg_wt += wt[i];
    }

    avg_wt /= n;
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avg_tat += tat[i];
        printf("\nP%d\t\t%d\t\t%d\t\t%d", process[i], bt[i], wt[i], tat[i]);
    }

    avg_tat /= n;
    printf("\n\nAverage Waiting Time = %0.2f", avg_wt);
    printf("\nAverage Turnaround Time = %0.2f", avg_tat);

    return 0;
}