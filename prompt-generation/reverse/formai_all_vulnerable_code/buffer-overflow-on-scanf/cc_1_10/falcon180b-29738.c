//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, k, completed_processes = 0;
    int quantum = 2; // Time slice for each process
    int current_time = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].waiting_time == 0) {
                current_time += quantum;
                processes[i].burst_time -= quantum;
                completed_processes++;
            } else if (processes[i].burst_time > 0 && processes[i].waiting_time > 0) {
                processes[i].waiting_time += quantum;
            }
        }

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time == 0 && processes[i].waiting_time > 0) {
                current_time += processes[i].waiting_time;
                processes[i].waiting_time = 0;
                processes[i].turnaround_time = current_time - processes[i].waiting_time - processes[i].burst_time;
                completed_processes++;
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, i;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process details:\n");
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}