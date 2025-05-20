//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define INF 9999

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_process(struct process *queue, int n, int quantum) {
    int i, j, sum_wt = 0, sum_tat = 0;
    int count = 0;
    int completed_processes = 0;

    for (i = 0; i < n; i++) {
        queue[i].waiting_time = 0;
    }

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (queue[i].burst_time > quantum && queue[i].burst_time - queue[i].waiting_time > 0) {
                queue[i].burst_time -= quantum;
                queue[i].waiting_time += quantum;
                sum_wt += quantum;
            } else if (queue[i].burst_time > 0) {
                queue[i].burst_time -= queue[i].burst_time;
                sum_wt += queue[i].burst_time;
                completed_processes++;
            }
        }

        for (i = 0; i < n; i++) {
            if (queue[i].burst_time > 0) {
                count++;
            }
        }

        if (count == 0) {
            break;
        }

        for (i = 0; i < n; i++) {
            if (queue[i].burst_time > 0) {
                queue[i].waiting_time += quantum;
            }
        }

        sum_tat += quantum;
    }

    printf("Average waiting time: %.2f\n", (float) sum_wt / n);
    printf("Average turnaround time: %.2f\n", (float) sum_tat / n);
}

int main() {
    int n, i, quantum;
    struct process queue[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time of each process:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &queue[i].burst_time);
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    execute_process(queue, n, quantum);

    return 0;
}