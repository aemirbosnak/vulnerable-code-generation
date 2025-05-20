//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Surprise! Let's simulate a CPU scheduling algorithm.\n");
    printf("We'll use the Round Robin algorithm today.\n");

    int n, i, j, time_quantum, remain, flag = 0, time, waiting_time = 0, turnaround_time = 0;
    int arrival_time[10], burst_time[10], remaining_time[10];
    printf("\nEnter the total number of processes: ");
    scanf("%d", &n);

    remain = n;
    for(i = 0; i < n; i++) {
        printf("\nEnter arrival time and burst time for process %d: ", i+1);
        scanf("%d%d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &time_quantum);

    printf("\nGantt chart for Round Robin CPU scheduling:\n");
    printf("0");

    for(time = 0, i = 0; remain != 0;) {
        if(remaining_time[i] <= time_quantum && remaining_time[i] > 0) {
            time += remaining_time[i];
            printf(" | %d P%d (%d)", time, i+1, remaining_time[i]);
            remaining_time[i] = 0;
            flag = 1;
        }
        else if(remaining_time[i] > 0) {
            remaining_time[i] -= time_quantum;
            time += time_quantum;
            printf(" | %d P%d (%d)", time, i+1, time_quantum);
        }

        if(remaining_time[i] == 0 && flag == 1) {
            remain--;
            waiting_time += time - arrival_time[i] - burst_time[i];
            turnaround_time += time - arrival_time[i];
            flag = 0;
        }

        if(i == n - 1)
            i = 0;
        else if(arrival_time[i+1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\n\nTotal waiting time: %d", waiting_time);
    printf("\nAverage waiting time: %.2f", (float) waiting_time/n);
    printf("\nTotal turnaround time: %d", turnaround_time);
    printf("\nAverage turnaround time: %.2f\n", (float) turnaround_time/n);

    return 0;
}