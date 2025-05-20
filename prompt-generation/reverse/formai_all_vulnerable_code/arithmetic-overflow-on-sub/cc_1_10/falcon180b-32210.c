//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    for (i = 0; i < n; i++) {
        if (processes[i].burst_time <= TIME_QUANTUM) {
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = processes[i].burst_time;
            current_time += processes[i].burst_time;
            completed_processes++;
        } else {
            processes[i].waiting_time = 0;
            for (int j = 0; j < processes[i].burst_time / TIME_QUANTUM; j++) {
                current_time += TIME_QUANTUM;
                if (current_time >= processes[i].burst_time) {
                    processes[i].waiting_time += TIME_QUANTUM;
                    current_time = processes[i].burst_time;
                } else {
                    processes[i].turnaround_time += TIME_QUANTUM;
                }
            }
            current_time += processes[i].burst_time % TIME_QUANTUM;
            completed_processes++;
        }
    }

    printf("Average waiting time: %.2f\n", (float) (current_time - processes[0].burst_time) / n);
    printf("Average turnaround time: %.2f\n", (float) processes[0].turnaround_time / n);
}

int main() {
    struct process processes[MAX];
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process details:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    execute_processes(processes, n);

    return 0;
}