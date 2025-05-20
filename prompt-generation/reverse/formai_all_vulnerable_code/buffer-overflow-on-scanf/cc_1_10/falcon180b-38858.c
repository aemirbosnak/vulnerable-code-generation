//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
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
    int i, j, count = 0, completed_processes = 0;
    int time_quantum = (int) (quantum * (double) DELAY);

    printf("\nGantt Chart:\n");
    printf("+----+----+----+----+\n");

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].waiting_time == 0) {
                if (processes[i].burst_time <= quantum) {
                    processes[i].burst_time = 0;
                    processes[i].waiting_time = 0;
                    processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
                    completed_processes++;
                } else {
                    processes[i].burst_time -= quantum;
                    count++;
                }
            }
        }

        printf("+----+----+----+----+\n");
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                printf("| %d ", i + 1);
            } else {
                printf("|              ");
            }
        }
        printf("|\n");

        if (count == 0) {
            break;
        }

        for (j = 0; j < time_quantum; j++) {
            if (count == 0) {
                break;
            }
            for (i = 0; i < n; i++) {
                if (processes[i].burst_time > 0) {
                    processes[i].burst_time--;
                }
            }
            count--;
        }
    }

    printf("\nProcess\tID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i + 1, processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int i, n, quantum;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the details of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].id);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &quantum);

    execute(processes, n, quantum);

    return 0;
}