//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turn_around_time;
} Process;

void roundRobin(Process processes[], int numProcesses);

int main() {
    Process processes[MAX_PROCESS] = {{1, "A", 5, 0, 0},
                                {2, "B", 3, 0, 0},
                                {3, "C", 8, 0, 0},
                                {4, "D", 6, 0, 0},
                                {5, "E", 4, 0, 0}};

    int numProcesses = 5;

    clock_t start, end;
    double cpu_time;

    start = clock();
    roundRobin(processes, numProcesses);
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("CPU utilization: %.2f%%", (cpu_time * 100) / numProcesses);

    return 0;
}

void roundRobin(Process processes[], int numProcesses) {
    int i, j, currentProcess = 0, quantum = 3;

    for (i = 0; i < numProcesses; i++) {
        processes[i].waiting_time = 0;
    }

    while (!processes[currentProcess].waiting_time) {
        for (j = 0; j < numProcesses; j++) {
            if (processes[j].burst_time > 0) {
                processes[j].burst_time--;
                processes[currentProcess].waiting_time++;
            }
        }

        currentProcess = (currentProcess + 1) % numProcesses;
    }
}