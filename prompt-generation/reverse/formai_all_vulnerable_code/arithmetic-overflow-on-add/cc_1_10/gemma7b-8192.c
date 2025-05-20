//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_PROCESSES 10

typedef struct Process {
    int id;
    char name[20];
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

void roundRobin(Process processes[], int numProcesses) {
    int i = 0;
    int currentProcess = 0;
    int timeQuantum = 5;

    while (processes[currentProcess].burstTime > 0) {
        processes[currentProcess].waitingTime++;
        sleep(timeQuantum);
        processes[currentProcess].burstTime--;

        if (i == numProcesses - 1) {
            i = 0;
        } else {
            i++;
        }

        currentProcess = i;
    }
}

int main() {
    Process processes[MAX_PROCESSES];

    for (int i = 0; i < MAX_PROCESSES; i++) {
        processes[i].id = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burstTime = rand() % 5 + 1;
    }

    roundRobin(processes, MAX_PROCESSES);

    for (int i = 0; i < MAX_PROCESSES; i++) {
        printf("Process %d: ", processes[i].id);
        printf("Waiting Time: %d ", processes[i].waitingTime);
        printf(", Turnaround Time: %d\n", processes[i].turnaroundTime);
    }

    return 0;
}