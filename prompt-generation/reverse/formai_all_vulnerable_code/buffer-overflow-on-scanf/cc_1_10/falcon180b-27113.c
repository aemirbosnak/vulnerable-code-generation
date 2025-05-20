//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void sjf(struct process processes[], int n) {
    int i, j, min_bt = 999, index = 0;

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time < min_bt) {
            min_bt = processes[i].burst_time;
            index = i;
        }
    }

    for (i = 0; i < n; i++) {
        if (i == index)
            continue;

        for (j = 0; j < n; j++) {
            if (i == j)
                continue;

            if (processes[i].burst_time > processes[j].burst_time) {
                int temp = processes[i].burst_time;
                processes[i].burst_time = processes[j].burst_time;
                processes[j].burst_time = temp;
            }
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = processes[i].burst_time;

        for (j = 0; j < i; j++) {
            processes[i].waiting_time += processes[j].burst_time;
        }

        processes[i].turnaround_time += processes[i].waiting_time;
    }

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

void main() {
    int i, n;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process ID, burst time, and priority:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &processes[i].id, &processes[i].burst_time);
    }

    printf("\nProcess ID\tBurst Time\tPriority\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].id);
    }

    sjf(processes, n);
}