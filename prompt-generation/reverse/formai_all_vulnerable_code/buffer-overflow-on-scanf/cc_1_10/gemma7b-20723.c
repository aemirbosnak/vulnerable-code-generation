//Gemma-7B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void roundrobin(int n, int **ready, int **wait, int **complete)
{
    int i, j, k, time = 0, completed = 0;

    for (i = 0; i < n; i++)
    {
        wait[i] = 0;
    }

    while (completed < n)
    {
        for (i = 0; i < n; i++)
        {
            if (ready[i] && time >= ready[i])
            {
                completed++;
                complete[i] = time;
                ready[i] = 0;
            }
        }

        time++;
    }
}

int main()
{
    int n, i, j, ready[MAX], wait[MAX], complete[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the arrival time of process %d: ", i + 1);
        scanf("%d", &ready[i]);

        printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &wait[i]);
    }

    roundrobin(n, ready, wait, complete);

    printf("Process ID\tArrival Time\tCompletion Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, ready[i], complete[i], wait[i]);
    }

    return 0;
}