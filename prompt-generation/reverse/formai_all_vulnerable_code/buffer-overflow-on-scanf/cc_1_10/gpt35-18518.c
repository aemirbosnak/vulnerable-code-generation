//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

struct Process{
    int burst;
    int priority;
    int arrival;
    char name[10];
    int completion;
    int turnaround;
    int waiting;
};

void FCFS_Scheduling(struct Process proc[], int n)
{
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];
    int total_waiting_time=0;
    int total_turnaround_time=0;
    for(int i=0;i<n;i++)
    {
         if(i==0)
        {
            completion_time[i]=proc[i].arrival+proc[i].burst;
        }
        else
        {
             if(proc[i].arrival>completion_time[i-1])
                completion_time[i]=proc[i].arrival+proc[i].burst;
             else
                completion_time[i]=completion_time[i-1]+proc[i].burst;
        }
        turnaround_time[i]=completion_time[i]-proc[i].arrival;
        waiting_time[i]=turnaround_time[i]-proc[i].burst;
        total_waiting_time+=waiting_time[i];
        total_turnaround_time+=turnaround_time[i];
        proc[i].completion=completion_time[i];
        proc[i].turnaround=turnaround_time[i];
        proc[i].waiting=waiting_time[i];
    }
    printf("Name\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\n",proc[i].name,proc[i].waiting,proc[i].turnaround,proc[i].completion);
    }
    printf("Average waiting time:%f\nAverage turnaround time:%f",(float)total_waiting_time/n,(float)total_turnaround_time/n);
}

void Priority_Scheduling(struct Process proc[], int n)
{
    int total_waiting_time=0,total_turnaround_time=0;
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];
    for(int i=0;i<n;i++)
    {
        int max_priority=i;
        for(int j=i;j<n;j++)
        {
            if(proc[j].arrival<=completion_time[i])
            {    
                if(proc[max_priority].priority>proc[j].priority)
                        max_priority=j;
            } 
            else
                break;
        }
        completion_time[max_priority]=completion_time[i]+proc[max_priority].burst;
        turnaround_time[max_priority]=completion_time[max_priority]-proc[max_priority].arrival;
        waiting_time[max_priority]=turnaround_time[max_priority]-proc[max_priority].burst;
        total_waiting_time+=waiting_time[max_priority];
        total_turnaround_time+=turnaround_time[max_priority];
        proc[max_priority].completion=completion_time[max_priority];
        proc[max_priority].turnaround=turnaround_time[max_priority];
        proc[max_priority].waiting=waiting_time[max_priority];
        struct Process temp=proc[i];
        proc[i]=proc[max_priority];
        proc[max_priority]=temp;
    }
    printf("Name\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\n",proc[i].name,proc[i].waiting,proc[i].turnaround,proc[i].completion);
    }
    printf("Average waiting time:%f\nAverage turnaround time:%f",(float)total_waiting_time/n,(float)total_turnaround_time/n);
}

void SJF_Scheduling(struct Process proc[], int n)
{
    int total_waiting_time=0,total_turnaround_time=0;
    int completion_time[n];
    int turnaround_time[n];
    int waiting_time[n];
    for(int i=0;i<n;i++)
    {
        int index=i;
        for(int j=i+1;j<n;j++)
        {
            if(proc[j].arrival<=completion_time[i])
            {
                if(proc[index].burst>proc[j].burst)
                    index=j;    
            } 
            else
                break;
        }
        completion_time[index]=completion_time[i]+proc[index].burst;
        turnaround_time[index]=completion_time[index]-proc[index].arrival;
        waiting_time[index]=turnaround_time[index]-proc[index].burst;
        total_waiting_time+=waiting_time[index];
        total_turnaround_time+=turnaround_time[index];
        proc[index].completion=completion_time[index];
        proc[index].turnaround=turnaround_time[index];
        proc[index].waiting=waiting_time[index];
        struct Process temp=proc[i];
        proc[i]=proc[index];
        proc[index]=temp;
    }
    printf("Name\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\n",proc[i].name,proc[i].waiting,proc[i].turnaround,proc[i].completion);
    }
    printf("Average waiting time:%f\nAverage turnaround time:%f",(float)total_waiting_time/n,(float)total_turnaround_time/n);
}

void main()
{
    int n;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    struct Process proc[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter name of the process %d:",i+1);
        scanf("%s",&proc[i].name);
        printf("Enter the arrival time of the process %d:",i+1);
        scanf("%d",&proc[i].arrival);
        printf("Enter the burst time of the process %d:",i+1);
        scanf("%d",&proc[i].burst);
        printf("Enter the priority of the process %d:",i+1);
        scanf("%d",&proc[i].priority);
    }
    printf("\nFCFS Scheduling\n");
    FCFS_Scheduling(proc,n);
    printf("\nPriority Scheduling\n");
    Priority_Scheduling(proc,n);
    printf("\nSJF Scheduling\n");
    SJF_Scheduling(proc,n);
}