//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int processes[10],burst_time[10],waiting_time[10],turnaround_time[10],priority[10];
    int i,j,n,pos,temp,sum_waiting_time=0,sum_turnaround_time=0;
    float avg_waiting_time,avg_turnaround_time;
    printf("Enter no. of processes:");
    scanf("%d",&n);

    printf("\nEnter Burst Time for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("Burst Time of Process %d:",i+1);
        scanf("%d",&burst_time[i]);
        processes[i]=i+1; //storing process ids in array
    }

    printf("\nEnter Priority for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("Priority of Process %d:",i+1);
        scanf("%d",&priority[i]);
    }

    //sorting based on priority
    for(i=0;i<n-1;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
            {
                pos=j;
            }
        }
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=processes[i];
        processes[i]=processes[pos];
        processes[pos]=temp;
    }

    //calculating waiting time and turnaround time
    waiting_time[0]=0; //waiting time for first process is 0
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
        {
            waiting_time[i]+=burst_time[j];
        }
        sum_waiting_time+=waiting_time[i];
    }

    for(i=0;i<n;i++)
    {
        turnaround_time[i]=burst_time[i]+waiting_time[i];
        sum_turnaround_time+=turnaround_time[i];
    }

    avg_waiting_time=(float)sum_waiting_time/n;
    avg_turnaround_time=(float)sum_turnaround_time/n;

    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d",processes[i],burst_time[i],priority[i],waiting_time[i],turnaround_time[i]);
    }

    printf("\n\nAverage Waiting Time=%.2f",avg_waiting_time);
    printf("\nAverage Turnaround Time=%.2f",avg_turnaround_time);

    return 0;
}