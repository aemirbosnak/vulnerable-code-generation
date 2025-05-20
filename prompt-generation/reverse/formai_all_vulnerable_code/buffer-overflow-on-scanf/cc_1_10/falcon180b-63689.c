//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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
        printf("------+");
    }
    printf("\n");

    while (completed_processes < n) {
        int min_burst_time = MAX;
        int min_index = -1;

        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0 && processes[i].burst_time <= min_burst_time) {
                min_burst_time = processes[i].burst_time;
                min_index = i;
            }
        }

        if (min_index == -1) {
            current_time++;
        } else {
            processes[min_index].burst_time--;
            printf("%d ", min_index + 1);
            for (i = 0; i < processes[min_index].burst_time; i++) {
                printf("*");
            }
            printf("\n");

            if (processes[min_index].burst_time == 0) {
                completed_processes++;
            }
        }
    }

    printf("\nAverage Turnaround Time: %f\n", (float)current_time / n);
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process processes[n];

    printf("\nEnter process details:\n");
    for (int i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}