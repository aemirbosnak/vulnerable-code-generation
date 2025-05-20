//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_PROCESS 10

typedef struct Process {
    int process_id;
    char name[20];
    int burst_time;
    int waiting_time;
    int turn_around_time;
} Process;

void round_robin(Process processes[], int n)
{
    int i = 0;
    int current_process = 0;
    int time_quantum = 5;

    while (i < n)
    {
        processes[current_process].waiting_time--;
        if (processes[current_process].waiting_time == 0)
        {
            processes[current_process].turn_around_time = time_quantum + processes[current_process].burst_time;
            printf("Process %d (%s) completed.\n", processes[current_process].process_id, processes[current_process].name);
            current_process = (current_process + 1) % n;
        }
        else
        {
            sleep(time_quantum);
            current_process = (current_process + 1) % n;
        }
        i++;
    }
}

int main()
{
    Process processes[MAX_PROCESS];

    // Create processes
    processes[0].process_id = 1;
    strcpy(processes[0].name, "Process A");
    processes[0].burst_time = 8;

    processes[1].process_id = 2;
    strcpy(processes[1].name, "Process B");
    processes[1].burst_time = 12;

    processes[2].process_id = 3;
    strcpy(processes[2].name, "Process C");
    processes[2].burst_time = 6;

    round_robin(processes, 3);

    return 0;
}