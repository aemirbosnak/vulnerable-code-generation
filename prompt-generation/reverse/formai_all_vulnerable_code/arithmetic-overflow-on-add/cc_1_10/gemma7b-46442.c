//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 5

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

void schedule(Process processes[]) {
    int i = 0;
    int time = 0;
    int completed = 0;

    while (!completed) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].arrival_time <= time && processes[i].burst_time > 0) {
                processes[i].waiting_time++;
                processes[i].burst_time--;
                if (processes[i].burst_time == 0) {
                    completed = 1;
                    processes[i].turnaround_time = time + processes[i].waiting_time;
                }
            }
        }

        time++;
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    processes[0].process_id = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 5;

    processes[1].process_id = 2;
    processes[1].arrival_time = 2;
    processes[1].burst_time = 4;

    processes[2].process_id = 3;
    processes[2].arrival_time = 3;
    processes[2].burst_time = 3;

    processes[3].process_id = 4;
    processes[3].arrival_time = 4;
    processes[3].burst_time = 2;

    processes[4].process_id = 5;
    processes[4].arrival_time = 5;
    processes[4].burst_time = 1;

    schedule(processes);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].process_id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}