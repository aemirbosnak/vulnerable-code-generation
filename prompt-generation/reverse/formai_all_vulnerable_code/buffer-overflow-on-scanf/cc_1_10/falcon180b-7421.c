//Falcon-180B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct {
    int data;
    int pri;
} Process;

int main() {
    int i, j, quantum, total_quantum = 0, temp = 0;
    int burst_time[MAX_SIZE], waiting_time[MAX_SIZE], turnaround_time[MAX_SIZE];
    int complete = 0, count = 0;
    Process process[MAX_SIZE];

    printf("Enter the number of processes: ");
    scanf("%d", &count);

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < count; i++) {
        scanf("%d", &burst_time[i]);
        process[i].data = i + 1;
        process[i].pri = rand() % 10;
        printf("Process %d has priority %d\n", i + 1, process[i].pri);
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    for (i = 0; i < count; i++) {
        total_quantum += burst_time[i];
    }

    int current_time = 0;
    while (complete!= count) {
        for (i = 0; i < count; i++) {
            if (process[i].data == 0) {
                continue;
            }

            if (burst_time[i] > quantum) {
                burst_time[i] -= quantum;
                process[i].data = i + 1;
                waiting_time[i] += quantum;
                current_time += quantum;
            } else {
                burst_time[i] = 0;
                waiting_time[i] += burst_time[i];
                turnaround_time[i] = waiting_time[i] + burst_time[i];
                complete++;
            }
        }
    }

    printf("Gantt Chart:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < count; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].data, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average waiting time: %d\n", (int) ((double) total_quantum / count));

    return 0;
}