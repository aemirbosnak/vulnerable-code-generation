//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    int i;

    printf("\nGantt Chart:\n");
    printf("+----+");
    for (i = 0; i < n; i++) {
        printf("----+");
    }
    printf("\n");

    while (completed_processes < n) {
        int smallest_burst_time = MAX;
        int smallest_index = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= smallest_burst_time) {
                smallest_burst_time = processes[i].burst_time;
                smallest_index = i;
            }
        }

        if (smallest_index == -1) {
            current_time += TIME_QUANTUM;
        } else {
            processes[smallest_index].burst_time -= TIME_QUANTUM;
            current_time += TIME_QUANTUM;

            if (processes[smallest_index].burst_time == 0) {
                completed_processes++;
                printf("P%d completed at %d\n", smallest_index + 1, current_time);
            } else {
                printf("P%d executed for %dms at %d\n", smallest_index + 1, TIME_QUANTUM, current_time);
            }
        }

        printf("+----+");
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                printf("----+");
            } else {
                printf("    +");
            }
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process processes[n];

    printf("\nEnter process details:\n");
    printf("PID   Burst Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", i + 1);
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}