//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void main()
{
    int i, n, quantum, ready, waiting, completed = 0, time = 0;
    char name[MAX][20];
    int priority[MAX], burst[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", name[i]);

        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &priority[i]);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &burst[i]);
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    while (!completed)
    {
        time++;
        ready = 0;
        for (i = 0; i < n; i++)
        {
            if (priority[i] == time && burst[i] > 0)
            {
                ready++;
                burst[i]--;
            }
        }

        if (ready > 0)
        {
            waiting = n - ready;
            printf("Time: %d, Processes in Ready Queue: %d, Processes Waiting: %d\n", time, ready, waiting);
        }

        if (ready == n)
        {
            completed = 1;
            printf("All processes completed!\n");
        }
    }

    return;
}