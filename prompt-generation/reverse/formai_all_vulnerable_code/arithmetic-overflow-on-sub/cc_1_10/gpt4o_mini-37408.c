//GPT-4o-mini DATASET v1.0 Category: System boot optimizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int priority;
    int burstTime;
    int waitTime;
    int turnaroundTime;
} Process;

void initializeProcesses(Process *processes, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for process %d: ", i + 1);
        scanf("%s", processes[i].name);
        processes[i].priority = rand() % 10 + 1; // Random priority between 1 and 10
        processes[i].burstTime = rand() % 20 + 1; // Random burst time between 1 and 20
        processes[i].waitTime = 0;
        processes[i].turnaroundTime = 0;
    }
}

void displayProcesses(Process *processes, int count) {
    printf("\nProcesses:\n");
    printf("Name\tPriority\tBurst Time\tWait Time\tTurnaround Time\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",
               processes[i].name,
               processes[i].priority,
               processes[i].burstTime,
               processes[i].waitTime,
               processes[i].turnaroundTime);
    }
}

void calculateWaitAndTurnaroundTime(Process *processes, int count) {
    // Calculate waiting time
    for (int i = 1; i < count; i++) {
        processes[i].waitTime = processes[i - 1].waitTime + processes[i - 1].burstTime;
    }

    // Calculate turnaround time
    for (int i = 0; i < count; i++) {
        processes[i].turnaroundTime = processes[i].waitTime + processes[i].burstTime;
    }
}

void optimizeBootTime(Process *processes, int count) {
    // Sort by priority (higher number means higher priority)
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    Process processes[MAX_PROCESS];
    int numProcesses;

    printf("Enter the number of processes (max %d): ", MAX_PROCESS);
    scanf("%d", &numProcesses);
    if (numProcesses > MAX_PROCESS) {
        printf("Number of processes can't exceed %d\n", MAX_PROCESS);
        return 1;
    }

    initializeProcesses(processes, numProcesses);
    optimizeBootTime(processes, numProcesses);
    calculateWaitAndTurnaroundTime(processes, numProcesses);
    displayProcesses(processes, numProcesses);

    return 0;
}