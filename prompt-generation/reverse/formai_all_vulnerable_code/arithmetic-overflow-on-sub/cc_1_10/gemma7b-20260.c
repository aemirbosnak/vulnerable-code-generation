//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void main()
{
    int i, j, n, quantum, readyQueue[MAX], processQueue[MAX], state[MAX] = {0}, time = 0, totalTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the quantum time: ");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &readyQueue[i]);

        printf("Enter the execution time of process %d: ", i + 1);
        scanf("%d", &processQueue[i]);
    }

    for (i = 0; i < n; i++)
    {
        state[i] = 0;
    }

    while (!state[n - 1] && time < totalTime)
    {
        time++;

        for (i = 0; i < n; i++)
        {
            if (state[i] == 0 && readyQueue[i] <= time)
            {
                state[i] = 1;
                readyQueue[i] = 0;
                processQueue[i]--;
            }
        }

        if (time % quantum == 0)
        {
            totalTime++;
        }
    }

    printf("The total time is: %d", totalTime);

    return;
}