//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

typedef struct process
{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
}Process;

void FCFS(Process *processes, int n)
{
    int i, j, sum = 0;
    for(i=0; i<n; i++)
    {
        printf("\nProcess %d started at time %d\n", processes[i].pid, sum);
        for(j=0; j<processes[i].burst_time; j++)
        {
            printf("\tCPU busy with Process %d at time %d\n", processes[i].pid, sum+j);
            sum += processes[i].burst_time;
        }
        printf("\nProcess %d completed at time %d\n", processes[i].pid, sum);
        processes[i].waiting_time = sum - processes[i].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        sum += processes[i].turnaround_time;
    }
}

int main()
{
    Process processes[MAX];
    int n, i, sum = 0;

    printf("\nEnter number of processes (max %d): ", MAX);
    scanf("%d", &n);

    printf("\nEnter process details:\n");
    for(i=0; i<n; i++)
    {
        printf("\nEnter process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Enter burst time: ");
        scanf("%d", &processes[i].burst_time);
    }

    FCFS(processes, n);

    return 0;
}