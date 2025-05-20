//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESSES 5

struct process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;
};

void schedule(struct process processes[]) {
    int i, j, time = 0, quantum = 5;
    int completed = 0;
    processes[0].waitingTime = 0;

    while (!completed) {
        for (i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].arrivalTime <= time && processes[i].burstTime > 0) {
                processes[i].burstTime--;
                processes[i].waitingTime++;
                if (processes[i].burstTime == 0) {
                    completed = 1;
                    processes[i].turnAroundTime = time + 1;
                }
            }
        }

        time++;
    }

    for (j = 0; j < MAX_PROCESSES; j++) {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[j].id, processes[j].waitingTime, processes[j].turnAroundTime);
    }
}

int main() {
    struct process processes[MAX_PROCESSES];

    processes[0].id = 1;
    processes[0].arrivalTime = 0;
    processes[0].burstTime = 8;

    processes[1].id = 2;
    processes[1].arrivalTime = 2;
    processes[1].burstTime = 4;

    processes[2].id = 3;
    processes[2].arrivalTime = 4;
    processes[2].burstTime = 6;

    processes[3].id = 4;
    processes[3].arrivalTime = 6;
    processes[3].burstTime = 2;

    processes[4].id = 5;
    processes[4].arrivalTime = 8;
    processes[4].burstTime = 3;

    schedule(processes);

    return 0;
}