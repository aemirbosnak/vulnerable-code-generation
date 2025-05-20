//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS 10

typedef struct Process
{
    int pid;
    char name[20];
    int burstTime;
    int waitingTime;
    int completionTime;
} Process;

void roundRobin(Process *processes, int numProcesses)
{
    int i = 0;
    int currentProcess = 0;
    int timeQuantum = 5;

    while (!processes[currentProcess].completionTime)
    {
        processes[currentProcess].waitingTime++;
        sleep(timeQuantum);
        processes[currentProcess].completionTime = 1;
        currentProcess = (currentProcess + 1) % numProcesses;
    }
}

int main()
{
    Process processes[MAX_PROCESS];

    for (int i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].pid = i + 1;
        processes[i].name[0] = 'A' + i;
        processes[i].burstTime = rand() % 5 + 1;
    }

    roundRobin(processes, MAX_PROCESS);

    for (int i = 0; i < MAX_PROCESS; i++)
    {
        printf("Process %d: completion time = %d, waiting time = %d\n", processes[i].pid, processes[i].completionTime, processes[i].waitingTime);
    }

    return 0;
}