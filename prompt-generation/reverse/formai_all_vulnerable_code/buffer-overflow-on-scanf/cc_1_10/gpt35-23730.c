//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include<stdio.h>
struct info
{
    char pname[10];
    int at, bt, wt, tat, status;
}p[10];

void roundRobin()
{
    int i, j, t, q, n, count = 0, tq = 4;
    float awt = 0, atat = 0;
    printf("\nEnter number of processes: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("\nEnter Process Name: ");
        scanf("%s", &p[i].pname);
        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);
        p[i].status = 0;
        p[i].wt = 0;
        p[i].tat = 0;
    }

    //implementing round robin algorithm
    printf("\n\nProcess\t|Turnaround Time\t|Waiting Time\n");
    printf("-------------------------------------------------\n");
    for(t=0; count!=n; )
    {
        for(i=0; i<n; i++)
        {
            if(p[i].at<=t && p[i].status==0)
            {
                p[i].wt = p[i].wt + (t - p[i].tat);
                t = t + tq;
                p[i].tat = t - p[i].at;
                p[i].status = 1;
                printf("%s\t|\t%d\t|\t%d\n", p[i].pname, p[i].tat, p[i].wt);
                count++;
            }
        }
    }
    for(i=0; i<n; i++)
    {
        awt = awt + p[i].wt;
        atat = atat + p[i].tat;
    }

    printf("\nAverage Waiting Time : %f", (awt/n));
    printf("\nAverage Turnaround Time : %f", (atat/n));
}

void main()
{
    printf("\n----------------------------------------\n");
    printf("CPU Scheduling Algorithm - Round Robin\n");
    printf("----------------------------------------\n");
    roundRobin();
}