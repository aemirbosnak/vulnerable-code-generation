//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PROCESSES 5
#define MAX_BURST_TIME 10
#define MAX_WAITING_TIME 20
#define MAX_TURNAROUND_TIME 30

struct process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_burst_time;
};

void execute_processes(struct process *processes, int quantum) {
    int i, j, completed_processes = 0;
    int current_time = 0;

    for (i = 0; i < NUM_PROCESSES; i++) {
        processes[i].remaining_burst_time = processes[i].burst_time;
    }

    while (completed_processes < NUM_PROCESSES) {
        for (i = 0; i < NUM_PROCESSES; i++) {
            if (processes[i].remaining_burst_time > 0) {
                if (processes[i].remaining_burst_time <= quantum) {
                    processes[i].remaining_burst_time = 0;
                    processes[i].waiting_time += quantum - processes[i].remaining_burst_time;
                    processes[i].turnaround_time += processes[i].waiting_time + processes[i].burst_time;
                    completed_processes++;
                } else {
                    processes[i].remaining_burst_time -= quantum;
                    current_time += quantum;
                }
            }
        }
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < NUM_PROCESSES; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }
}

int main() {
    struct process processes[NUM_PROCESSES];
    int i;

    srand(time(NULL));

    for (i = 0; i < NUM_PROCESSES; i++) {
        processes[i].pid = i + 1;
        processes[i].burst_time = rand() % MAX_BURST_TIME + 1;
    }

    execute_processes(processes, 2);

    return 0;
}