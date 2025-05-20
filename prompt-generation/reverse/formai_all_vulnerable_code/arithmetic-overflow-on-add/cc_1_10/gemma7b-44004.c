//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESS 5
#define MAX_QUEUE_SIZE 10

typedef struct Process
{
    int process_id;
    char name[20];
    int arrival_time;
    int service_time;
    int completion_time;
    int waiting_time;
    int turn_around_time;
} Process;

void create_process(Process *process)
{
    process->process_id = process->process_id + 1;
    process->arrival_time = rand() % MAX_QUEUE_SIZE;
    process->service_time = rand() % MAX_QUEUE_SIZE;
    process->completion_time = 0;
    process->waiting_time = 0;
    process->turn_around_time = 0;
}

void calculate_completion_time(Process *process)
{
    process->completion_time = process->arrival_time + process->service_time;
}

void calculate_waiting_time(Process *process)
{
    process->waiting_time = process->arrival_time - process->completion_time;
}

void calculate_turn_around_time(Process *process)
{
    process->turn_around_time = process->waiting_time + process->service_time;
}

int main()
{
    Process processes[MAX_PROCESS];
    int i;

    // Create processes
    for (i = 0; i < MAX_PROCESS; i++)
    {
        create_process(&processes[i]);
    }

    // Calculate completion time for each process
    for (i = 0; i < MAX_PROCESS; i++)
    {
        calculate_completion_time(&processes[i]);
    }

    // Calculate waiting time for each process
    for (i = 0; i < MAX_PROCESS; i++)
    {
        calculate_waiting_time(&processes[i]);
    }

    // Calculate turn-around time for each process
    for (i = 0; i < MAX_PROCESS; i++)
    {
        calculate_turn_around_time(&processes[i]);
    }

    // Print process details
    for (i = 0; i < MAX_PROCESS; i++)
    {
        printf("Process ID: %d\n", processes[i].process_id);
        printf("Arrival Time: %d\n", processes[i].arrival_time);
        printf("Service Time: %d\n", processes[i].service_time);
        printf("Completion Time: %d\n", processes[i].completion_time);
        printf("Waiting Time: %d\n", processes[i].waiting_time);
        printf("Turn-around Time: %d\n", processes[i].turn_around_time);
        printf("\n");
    }

    return 0;
}