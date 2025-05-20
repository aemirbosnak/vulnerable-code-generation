//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PROCESSES 5
#define MAX_QUEUE_SIZE 10

typedef struct Process
{
    int process_id;
    char name[20];
    int arrival_time;
    int service_time;
    int completion_time;
    int status;
} Process;

void initialize_processes(Process *processes)
{
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        processes[i].process_id = i + 1;
        processes[i].status = 0;
    }
}

void simulate_arrival(Process *processes)
{
    int arrival_time = rand() % MAX_QUEUE_SIZE;
    processes[0].arrival_time = arrival_time;
}

void calculate_completion_time(Process *processes)
{
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        processes[i].completion_time = processes[i].arrival_time + processes[i].service_time;
    }
}

void print_processes(Process *processes)
{
    for (int i = 0; i < MAX_PROCESSES; i++)
    {
        printf("Process ID: %d, Name: %s, Arrival Time: %d, Service Time: %d, Completion Time: %d, Status: %d\n", processes[i].process_id, processes[i].name, processes[i].arrival_time, processes[i].service_time, processes[i].completion_time, processes[i].status);
    }
}

int main()
{
    Process processes[MAX_PROCESSES];
    initialize_processes(processes);
    simulate_arrival(processes);
    calculate_completion_time(processes);
    print_processes(processes);

    return 0;
}