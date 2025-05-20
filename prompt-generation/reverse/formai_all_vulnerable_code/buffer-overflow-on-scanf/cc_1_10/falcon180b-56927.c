//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define DELAY 2

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process *queue, int n, int quantum) {
    int i, j, sum = 0;
    for (i = 0; i < n; i++) {
        queue[i].waiting_time = 0;
        queue[i].turnaround_time = 0;
    }

    for (i = 0; i < n; i++) {
        if (queue[i].burst_time <= quantum) {
            queue[i].turnaround_time = queue[i].waiting_time + queue[i].burst_time;
            for (j = i + 1; j < n; j++) {
                sum += queue[j].burst_time;
            }
            queue[i].waiting_time = sum;
        } else {
            int temp = quantum - queue[i].burst_time;
            queue[i].turnaround_time = queue[i].waiting_time + temp * (n - 1);
            for (j = i + 1; j < n; j++) {
                sum += queue[j].burst_time;
            }
            queue[i].waiting_time = sum - temp * (n - 1);
        }
        printf("\nProcess %d executed in %d ms", queue[i].pid, queue[i].burst_time);
        sleep(queue[i].burst_time / 1000);
    }
}

int main() {
    struct process queue[MAX];
    int n, i, j, sum = 0;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter process id, burst time for process %d: ", i + 1);
        scanf("%d %d", &queue[i].pid, &queue[i].burst_time);
        sum += queue[i].burst_time;
    }

    printf("\nGantt chart:\n");
    for (i = 0; i < n; i++) {
        printf("\nProcess %d | ", queue[i].pid);
        for (j = 0; j < queue[i].burst_time / DELAY; j++) {
            printf("* ");
        }
        printf("\n");
    }

    execute_processes(queue, n, 2);

    return 0;
}