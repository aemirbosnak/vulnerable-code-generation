//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define INIT_TIME 0
#define MIN_QUANTUM 5

struct process
{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void execute(struct process *queue, int n, int quantum)
{
    int completed_process = 0, temp_wt = 0, temp_tat = 0;
    int current_time = INIT_TIME;

    while(completed_process < n)
    {
        for(int i=0; i<n; i++)
        {
            if(queue[i].burst_time > 0 && queue[i].waiting_time <= current_time)
            {
                if(queue[i].burst_time > quantum)
                {
                    queue[i].burst_time -= quantum;
                    current_time += quantum;
                    temp_wt += quantum;
                }
                else
                {
                    queue[i].burst_time = 0;
                    temp_wt += queue[i].burst_time;
                    temp_tat += queue[i].turnaround_time = current_time - queue[i].waiting_time - queue[i].burst_time;
                    completed_process++;
                }
            }
            else if(queue[i].burst_time > 0)
            {
                queue[i].waiting_time = current_time;
            }
        }
        current_time += MIN_QUANTUM;
    }

    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", queue[i].pid, queue[i].burst_time, queue[i].waiting_time, queue[i].turnaround_time);
    }
}

void main()
{
    struct process queue[MAX];
    int n, quantum, i, j;

    printf("\nEnter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter process details:\n");
    for(i=0; i<n; i++)
    {
        printf("\nFor Process %d:\n", i+1);
        printf("Enter Process ID: ");
        scanf("%d", &queue[i].pid);
        printf("Enter Burst Time: ");
        scanf("%d", &queue[i].burst_time);
    }

    printf("\nEnter time quantum: ");
    scanf("%d", &quantum);

    execute(queue, n, quantum);
}