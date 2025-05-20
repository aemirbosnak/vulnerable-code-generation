//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include<stdio.h>
void main()
{
    int i,j, n, temp, total_time=0, total_wt=0, total_tat=0, avg_wt, avg_tat;
    int process[25], burst_time[25], waiting_time[25], turn_around_time[25];
    printf("Enter total number of processes(maximum 25): ");
    scanf("%d",&n);
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&burst_time[i]);
        process[i]=i+1;          
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(burst_time[i]>burst_time[j])
            {
                temp=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }
    waiting_time[0]=0;            
    for(i=1;i<n;i++)
    {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total_time+=waiting_time[i];
    }
    avg_wt=total_time/n;        
    total_time=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turn_around_time[i]=burst_time[i]+waiting_time[i];    
        total_tat+=turn_around_time[i];
        printf("\nP[%d]\t\t %d\t\t   %d\t\t\t%d",process[i],burst_time[i],waiting_time[i],turn_around_time[i]);
    }
    avg_tat=total_tat/n;     
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
}