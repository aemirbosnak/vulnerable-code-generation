//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: light-weight
#include<stdio.h>

void main()
{
    int p[20], bt[20], wt[20], tat[20], pr[20], i, j, n, total=0, pos, temp;
    float avg_wt, avg_tat;
    
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    
    printf("\nEnter the burst time and priority of the processes:\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n", i+1);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);
        p[i] = i+1;
    }
    
    //Sorting the processes according to priority
    for(i=0;i<n-1;i++)
    {
        pos = i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos = j;
        }
        
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    
    wt[0] = 0;
    
    //Calculating waiting time for each process
    for(i=1;i<n;i++)
    {
        wt[i] = 0;
        for(j=0;j<i;j++)
            wt[i] += bt[j];
            
        total += wt[i];
    }
    
    avg_wt = (float)total/n;
    total = 0;
    
    printf("\nProcess\t Burst Time\t Waiting Time\t Turnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\nP[%d]\t\t %d\t\t %d\t\t %d",p[i],bt[i],wt[i],tat[i]);
    }
    
    avg_tat = (float)total/n;
    
    printf("\n\nAverage Waiting Time: %f",avg_wt);
    printf("\nAverage Turnaround Time: %f\n",avg_tat);
}