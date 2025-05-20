//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, j, n, count = 0;
    int burst_time[10], waiting_time[10], turnaround_time[10];
    int quantum = 2;
    float avg_wt = 0, avg_tt = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
    }

    for(i = 0; i < n; i++) {
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(burst_time[j] > burst_time[j+1]) {
                int temp = burst_time[j];
                burst_time[j] = burst_time[j+1];
                burst_time[j+1] = temp;
            }
        }
        waiting_time[i] += burst_time[i];
        turnaround_time[i] += burst_time[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nGantt Chart:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < burst_time[i]; j++) {
            printf("%d ", i+1);
        }
        printf("\n");
    }

    return 0;
}