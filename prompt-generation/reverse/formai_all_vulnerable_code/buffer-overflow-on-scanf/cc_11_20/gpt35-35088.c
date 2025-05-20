//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n=0;
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    int arrival[n],burst[n],priority[n],timeQuantum;
    printf("\nEnter the Arrival Time, Burst Time, and Priority of the Processes:\n");
    for(int i=0;i<n;i++){
        printf("\nFor Process %d:\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&arrival[i]);
        printf("Burst Time: ");
        scanf("%d",&burst[i]);
        printf("Priority: ");
        scanf("%d",&priority[i]);
    }
    printf("\nEnter the time quantum: ");
    scanf("%d",&timeQuantum);

    int complete[n],turnaround[n],waiting[n],c=0,time=0,minPriority,executingProcess=-1,currentTimeQuantum;
    float avgTurnaroundTime=0.0,avgWaitingTime=0.0;

    while(1)
    {
        minPriority=10000;
        for(int i=0;i<n;i++)
        {
            if(arrival[i]<=time && priority[i]<minPriority && complete[i]==0)
            {
                minPriority=priority[i];
                executingProcess=i;
            }
        }

        if(executingProcess==-1)
        {
            time++;
            continue;
        }

        currentTimeQuantum=timeQuantum;
        if(burst[executingProcess]<currentTimeQuantum)
            currentTimeQuantum=burst[executingProcess];

        burst[executingProcess]-=currentTimeQuantum;
        time+=currentTimeQuantum;

        if(burst[executingProcess]==0)
        {
            complete[executingProcess]=1;
            c++;
            turnaround[executingProcess]=time-arrival[executingProcess];
            waiting[executingProcess]=turnaround[executingProcess]-currentTimeQuantum;
            avgTurnaroundTime+=turnaround[executingProcess];
            avgWaitingTime+=waiting[executingProcess];
            executingProcess=-1;
        }

        if(c==n)
            break;
    }

    avgTurnaroundTime/=n;
    avgWaitingTime/=n;

    printf("\n\nFinal Results: ");
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tTAT Time\tWaiting Time\n");
    for(int i=0;i<n;i++)
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,arrival[i],burst[i]+currentTimeQuantum,priority[i],turnaround[i],waiting[i]);

    printf("\n\nAverage Turnaround Time: %0.2f", avgTurnaroundTime);
    printf("\nAverage Waiting Time: %0.2f", avgWaitingTime);

    return 0;
}