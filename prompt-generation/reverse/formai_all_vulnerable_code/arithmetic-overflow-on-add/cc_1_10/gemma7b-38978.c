//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROC 5
#define MAX_TIME 10

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void roundRobin(struct process processes[], int n) {
    int current_time = 0;
    int i = 0;
    int flag = 0;

    while (current_time < MAX_TIME) {
        for (i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
                processes[i].burst_time--;
                processes[i].waiting_time++;
                flag = 1;
            }
        }

        if (flag == 0) {
            current_time++;
        } else {
            current_time++;
            flag = 0;
        }
    }
}

int main() {
    struct process processes[MAX_PROC];

    // Create processes
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

    roundRobin(processes, MAX_PROC);

    // Print results
    for (int i = 0; i < MAX_PROC; i++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].pid, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}