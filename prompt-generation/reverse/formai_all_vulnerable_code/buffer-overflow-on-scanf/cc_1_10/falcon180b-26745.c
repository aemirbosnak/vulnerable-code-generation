//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_PROCESSES 10

typedef struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

Process processes[MAX_PROCESSES];

int main() {
    int i, j, n, sum = 0, quantum = 2;
    int count = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        scanf("%d", &processes[i].burst_time);
        sum += processes[i].burst_time;
        count++;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j += quantum) {
            if (j == 0) {
                processes[i].waiting_time = 0;
            } else {
                processes[i].waiting_time += quantum;
            }

            if (j == processes[i].burst_time - 1) {
                processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
            }
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage waiting time: %.2f", (float)sum / n);

    return 0;
}