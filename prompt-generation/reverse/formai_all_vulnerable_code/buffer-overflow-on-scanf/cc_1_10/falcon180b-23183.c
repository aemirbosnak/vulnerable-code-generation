//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void execute_processes(Process processes[], int n) {
    int i, j, current_time = 0;
    int completed_processes = 0;
    int time_quantum = 2;

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < processes[i].burst_time; j++) {
            if (completed_processes == 0 || (completed_processes % n) == i) {
                current_time++;
            } else {
                current_time += time_quantum;
            }

            if (j == 0) {
                printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].burst_time, 0, 0);
            }

            if (j == processes[i].burst_time - 1) {
                processes[i].turnaround_time = current_time - processes[i].burst_time + 1;
            }
        }

        completed_processes++;
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("Enter process ID and burst time:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &processes[i].id, &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}