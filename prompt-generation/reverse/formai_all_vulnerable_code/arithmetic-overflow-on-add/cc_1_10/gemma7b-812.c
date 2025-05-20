//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

struct process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void simulate_cpu_scheduling(struct process processes[]) {
    int current_time = 0;
    int quantum = 5;
    int completed = 0;

    for (int i = 0; i < MAX_PROCESSES && completed < MAX_PROCESSES; i++) {
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        processes[i].turnaround_time = current_time + processes[i].burst_time - processes[i].arrival_time;

        if (processes[i].waiting_time >= quantum) {
            processes[i].waiting_time -= quantum;
            current_time += quantum;

            if (processes[i].waiting_time == 0) {
                completed++;
            }
        } else {
            current_time += processes[i].burst_time;
            processes[i].waiting_time = 0;
            completed++;
        }
    }

    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nTotal Processes Completed: %d", completed);
}

int main() {
    struct process processes[MAX_PROCESSES];

    // Populate processes with sample data
    processes[0].id = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 8;

    processes[1].id = 2;
    processes[1].arrival_time = 2;
    processes[1].burst_time = 4;

    processes[2].id = 3;
    processes[2].arrival_time = 4;
    processes[2].burst_time = 6;

    processes[3].id = 4;
    processes[3].arrival_time = 6;
    processes[3].burst_time = 2;

    processes[4].id = 5;
    processes[4].arrival_time = 8;
    processes[4].burst_time = 3;

    simulate_cpu_scheduling(processes);

    return 0;
}