//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct process
{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct process *processes, int n)
{
    int i, j, comp = 0, index = 0;
    int sum_wt = 0, sum_tat = 0;
    int avg_wt = 0, avg_tat = 0;
    float avg_rt = 0;

    for (i = 0; i < n; i++)
    {
        if (processes[i].burst_time > 0)
        {
            comp++;
            sum_wt += processes[i].waiting_time;
            sum_tat += processes[i].turnaround_time;
        }
    }

    if (comp > 0)
    {
        avg_wt = (float)sum_wt / comp;
        avg_tat = (float)sum_tat / comp;
        avg_rt = avg_tat / processes[0].burst_time;
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < n; i++)
    {
        if (processes[i].burst_time > 0)
        {
            printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
        }
    }

    printf("\nGantt Chart\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < processes[i].burst_time; j++)
        {
            if (processes[i].burst_time > 0)
            {
                printf("P%d ", processes[i].pid);
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("\nAverage Waiting Time: %d\n", avg_wt);
    printf("Average Turnaround Time: %d\n", avg_tat);
    printf("Average Response Time: %f\n", avg_rt);
}

int main()
{
    int i, n;
    struct process processes[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the details of %d processes:\n", n);

    for (i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i+1);
        printf("Enter the process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter the burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    FCFS(processes, n);

    return 0;
}