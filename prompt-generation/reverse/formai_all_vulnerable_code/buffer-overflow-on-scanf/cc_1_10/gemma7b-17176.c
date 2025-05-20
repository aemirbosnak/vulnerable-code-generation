//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

void main()
{
    int i, j, n, quantum, readyQueue[MAX], processQueue[MAX], completed[MAX];
    time_t start, end;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("Enter the quantum time:");
    scanf("%d", &quantum);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d:", i + 1);
        scanf("%d", &readyQueue[i]);

        printf("Enter the burst time of process %d:", i + 1);
        scanf("%d", &processQueue[i]);
    }

    start = time(NULL);

    for (i = 0; i < n; i++)
    {
        completed[i] = 0;

        if (readyQueue[i] == 0)
        {
            readyQueue[i] = time(NULL) + quantum;
        }

        while (completed[i] == 0 && readyQueue[i] <= time(NULL))
        {
            completed[i] = 1;
            printf("Process %d is completed.\n", i + 1);
        }
    }

    end = time(NULL);

    printf("Total time elapsed: %ld seconds\n", end - start);

    return;
}