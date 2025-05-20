//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include<stdio.h>
#define MAX 10

void fcfs(int n, int bt[MAX]);
void sjf(int n, int bt[MAX]);
void priority(int n, int bt[MAX], int p[MAX]);

int main()
{
    int choice, n, i, bt[MAX], p[MAX];
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the burst time for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("Process %d: ", i+1);
        scanf("%d",&bt[i]);
    }
    printf("\nSelect a scheduling algorithm:\n1. FCFS\n2. Shortest Job First\n3. Priority Scheduling\n");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: fcfs(n, bt);
                break;

        case 2: sjf(n, bt);
                break;

        case 3: printf("Enter the priority for each process:\n");
                for(i=0;i<n;i++)
                {
                    printf("Process %d: ", i+1);    
                    scanf("%d", &p[i]);
                }       
                priority(n, bt, p);
                break;

        default: printf("Invalid choice. Please select again.\n");
                 break;
    }
    return 0;
}

void fcfs(int n, int bt[MAX])
{
    int wt[MAX], tat[MAX], i;
    float avg_wt=0, avg_tat=0;
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }
    printf("\nFCFS Scheduling:\n");
    printf("Process  Burst Time  Waiting Time  Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        printf("   %d         %d           %d             %d\n",i+1,bt[i],wt[i],tat[i]);
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }
    avg_wt/=n;
    avg_tat/=n;
    printf("Average Waiting Time: %.2fms\n", avg_wt);
    printf("Average Turnaround Time: %.2fms\n", avg_tat);
}

void sjf(int n, int bt[MAX])
{
    int wt[MAX], tat[MAX], temp[MAX], total_wt=0, total_tat=0, i, j;
    float avg_wt, avg_tat;
    for(i=0;i<n;i++)
        temp[i]=bt[i];
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(temp[j]<temp[min])
                min=j;
        }
        int c=temp[i];
        temp[i]=temp[min];
        temp[min]=c;
        c=bt[i];
        bt[i]=bt[min];
        bt[min]=c;
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }
    printf("\nShortest Job First Scheduling:\n");
    printf("Process  Burst Time  Waiting Time  Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        printf("   %d         %d           %d             %d\n",i+1,bt[i],wt[i],tat[i]);
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    avg_wt=(float)total_wt/n;
    avg_tat=(float)total_tat/n;
    printf("Average Waiting Time: %.2fms\n", avg_wt);
    printf("Average Turnaround Time: %.2fms\n", avg_tat);
}

void priority(int n, int bt[MAX], int p[MAX])
{
    int wt[MAX], tat[MAX], temp[MAX], total_wt=0, total_tat=0, i, j;
    float avg_wt, avg_tat;
    for(i=0;i<n;i++)
        temp[i]=p[i];
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            if(temp[j]<temp[min])
                min=j;
        }
        int c=p[i];
        p[i]=p[min];
        p[min]=c;
        c=bt[i];
        bt[i]=bt[min];
        bt[min]=c;
    }
    wt[0]=0;
    tat[0]=bt[0];
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
        tat[i]=wt[i]+bt[i];
    }
    printf("\nPriority Scheduling:\n");
    printf("Process  Burst Time  Priority  Waiting Time  Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        printf("   %d         %d           %d             %d            %d\n",i+1,bt[i],p[i],wt[i],tat[i]);
        total_wt+=wt[i];
        total_tat+=tat[i];
    }
    avg_wt=(float)total_wt/n;
    avg_tat=(float)total_tat/n;
    printf("Average Waiting Time: %.2fms\n", avg_wt);
    printf("Average Turnaround Time: %.2fms\n", avg_tat);
}