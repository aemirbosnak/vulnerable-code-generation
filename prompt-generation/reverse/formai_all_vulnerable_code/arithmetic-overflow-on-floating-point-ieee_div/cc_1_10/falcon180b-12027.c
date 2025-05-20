//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct process processes[], int n) {
    int i, j, completed_processes = 0;
    int current_time = 0;
    int context_switch_count = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > current_time) {
            current_time = processes[i].burst_time;
        }

        for (j = 0; j < i; j++) {
            if (processes[j].burst_time > current_time && completed_processes == 0) {
                current_time = processes[j].burst_time;
            }
        }

        if (completed_processes == 0) {
            processes[i].waiting_time = current_time - processes[i].burst_time;
            completed_processes++;
        }

        context_switch_count++;
        current_time += processes[i].burst_time;
        processes[i].turnaround_time = current_time - processes[i].burst_time - processes[i].waiting_time;
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %f\n", (float) completed_processes / n);
    printf("Average Turnaround Time: %f\n", (float) (current_time - processes[n - 1].burst_time) / n);
    printf("Context Switches: %d\n", context_switch_count);
}

int main() {
    int n;
    struct process processes[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process details:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter process ID: ");
        scanf("%d", &processes[i].id);

        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    FCFS(processes, n);

    return 0;
}