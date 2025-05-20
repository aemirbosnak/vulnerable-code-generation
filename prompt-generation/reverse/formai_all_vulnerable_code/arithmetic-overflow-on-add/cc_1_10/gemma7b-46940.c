//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5

typedef struct process
{
    int pid;
    char name[20];
    int burst_time;
    int waiting_time;
    int turn_around_time;
} process;

void round_robin(process *processes, int quantum)
{
    int i = 0;
    processes[i].waiting_time = 0;
    processes[i].turn_around_time = processes[i].burst_time;

    while (i < MAX_PROCESS - 1)
    {
        int time_quantum = quantum;
        processes[i].waiting_time++;

        if (processes[i].waiting_time >= processes[i].burst_time)
        {
            processes[i].waiting_time = processes[i].burst_time;
            processes[i].turn_around_time = time_quantum + processes[i].burst_time;

            i++;
            if (i == MAX_PROCESS - 1)
                i = 0;
        }
    }
}

int main()
{
    process processes[MAX_PROCESS];
    int quantum = 3;

    // Create processes
    processes[0].pid = 1;
    strcpy(processes[0].name, "Process A");
    processes[0].burst_time = 5;

    processes[1].pid = 2;
    strcpy(processes[1].name, "Process B");
    processes[1].burst_time = 8;

    processes[2].pid = 3;
    strcpy(processes[2].name, "Process C");
    processes[2].burst_time = 2;

    processes[3].pid = 4;
    strcpy(processes[3].name, "Process D");
    processes[3].burst_time = 4;

    processes[4].pid = 5;
    strcpy(processes[4].name, "Process E");
    processes[4].burst_time = 6;

    round_robin(processes, quantum);

    // Print results
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        printf("Process: %s, Waiting Time: %d, Turnaround Time: %d\n", processes[i].name, processes[i].waiting_time, processes[i].turn_around_time);
    }

    return 0;
}