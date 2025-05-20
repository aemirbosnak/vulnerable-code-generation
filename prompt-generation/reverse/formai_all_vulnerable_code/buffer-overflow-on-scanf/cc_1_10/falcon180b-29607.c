//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct process processes[], int n) {
    int i, j, temp, sum_wt = 0, sum_tt = 0;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time > 0) {
            for (j = 0; j < n; j++) {
                if (processes[j].burst_time > 0 && processes[j].burst_time < processes[i].burst_time)
                    processes[j].burst_time = 0;
            }
            processes[i].turnaround_time = processes[i].burst_time + processes[i].waiting_time;
            sum_wt += processes[i].waiting_time;
            sum_tt += processes[i].turnaround_time;
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nAverage Waiting Time: %f\n", (float)sum_wt / n);
    printf("Average Turnaround Time: %f\n", (float)sum_tt / n);
}

int main() {
    int n, i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process processes[n];

    for (i = 0; i < n; i++) {
        printf("Enter the details of process %d:\n", i + 1);
        printf("Enter process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    FCFS(processes, n);

    return 0;
}