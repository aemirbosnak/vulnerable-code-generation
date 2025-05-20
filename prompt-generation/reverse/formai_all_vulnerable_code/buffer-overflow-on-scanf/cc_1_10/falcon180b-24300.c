//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define DELAY 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute(struct process *processes, int n, int quantum) {
    int i, j, index, max_index = 0, completed = 0;
    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > quantum) {
            processes[i].burst_time -= quantum;
            processes[i].waiting_time += quantum;
            printf("\nProcess %d executed for %d time units", i + 1, quantum);
        } else {
            printf("\nProcess %d executed for %d time units", i + 1, processes[i].burst_time);
            completed++;
        }
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
    printf("\n\nGantt Chart:\n");
    for (i = 0; i < n; i++) {
        if (completed < i) {
            printf("P%d ", i + 1);
            for (j = 0; j < processes[i].turnaround_time; j++) {
                if (j % (processes[i].burst_time + DELAY) == 0) {
                    printf("*");
                } else {
                    printf("-");
                }
            }
            printf("\n");
        }
    }
}

void main() {
    int i, n, quantum;
    struct process processes[MAX];

    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the details of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("\nFor process %d:\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    execute(processes, n, quantum);
}