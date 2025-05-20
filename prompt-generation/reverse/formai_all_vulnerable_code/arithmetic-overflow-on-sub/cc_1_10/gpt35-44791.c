//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: detailed
#include<stdio.h>

int main()
{
    //Declaring variables
    int n,i,j;
    float atat=0,awt=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int p[n],bt[n],ct[n],tat[n],wt[n];
    int max;
    float sumt=0,sumw=0;
    printf("Enter the burst time of the processes: ");
    //Taking input of burst time from user
    for(i=0;i<n;i++)
    {
        printf("\nProcess[%d]: ",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    //Sorting the burst time in ascending order
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                int temp1=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp1;
                int temp2=p[j];
                p[j]=p[j+1];
                p[j+1]=temp2;
            }
        }
    }
    ct[0]=bt[0];
    tat[0]=ct[0];
    wt[0]=0;
    //Calculating completion time and turnaround time
    for(i=1;i<n;i++)
    {
        ct[i]=ct[i-1]+bt[i];
        tat[i]=ct[i];
    }
    //Calculating average turnaround time and waiting time
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        sumt=sumt+tat[i];
        sumw=sumw+wt[i];
    }
    atat=sumt/n;
    awt=sumw/n;
    printf("\n");
    //Printing the output
    printf("Process\tBurst Time\tCompletion Time\t  Turnaround Time\tWaiting Time\n");
    for(i=0;i<n;i++)
    {
        printf(" P%d\t\t%d\t\t%d\t\t  %d\t\t\t%d\n",p[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Turnaround Time: %0.2f\nAverage Waiting Time: %0.2f\n",atat,awt);
    return 0;
}