//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX 100
#define DELAY 2

// Process structure
struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, current_process = 0, completed_processes = 0;
    int quantum = 2; // Time slice of 2 units

    printf("\nGantt chart for CPU scheduling:\n");
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].burst_time <= quantum) {
                    processes[i].burst_time = 0;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= quantum;
                    current_process = i;
                }
            }
        }

        if (current_process == -1) {
            current_process = 0;
        }

        for (j = 0; j < n; j++) {
            if (j!= current_process && processes[j].burst_time > 0) {
                processes[j].waiting_time += quantum;
            }
        }

        printf("\nCPU scheduling at time %d:\n", current_process);
        for (i = 0; i < n; i++) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", i, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
        }
    }
}

int main() {
    int n, i;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter details for %d processes:\n", n);

    for (i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}