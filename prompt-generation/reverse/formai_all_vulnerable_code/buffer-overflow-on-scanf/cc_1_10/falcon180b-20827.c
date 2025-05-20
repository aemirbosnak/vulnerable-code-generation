//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define FCFS 1
#define SJF 2
#define PRIORITY 3
#define ROUND_ROBIN 4

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_process(struct process *queue, int size, int quantum, int algorithm) {
    int i, j, count = 0, completed_processes = 0;
    int index = 0;

    while (completed_processes < size) {
        for (i = 0; i < size; i++) {
            if (queue[i].burst_time > 0) {
                if (algorithm == FCFS) {
                    if (queue[index].burst_time > queue[i].burst_time) {
                        index = i;
                    }
                }
                else if (algorithm == SJF) {
                    if (queue[index].burst_time > queue[i].burst_time) {
                        index = i;
                    }
                }
                else if (algorithm == PRIORITY) {
                    if (queue[index].burst_time > queue[i].burst_time) {
                        index = i;
                    }
                }
                else if (algorithm == ROUND_ROBIN) {
                    if (queue[index].burst_time > 0) {
                        queue[index].burst_time -= quantum;
                        if (queue[index].burst_time == 0) {
                            queue[index].waiting_time += quantum;
                            queue[index].turnaround_time += queue[index].waiting_time + queue[index].burst_time;
                            completed_processes++;
                            count += queue[index].burst_time;
                            queue[index].burst_time = 0;
                        }
                    }
                    index = (index + 1) % size;
                }
            }
        }
    }
}

void display_queue(struct process *queue, int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("Process %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n", queue[i].pid, queue[i].burst_time, queue[i].waiting_time, queue[i].turnaround_time);
    }
}

int main() {
    int i, size, burst_time, quantum;
    int algorithm;

    printf("Enter the number of processes: ");
    scanf("%d", &size);

    struct process queue[size];

    for (i = 0; i < size; i++) {
        printf("Enter the burst time for process %d: ", i+1);
        scanf("%d", &burst_time);
        queue[i].pid = i+1;
        queue[i].burst_time = burst_time;
    }

    printf("Enter the quantum: ");
    scanf("%d", &quantum);

    printf("Enter the scheduling algorithm (FCFS/SJF/PRIORITY/ROUND_ROBIN): ");
    scanf("%d", &algorithm);

    execute_process(queue, size, quantum, algorithm);

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    display_queue(queue, size);

    return 0;
}