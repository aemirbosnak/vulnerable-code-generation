//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

struct process
{
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

// Function to perform FCFS scheduling
void fcfs_scheduling(struct process *p, int n)
{
    int time = 0;
    for(int i=0; i<n; i++)
    {
        // Calculate completion time of each process
        if(time < p[i].arrival_time)
            time = p[i].arrival_time;
        p[i].completion_time = time + p[i].burst_time;
        time = p[i].completion_time;
        
        // Calculate waiting time and turnaround time of each process
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
}

// Function to perform Round Robin scheduling
void round_robin_scheduling(struct process *p, int n, int quantum)
{
    int time = 0, i, flag = 0;
    int remaining_time[n];
    int waiting_time_total = 0, turnaround_time_total = 0;
    for(i=0; i<n; i++)
        remaining_time[i] = p[i].burst_time;
    while(1)
    {
        flag = 0;
        for(i=0; i<n; i++)
        {
            if(remaining_time[i] > 0)
            {
                flag = 1;
                if(remaining_time[i] > quantum)
                {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
                else
                {
                    time += remaining_time[i];
                    p[i].completion_time = time;
                    remaining_time[i] = 0;
                    
                    // Calculate waiting time and turnaround time of each process
                    p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
                    p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
                    
                    // Calculate total waiting time and turnaround time for average time calculation
                    waiting_time_total += p[i].waiting_time;
                    turnaround_time_total += p[i].turnaround_time;
                }
            }
        }
        if(flag == 0)
            break;
    }
    
    // Calculate average waiting time and average turnaround time
    float avg_waiting_time = (float)waiting_time_total/n;
    float avg_turnaround_time = (float)turnaround_time_total/n;
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f", avg_turnaround_time);
}

int main()
{
    int n, choice, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    for(int i=0; i<n; i++)
    {
        printf("\nFor process %d,\n", i+1);
        p[i].pid = i+1;
        printf("Enter arrival time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Enter burst time: ");
        scanf("%d", &p[i].burst_time);
    }
    printf("\nChoose the scheduling algorithm:\n1. FCFS Scheduling\n2. Round Robin Scheduling\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1: fcfs_scheduling(p, n);
                printf("\nFCFS Scheduling\n");
                for(int i=0; i<n; i++)
                {
                    printf("\nProcess %d", p[i].pid);
                    printf("\nCompletion time: %d", p[i].completion_time);
                    printf("\nWaiting time: %d", p[i].waiting_time);
                    printf("\nTurnaround time: %d", p[i].turnaround_time);
                }
                break;
        case 2: printf("\nEnter quantum time: ");
                scanf("%d", &quantum);
                round_robin_scheduling(p, n, quantum);
                break;
        default: printf("\nInvalid choice!");
    }
    return 0;
}