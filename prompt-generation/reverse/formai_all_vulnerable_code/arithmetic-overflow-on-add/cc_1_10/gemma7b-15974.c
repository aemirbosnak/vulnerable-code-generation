//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void roundRobin(struct Process processes[]) {
    int i = 0;
    int current_time = processes[0].arrival_time;
    while (i < MAX_PROCESS) {
        for (int j = 0; j < MAX_PROCESS; j++) {
            if (processes[j].arrival_time <= current_time && processes[j].burst_time > 0) {
                processes[j].waiting_time++;
                processes[j].burst_time--;
                current_time++;
            }
        }
        i++;
    }
}

int main() {
    struct Process processes[MAX_PROCESS];
    processes[0].pid = 1;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 5;
    processes[1].pid = 2;
    processes[1].arrival_time = 2;
    processes[1].burst_time = 4;
    processes[2].pid = 3;
    processes[2].arrival_time = 3;
    processes[2].burst_time = 3;
    processes[3].pid = 4;
    processes[3].arrival_time = 4;
    processes[3].burst_time = 2;
    processes[4].pid = 5;
    processes[4].arrival_time = 5;
    processes[4].burst_time = 1;

    roundRobin(processes);

    for (int i = 0; i < MAX_PROCESS; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}