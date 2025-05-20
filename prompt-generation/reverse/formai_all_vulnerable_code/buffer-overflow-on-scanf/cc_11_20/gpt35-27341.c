//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
} Process;

int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    Process *processes = calloc(n, sizeof(Process));
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Enter the arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int total_time = 0, completed = 0, time_slice;
    printf("\nGantt chart:\n");
    printf("0 ");
    for (int i = 0; completed != n; i = (i+1)%n) {
        if (processes[i].remaining_time == 0) continue;
        if (processes[i].remaining_time <= quantum) {
            time_slice = processes[i].remaining_time;
            processes[i].remaining_time = 0;
            completed++;
        } else {
            time_slice = quantum;
            processes[i].remaining_time -= quantum;
        }

        for (int j = 0; j < time_slice; j++) {
            printf("P%d ", processes[i].pid);
        }
        total_time += time_slice;

        for (int j = 0; j < n; j++) {
            if (processes[j].remaining_time > 0 && processes[j].arrival_time <= total_time && j != i) {
                processes[j].waiting_time += time_slice;
            }
        }
    }
    printf("\n");

    double total_waiting_time = 0, total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
    }

    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
    printf("\n");

    printf("Average Waiting Time: %.2lf\n", total_waiting_time/n);
    printf("Average Turnaround Time: %.2lf\n", total_turnaround_time/n);

    free(processes);
    return 0;
}