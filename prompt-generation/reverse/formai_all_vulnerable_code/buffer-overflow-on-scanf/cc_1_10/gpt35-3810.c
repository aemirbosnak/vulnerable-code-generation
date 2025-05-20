//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// struct representing a process
typedef struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainingTime;
} Process;

// array of processes
Process processes[MAX_PROCESSES];

// number of processes
int numProcesses;

// function to perform round-robin scheduling
void roundRobin(int timeQuantum) {
    // time counter
    int time = 0;

    // index of process being executed
    int currentProcess = 0;

    // flag to check if any process is remaining
    int remainingProcesses = 1;

    // loop till all processes are executed
    while (remainingProcesses) {
        // set flag to 0
        remainingProcesses = 0;

        // loop through all processes
        for (int i = 0; i < numProcesses; i++) {
            // execute process if it has arrived and has remaining time
            if (processes[i].arrivalTime <= time && processes[i].remainingTime > 0) {
                // set flag to 1
                remainingProcesses = 1;

                // execute process for time quantum or remaining time, whichever is smaller
                int executionTime = processes[i].remainingTime < timeQuantum ? processes[i].remainingTime : timeQuantum;

                // update process remaining time and time counter
                processes[i].remainingTime -= executionTime;
                time += executionTime;

                // if process is complete, print completion time and turnaround time
                if (processes[i].remainingTime == 0) {
                    printf("Process %d completed execution at time %d. Turnaround time: %d\n", processes[i].id, time, time - processes[i].arrivalTime);
                }
            }
        }
    }
}

// function to perform shortest job first scheduling
void shortestJobFirst() {
    // time counter
    int time = 0;

    // loop through all processes
    for (int i = 0; i < numProcesses; i++) {
        // index of process with shortest remaining time
        int j = -1;

        // loop through all processes and find the one with shortest remaining time
        for (int k = 0; k < numProcesses; k++) {
            if (processes[k].arrivalTime <= time && processes[k].remainingTime > 0) {
                if (j == -1 || processes[k].remainingTime < processes[j].remainingTime) {
                    j = k;
                }
            }
        }

        // if no process found, increment time and continue
        if (j == -1) {
            time++;
            i--;
            continue;
        }

        // execute process for its remaining time
        int executionTime = processes[j].remainingTime;
        processes[j].remainingTime = 0;
        time += executionTime;

        // print completion time and turnaround time
        printf("Process %d completed execution at time %d. Turnaround time: %d\n", processes[j].id, time, time - processes[j].arrivalTime);
    }
}

int main() {
    // get number of processes from user
    printf("Enter number of processes: ");
    scanf("%d", &numProcesses);

    // get process details from user
    for (int i = 0; i < numProcesses; i++) {
        printf("Enter details of process %d (arrival time, burst time, priority): ", i + 1);
        
        processes[i].id = i + 1;

        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].burstTime, &processes[i].priority);

        processes[i].remainingTime = processes[i].burstTime;
    }

    // perform round-robin scheduling
    printf("\nRound Robin Scheduling with time quantum 2\n");
    roundRobin(2);

    // perform shortest job first scheduling
    printf("\nShortest Job First Scheduling\n");
    shortestJobFirst();

    return 0;
}