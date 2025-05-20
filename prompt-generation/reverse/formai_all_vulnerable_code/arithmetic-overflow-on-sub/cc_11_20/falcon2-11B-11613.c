//Falcon2-11B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_TIME 100
#define TIME_QUANTUM 10

struct process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
};

int main()
{
    struct process processes[MAX_PROCESS];
    int numProcesses = 0;
    int i;
    clock_t start, end;

    srand(time(0));

    for (i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].pid = rand() % 100;
        processes[i].arrivalTime = rand() % MAX_TIME;
        processes[i].burstTime = rand() % MAX_TIME;
        processes[i].remainingTime = processes[i].burstTime;
    }

    start = clock();

    while (numProcesses > 0)
    {
        int minRemainingTime = MAX_TIME;
        int minRemainingTimePid = -1;

        for (i = 0; i < numProcesses; i++)
        {
            if (processes[i].remainingTime < minRemainingTime && processes[i].remainingTime > 0)
            {
                minRemainingTime = processes[i].remainingTime;
                minRemainingTimePid = processes[i].pid;
            }
        }

        if (minRemainingTimePid == -1)
            break;

        numProcesses--;
        printf("Process %d has been switched.\n", minRemainingTimePid);

        processes[minRemainingTimePid].remainingTime -= TIME_QUANTUM;
        processes[minRemainingTimePid].remainingTime = processes[minRemainingTimePid].remainingTime > TIME_QUANTUM? processes[minRemainingTimePid].remainingTime - TIME_QUANTUM : 0;

        if (processes[minRemainingTimePid].remainingTime == 0)
        {
            processes[minRemainingTimePid].remainingTime = processes[minRemainingTimePid].burstTime;
            processes[minRemainingTimePid].remainingTime = processes[minRemainingTimePid].remainingTime > TIME_QUANTUM? processes[minRemainingTimePid].remainingTime - TIME_QUANTUM : 0;
        }

        for (i = 0; i < numProcesses; i++)
        {
            if (processes[i].pid!= minRemainingTimePid)
            {
                if (processes[i].remainingTime > 0)
                {
                    processes[i].remainingTime -= TIME_QUANTUM;
                    processes[i].remainingTime = processes[i].remainingTime > TIME_QUANTUM? processes[i].remainingTime - TIME_QUANTUM : 0;
                }
            }
        }
    }

    end = clock();
    printf("Time elapsed: %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}