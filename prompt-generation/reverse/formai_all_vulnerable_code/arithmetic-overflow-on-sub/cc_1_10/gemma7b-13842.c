//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 10
#define MAX_QUEUE_SIZE 5

typedef struct Process
{
    int process_id;
    char name[20];
    int arrival_time;
    int burst_time;
    int remaining_time;
    int status;
} Process;

void roundrobin(Process **processes, int *quantum)
{
    int i = 0;
    int current_time = 0;
    int completed = 0;

    while (!completed)
    {
        for (i = 0; i < MAX_PROCESS; i++)
        {
            if (processes[i]->remaining_time > 0 && processes[i]->arrival_time <= current_time)
            {
                processes[i]->remaining_time--;
                current_time++;

                if (processes[i]->remaining_time == 0)
                {
                    processes[i]->status = 2;
                    completed++;
                }
            }
        }

        *quantum++;
    }
}

int main()
{
    Process processes[MAX_PROCESS];
    int quantum = 0;

    // Create and initialize processes
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        processes[i].process_id = i;
        processes[i].arrival_time = rand() % MAX_QUEUE_SIZE;
        processes[i].burst_time = rand() % MAX_QUEUE_SIZE;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].status = 0;
    }

    // Round robin scheduling
    roundrobin(processes, &quantum);

    // Print completed processes
    printf("Completed processes:\n");
    for (int i = 0; i < MAX_PROCESS; i++)
    {
        if (processes[i].status == 2)
        {
            printf("Process ID: %d, Name: %s\n", processes[i].process_id, processes[i].name);
        }
    }

    printf("Total quantum: %d\n", quantum);

    return 0;
}