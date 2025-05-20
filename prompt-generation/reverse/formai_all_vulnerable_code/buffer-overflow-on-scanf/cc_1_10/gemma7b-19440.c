//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: visionary
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 10

typedef struct Process
{
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} Process;

Process processes[MAX_PROCESSES];

void schedule()
{
    int i;
    int currentProcess = 0;
    int time = 0;

    for (i = 0; i < MAX_PROCESSES; i++)
    {
        processes[i].waitingTime++;
    }

    while (!processes[currentProcess].burstTime == 0)
    {
        processes[currentProcess].burstTime--;
        time++;
    }

    processes[currentProcess].turnaroundTime = time - processes[currentProcess].waitingTime;

    currentProcess = (currentProcess + 1) % MAX_PROCESSES;
}

int main()
{
    int i;
    int numProcesses;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (i = 0; i < numProcesses; i++)
    {
        processes[i].id = i + 1;
        printf("Enter the burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
    }

    schedule();

    printf("Process Scheduling Results:\n");

    for (i = 0; i < numProcesses; i++)
    {
        printf("Process ID: %d, Waiting Time: %d, Turnaround Time: %d\n", processes[i].id, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    return 0;
}