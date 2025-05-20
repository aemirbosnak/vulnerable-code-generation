//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void scheduler()
{
    int i, j, quantum = 0, ready_queue[MAX], process_queue[MAX], state[MAX] = {0, 0, 0, 0, 0};
    char name[MAX][20] = {"Romeo", "Juliet", "Ben", "Mercutio", "Tybalt"};

    for (i = 0; i < MAX; i++)
    {
        process_queue[i] = -1;
    }

    printf("Enter the number of processes: ");
    int no_processes = 0;
    scanf("%d", &no_processes);

    for (i = 0; i < no_processes; i++)
    {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", name[i]);

        printf("Enter the CPU burst time of process %d: ", i + 1);
        int burst_time = 0;
        scanf("%d", &burst_time);

        process_queue[i] = burst_time;
    }

    while (!ready_queue[0] && process_queue[0] != -1)
    {
        for (i = 0; i < MAX; i++)
        {
            if (process_queue[i] != -1 && state[i] == 0)
            {
                ready_queue[i] = 1;
                state[i] = 1;
            }
        }

        quantum++;

        for (i = 0; i < MAX; i++)
        {
            if (ready_queue[i] == 1)
            {
                process_queue[i]--;
                if (process_queue[i] == 0)
                {
                    state[i] = 0;
                }
            }
        }

        printf("Time quantum: %d\n", quantum);
    }

    printf("All processes have been scheduled.\n");
}

int main()
{
    scheduler();

    return 0;
}