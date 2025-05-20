//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: satisfied
/*
 * CPU Scheduling Algorithm - Round Robin (RR)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define QUEUE_SIZE 10
#define TIME_SLICE 100

typedef struct process {
    int pid;
    int burst_time;
    int priority;
    int arrival_time;
    int turnaround_time;
    int response_time;
    int waiting_time;
} process;

void round_robin(process *queue, int n) {
    int current_time = 0;
    int current_process = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        if (queue[current_process].burst_time > TIME_SLICE) {
            queue[current_process].burst_time -= TIME_SLICE;
        } else {
            queue[current_process].burst_time = 0;
            completed_processes++;
        }

        current_process = (current_process + 1) % n;
        current_time += TIME_SLICE;
    }

    for (int i = 0; i < n; i++) {
        queue[i].turnaround_time = current_time - queue[i].arrival_time;
        queue[i].waiting_time = queue[i].turnaround_time - queue[i].burst_time;
    }
}

int main() {
    process queue[QUEUE_SIZE];
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time, burst time and priority for process %d: ", i + 1);
        scanf("%d %d %d", &queue[i].arrival_time, &queue[i].burst_time, &queue[i].priority);
        queue[i].pid = i + 1;
    }

    round_robin(queue, n);

    printf("Process\tArrival Time\tBurst Time\tPriority\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", queue[i].pid, queue[i].arrival_time, queue[i].burst_time, queue[i].priority, queue[i].turnaround_time, queue[i].waiting_time);
    }

    return 0;
}