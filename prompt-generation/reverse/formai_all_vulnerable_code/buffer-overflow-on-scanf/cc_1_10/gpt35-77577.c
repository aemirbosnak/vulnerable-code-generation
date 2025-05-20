//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complete
#include <stdio.h>

int main()
{
    int n, i, j, pos, temp;
    float avg_wait = 0, avg_tat=0;
    int burst_time[10], process[10], waiting_time[10], turnaround_time[10];

    printf("Enter the number of processes:");
    scanf("%d",&n);

    printf("\nEnter burst time for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess %d:",i+1);
        scanf("%d",&burst_time[i]);
        process[i]=i+1;
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst_time[j]<burst_time[pos])
                pos=j;
        }

        temp=burst_time[i];
        burst_time[i]=burst_time[pos];
        burst_time[pos]=temp;

        temp=process[i];
        process[i]=process[pos];
        process[pos]=temp;
    }

    waiting_time[0]=0;

    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];

        avg_wait+=waiting_time[i];
    }

    avg_wait/=n;
    printf("\nAverage waiting time:%.2f",avg_wait);

    for(i=0;i<n;i++)
    {
        turnaround_time[i] = burst_time[i]+waiting_time[i];
        avg_tat+=turnaround_time[i];
    }

    avg_tat/=n;
    printf("\nAverage turnaround time:%.2f",avg_tat);

    return 0;
}