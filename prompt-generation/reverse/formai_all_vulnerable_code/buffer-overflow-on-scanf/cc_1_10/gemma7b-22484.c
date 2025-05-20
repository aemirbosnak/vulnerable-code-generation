//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main()
{
    int i, j, n, quantum, ready_queue[MAX], process_queue[MAX], state[MAX], completed = 0;
    char name[MAX][20];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of process %d: ", i + 1);
        scanf("%s", name[i]);

        printf("Enter the CPU burst time of process %d: ", i + 1);
        scanf("%d", &process_queue[i]);

        printf("Enter the priority of process %d: ", i + 1);
        scanf("%d", &ready_queue[i]);
    }

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++)
    {
        state[i] = 0;
    }

    while (!completed)
    {
        for (i = 0; i < n; i++)
        {
            if (state[i] == 0 && ready_queue[i] > 0)
            {
                state[i] = 1;
                ready_queue[i] -= quantum;
                completed++;
            }
        }
    }

    printf("The processes are completed.\n");

    for (i = 0; i < n; i++)
    {
        printf("The name of process %d is: %s\n", i + 1, name[i]);
    }

    return;
}