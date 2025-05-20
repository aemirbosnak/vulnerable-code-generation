//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void scheduler()
{
    int i, j, quantum, total_processes, process_time, arrival_time, completion_time, waiting_time, turn_around_time;
    int processes[10], ready_queue[10], completed_processes[10];

    printf("Enter the total number of processes: ");
    scanf("%d", &total_processes);

    for (i = 0; i < total_processes; i++)
    {
        printf("Enter the process arrival time: ");
        scanf("%d", &arrival_time);

        printf("Enter the process execution time: ");
        scanf("%d", &process_time);

        processes[i] = arrival_time;
        waiting_time = process_time - quantum;
        turn_around_time = waiting_time + process_time;

        completed_processes[i] = 0;
        ready_queue[i] = 1;
    }

    quantum = 5;

    while (!completed_processes[total_processes - 1])
    {
        for (i = 0; i < total_processes; i++)
        {
            if (processes[i] <= quantum && ready_queue[i] && completed_processes[i] == 0)
            {
                completed_processes[i] = 1;
                ready_queue[i] = 0;
                completion_time = processes[i] + quantum;
                waiting_time = completion_time - processes[i];
                turn_around_time = waiting_time + process_time;

                printf("Process %d completed at time %d\n", i + 1, completion_time);
            }
        }

        quantum++;
    }

    printf("All processes completed.\n");

    return;
}

int main()
{
    scheduler();

    return 0;
}