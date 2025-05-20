//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: recursive
// This program implements the Round Robin CPU scheduling algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void round_robin(struct process *queue, int n, int quantum) {
    int i, j, sum = 0;
    for (i = 0; i < n; i++) {
        queue[i].turnaround_time = 0;
        queue[i].waiting_time = 0;
    }
    for (i = 0; i < n; i++) {
        if (queue[i].burst_time > quantum) {
            queue[i].burst_time -= quantum;
            sum += quantum;
        } else {
            sum += queue[i].burst_time;
        }
    }
    for (i = 0; i < n; i++) {
        queue[i].turnaround_time = queue[i].waiting_time + queue[i].burst_time;
    }
    for (i = 0; i < n; i++) {
        printf("Process %d executed for %d time units\n", queue[i].pid, queue[i].burst_time);
    }
    printf("Average waiting time: %.2f\n", ((float) sum / n));
    printf("Average turnaround time: %.2f\n", ((float) sum / n));
}

int main() {
    int n, i;
    struct process queue[MAX];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the details of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("Enter the process id: ");
        scanf("%d", &queue[i].pid);
        printf("Enter the burst time: ");
        scanf("%d", &queue[i].burst_time);
    }
    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    round_robin(queue, n, quantum);
    return 0;
}