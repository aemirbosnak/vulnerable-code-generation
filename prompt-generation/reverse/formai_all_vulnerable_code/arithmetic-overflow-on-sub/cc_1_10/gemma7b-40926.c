//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_TIME 10

typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

Process processes[MAX_PROCESSES];

void schedule() {
    int currentTime = 0;
    int completed = 0;

    while (!completed) {
        for (int i = 0; i < MAX_PROCESSES; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].burstTime > 0) {
                processes[i].burstTime--;
                processes[i].waitingTime++;
                if (processes[i].burstTime == 0) {
                    completed = 1;
                    processes[i].turnaroundTime = currentTime - processes[i].arrivalTime;
                }
            }
        }

        currentTime++;
    }
}

int main() {
    time_t tStart, tEnd;

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].id = i + 1;
        processes[i].arrivalTime = rand() % MAX_TIME;
        processes[i].burstTime = rand() % MAX_TIME;
    }

    tStart = time(NULL);
    schedule();
    tEnd = time(NULL);

    printf("Time taken: %f seconds\n", tEnd - tStart);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d: arrival time %d, burst time %d, waiting time %d, turnaround time %d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    return 0;
}