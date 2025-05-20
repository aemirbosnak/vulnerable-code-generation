//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include <stdio.h>

#define MAX 10

void schedule()
{
    int i, j, k, quantum = 0, roundRobin = 0;

    // Create an array of processes
    struct process
    {
        int pid;
        int burstTime;
        int waitingTime;
    } processes[MAX];

    // Initialize the processes
    processes[0].pid = 1;
    processes[0].burstTime = 5;
    processes[0].waitingTime = 0;

    processes[1].pid = 2;
    processes[1].burstTime = 3;
    processes[1].waitingTime = 0;

    processes[2].pid = 3;
    processes[2].burstTime = 8;
    processes[2].waitingTime = 0;

    processes[3].pid = 4;
    processes[3].burstTime = 2;
    processes[3].waitingTime = 0;

    processes[4].pid = 5;
    processes[4].burstTime = 4;
    processes[4].waitingTime = 0;

    // Calculate the total waiting time for each process
    for (i = 0; i < MAX; i++)
    {
        k = 0;
        for (j = 0; j < MAX; j++)
        {
            if (processes[j].burstTime > k)
            {
                k = processes[j].burstTime;
            }
        }
        processes[i].waitingTime = k - processes[i].burstTime;
    }

    // Round robin scheduling
    quantum = processes[0].burstTime;
    roundRobin = 0;
    while (quantum > 0)
    {
        for (i = 0; i < MAX; i++)
        {
            if (processes[i].burstTime > 0)
            {
                processes[i].burstTime--;
                roundRobin++;
            }
        }
        quantum--;
    }

    // Print the final waiting time for each process
    for (i = 0; i < MAX; i++)
    {
        printf("Process ID: %d, Waiting Time: %d\n", processes[i].pid, processes[i].waitingTime);
    }
}

int main()
{
    schedule();

    return 0;
}