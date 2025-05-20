//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include <stdio.h>

int main() {
    int n, quantum, i, j, total_waiting_time = 0, total_turnaround_time = 0;
    int arrival_time[10], burst_time[10], temp[10];
    float average_waiting_time, average_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get arrival time and burst time for each process
    for (i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        temp[i] = burst_time[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Run processes in a circular queue until they all complete
    for (i = 0, j = 0; n != 0;) {
        if (temp[j] <= quantum && temp[j] > 0) {
            total_turnaround_time += quantum;
            temp[j] = 0;
            n--;
        } else if (temp[j] > 0) {
            temp[j] -= quantum;
            total_turnaround_time += quantum;
        }

        if (temp[j] == 0 && n != 0) {
            total_waiting_time += total_turnaround_time - arrival_time[j] - burst_time[j];
        }

        // Move on to next process in queue
        if (j == n - 1) {
            j = 0;
        } else if (arrival_time[j+1] <= total_turnaround_time) {
            j++;
        } else {
            j = 0;
        }
    }

    // Calculate averages and print results
    average_waiting_time = (float)total_waiting_time / n;
    average_turnaround_time = (float)total_turnaround_time / n;

    printf("Average waiting time: %f\n", average_waiting_time);
    printf("Average turnaround time: %f\n", average_turnaround_time);

    return 0;
}