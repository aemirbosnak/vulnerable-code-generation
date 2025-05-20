//Falcon-180B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100

struct process
{
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

void FCFS(struct process pro[], int n)
{
    int i, j, comp=0, temp;
    for(i=0;i<n;i++)
    {
        printf("\nProcess %d arrived at time %d",pro[i].pid,pro[i].burst_time);
        for(j=0;j<i;j++)
        {
            if(pro[i].burst_time<=pro[j].burst_time)
            {
                temp=pro[i].burst_time;
                pro[i].burst_time=pro[j].burst_time;
                pro[j].burst_time=temp;
            }
        }
        if(comp==0)
        {
            printf("\nProcess %d is executing",pro[i].pid);
            pro[i].waiting_time=0;
            pro[i].turnaround_time=pro[i].burst_time;
        }
        else
        {
            printf("\nProcess %d is in ready queue",pro[i].pid);
            pro[i].waiting_time=pro[i-1].turnaround_time;
            pro[i].turnaround_time=pro[i].waiting_time+pro[i].burst_time;
        }
        comp=1;
    }
    printf("\nGantt chart:\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess %d\t",pro[i].pid);
        for(j=pro[i].burst_time;j>0;j--)
        {
            printf("*\t");
        }
        printf("\n");
    }
}

int main()
{
    int n, i, j;
    struct process pro[MAX];

    printf("\nEnter the number of processes: ");
    scanf("%d",&n);

    printf("\nEnter the details of %d processes:\n",n);

    for(i=0;i<n;i++)
    {
        printf("\nFor process %d:\n",i+1);
        printf("Enter the process id: ");
        scanf("%d",&pro[i].pid);
        printf("Enter the burst time: ");
        scanf("%d",&pro[i].burst_time);
    }

    FCFS(pro,n);

    return 0;
}