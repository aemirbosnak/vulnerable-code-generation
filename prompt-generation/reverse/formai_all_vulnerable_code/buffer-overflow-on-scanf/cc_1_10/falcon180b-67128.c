//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_PRIORITY 10

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int priority;
};

void execute_processes(struct process *processes, int n) {
    int i, j, max_index, completed_processes = 0;
    int current_time = 0, time_quantum = 2;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        max_index = 0;

        for (i = 1; i < n; i++) {
            if (processes[i].priority > processes[max_index].priority) {
                max_index = i;
            }
        }

        if (processes[max_index].burst_time > time_quantum) {
            processes[max_index].burst_time -= time_quantum;
            current_time += time_quantum;
        } else {
            processes[max_index].burst_time = 0;
            completed_processes++;
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the process details:\n");

    for (int i = 0; i < n; i++) {
        printf("For process %d:\n", i+1);
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].id);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority: ");
        scanf("%d", &processes[i].priority);
    }

    execute_processes(processes, n);

    return 0;
}