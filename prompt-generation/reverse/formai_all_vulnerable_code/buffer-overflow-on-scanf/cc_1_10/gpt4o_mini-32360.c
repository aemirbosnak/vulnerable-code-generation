//GPT-4o-mini DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int id;                  // Process ID
    int burstTime;          // Time required for the process to complete
    int remainingTime;      // Time remaining for the completion of the process
} Process;

// Function to execute the Round Robin scheduling
void roundRobin(Process processes[], int numProcesses, int quantum) {
    int time = 0;  // Current time
    bool allDone;

    // Continue to run until all processes are completed
    do {
        allDone = true;  // Assume all processes are done

        for (int i = 0; i < numProcesses; i++) {
            if (processes[i].remainingTime > 0) {
                allDone = false; // At least one process is still running

                if (processes[i].remainingTime > quantum) {
                    time += quantum; // Increment time by the time quantum
                    processes[i].remainingTime -= quantum;  // Reduce remaining time
                    printf("Process %d executed for %d time units.\n", processes[i].id, quantum);
                } else {
                    time += processes[i].remainingTime; // Execute remaining time
                    printf("Process %d executed for %d time units.\n", processes[i].id, processes[i].remainingTime);
                    processes[i].remainingTime = 0; // Mark process as completed
                }
            }
        }
    } while (!allDone);

    // Display completion status
    printf("\nAll processes completed at time %d.\n", time);
}

// Function to initialize processes
void initializeProcesses(Process processes[], int numProcesses, int burstTimes[]) {
    for (int i = 0; i < numProcesses; i++) {
        processes[i].id = i + 1;  // Assign process IDs starting from 1
        processes[i].burstTime = burstTimes[i];
        processes[i].remainingTime = burstTimes[i]; // Initially, remaining time is the same as burst time
    }
}

int main() {
    int numProcesses;
    int quantum;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    if (numProcesses <= 0) {
        printf("Number of processes must be greater than zero.\n");
        return -1;
    }

    Process *processes = (Process *)malloc(numProcesses * sizeof(Process));
    if (processes == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    int *burstTimes = (int *)malloc(numProcesses * sizeof(int));
    if (burstTimes == NULL) {
        free(processes);
        fprintf(stderr, "Memory allocation failed.\n");
        return -1;
    }

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < numProcesses; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burstTimes[i]);
    }
    
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    // Initialize processes and execute round-robin scheduling
    initializeProcesses(processes, numProcesses, burstTimes);
    roundRobin(processes, numProcesses, quantum);

    // Free dynamically allocated memory
    free(processes);
    free(burstTimes);

    return 0;
}