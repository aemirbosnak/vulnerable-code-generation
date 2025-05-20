//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: automated
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    int burst_time[n];
    int process_id[n];
    int arrival_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    int completion_time[n];
    int time_quantum;
    int remaining_processes = n;
    int time = 0;
    int i,j;
    int flag = 0;
    
    for(i=0;i<n;i++)
    {
        printf("\nEnter the Process ID for process %d: ",i+1);
        scanf("%d",&process_id[i]);
        printf("Enter the arrival time for process %d: ",i+1);
        scanf("%d",&arrival_time[i]);
        printf("Enter the burst time for process %d: ",i+1);
        scanf("%d",&burst_time[i]);
        printf("-------------------------------\n");
    }
    
    printf("\nEnter the time slice for Round Robin Scheduling: ");
    scanf("%d",&time_quantum);
    
    int remaining_burst_time[n];
    for(i=0;i<n;i++)
        remaining_burst_time[i] = burst_time[i];
    
    while(remaining_processes!=0)
    {
        for(i=0;i<n;i++)
        {
            if(remaining_burst_time[i]>0)
            {
                flag = 1;
                if(remaining_burst_time[i]>time_quantum)
                {
                    time += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                }
                else
                {
                    time += remaining_burst_time[i];
                    completion_time[i] = time;
                    remaining_burst_time[i] = 0;
                    remaining_processes--;
                }
            }
        }
        if(flag == 0)
            time++;
        flag = 0;
    }
    
    for(i=0;i<n;i++)
    {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
    
    float avg_waiting_time=0;
    float avg_turnaround_time=0;
    for(i=0;i<n;i++)
    {
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    avg_waiting_time /= n;
    avg_turnaround_time /= n;
    
    printf("\nProcess ID \t Arrival Time \t Burst Time \t Completion Time \t Waiting Time \t Turnaround Time\n");
    for(i=0;i<n;i++)
    {
        printf("%d \t \t %d \t \t %d \t \t %d \t \t\t %d \t \t %d\n",process_id[i],arrival_time[i],burst_time[i],completion_time[i],waiting_time[i],turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %f\n",avg_waiting_time);
    printf("Average Turnaround Time: %f\n",avg_turnaround_time);
    return 0;
}