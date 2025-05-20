//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int i, j, smallest_index = 0;
    int completed_processes = 0;
    int time_quantum = 2;

    for (i = 0; i < n; i++) {
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= time_quantum) {
                if (processes[i].waiting_time == 0) {
                    processes[i].waiting_time = time_quantum - processes[i].burst_time;
                    processes[i].burst_time = 0;
                    completed_processes++;
                } else {
                    processes[i].waiting_time -= time_quantum;
                    processes[i].burst_time -= time_quantum;
                }
            } else if (processes[i].burst_time > time_quantum) {
                if (processes[i].waiting_time == 0) {
                    processes[i].waiting_time = time_quantum;
                    processes[i].burst_time -= time_quantum;
                } else {
                    processes[i].waiting_time += time_quantum;
                    processes[i].burst_time -= time_quantum;
                }
            }
        }

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time == 0) {
                if (processes[i].waiting_time > processes[smallest_index].waiting_time) {
                    smallest_index = i;
                }
            }
        }

        if (smallest_index!= 0) {
            for (j = smallest_index; j > 0; j--) {
                processes[j] = processes[j - 1];
            }
            processes[0] = processes[smallest_index];
        }
    }
}

int main() {
    struct process processes[MAX];
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}