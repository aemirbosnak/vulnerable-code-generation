//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int arrival_time;
    int burst_time;
    int priority;
} process;

int main() {
    int n, i, j;
    float avg_waiting_time, avg_turnaround_time;
    process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time, burst time, and priority for each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    }

    // Sort the processes by arrival time
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Calculate the waiting time and turnaround time for each process
    int waiting_time[n], turnaround_time[n];
    waiting_time[0] = 0;
    turnaround_time[0] = processes[0].burst_time;
    for (i = 1; i < n; i++) {
        waiting_time[i] = turnaround_time[i - 1] - processes[i].arrival_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }

    // Calculate the average waiting time and average turnaround time
    avg_waiting_time = 0;
    avg_turnaround_time = 0;
    for (i = 0; i < n; i++) {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Print the results
    printf("Process\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time: %.2f\n", avg_waiting_time);
    printf("Average turnaround time: %.2f\n", avg_turnaround_time);

    return 0;
}