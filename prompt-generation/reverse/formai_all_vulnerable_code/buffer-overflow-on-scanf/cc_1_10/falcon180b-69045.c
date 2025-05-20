//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int quantum = 2;
    int current_time = 0;
    int i, j, completed_processes = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (processes[i].burst_time <= quantum) {
                    processes[i].burst_time = 0;
                    processes[i].waiting_time += quantum - processes[i].burst_time;
                    processes[i].turnaround_time += processes[i].waiting_time + processes[i].burst_time;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= quantum;
                    current_time += quantum;
                }
            }
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process details:\n");
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].id);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}