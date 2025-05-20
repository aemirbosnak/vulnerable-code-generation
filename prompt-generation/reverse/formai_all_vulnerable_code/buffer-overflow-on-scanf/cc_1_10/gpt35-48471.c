//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROC 100 // Maximum number of processes

int main() {

    int i, j, n, quantum, cnt = 0, burst_time[MAX_PROC], remaining_time[MAX_PROC], waiting_time[MAX_PROC], turnaround_time[MAX_PROC], time = 0;
    bool done[MAX_PROC] = {false};

    printf("Enter the total number of processes (max %d): ", MAX_PROC);
    scanf("%d", &n);

    // Input burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        remaining_time[i] = burst_time[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    while (cnt < n) {
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done[i] = false;
                if (remaining_time[i] > quantum) {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                else {
                    time += remaining_time[i];
                    waiting_time[i] = time - burst_time[i];
                    remaining_time[i] = 0;
                    turnaround_time[i] = time;
                    cnt++;
                    done[i] = true;
                }
            }
        }
        if (cnt == n) break;
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    int total_waiting_time = 0, total_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("\nAverage waiting time: %f\n", (float)total_waiting_time/n);
    printf("Average turnaround time: %f\n", (float)total_turnaround_time/n);

    return 0;
}