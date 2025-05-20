//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TIME_QUANTUM 2

struct process {
    int id;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute_processes(struct process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;
    int i;

    while (completed_processes < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].burst_time > 0) {
                if (current_time >= processes[i].waiting_time) {
                    if (current_time + TIME_QUANTUM > processes[i].burst_time) {
                        processes[i].burst_time -= TIME_QUANTUM;
                        completed_processes++;
                    } else {
                        processes[i].burst_time -= TIME_QUANTUM;
                        current_time += TIME_QUANTUM;
                    }
                } else {
                    current_time++;
                }
            }
        }
    }

    printf("\n");
    for (i = 0; i < n; i++) {
        printf("Process %d: Burst time = %d, Waiting time = %d, Turnaround time = %d\n",
               processes[i].id, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    int n, i;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the details of %d processes:\n", n);
    for (i = 0; i < n; i++) {
        printf("For process %d:\n", i + 1);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
        processes[i].id = i + 1;
        processes[i].waiting_time = processes[i].turnaround_time = 0;
    }

    execute_processes(processes, n);

    return 0;
}