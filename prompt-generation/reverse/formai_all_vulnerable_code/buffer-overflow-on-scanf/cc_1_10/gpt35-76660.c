//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mind-bending
#include<stdio.h>
int main()
{
    int processes[10], burst_time[10], waiting_time[10], turnaround_time[10], completion_time[10];
    int i, j, num_processes, quantum, total_time=0, flag=0, burst_time_cpy[10];
    float avg_waiting_time=0, avg_turnaround_time=0;
    
    printf("Enter the number of processes: ");
    scanf("%d",&num_processes);
    
    printf("\nEnter the burst time for each process:\n");
    for(i=0;i<num_processes;i++)
    {
        printf("P[%d] : ", i+1);
        scanf("%d", &burst_time[i]);
        burst_time_cpy[i] = burst_time[i];
        processes[i] = i+1;
    }
    
    printf("\nEnter the time quantum : ");
    scanf("%d", &quantum);
    
    while(1)
    {
        flag = 0;
        
        for(i=0;i<num_processes;i++)
        {
            if(burst_time_cpy[i] > 0)
            {
                flag = 1;
                
                if(burst_time_cpy[i] > quantum)
                {
                    total_time += quantum;
                    burst_time_cpy[i] -= quantum;
                }
                else
                {
                    total_time += burst_time_cpy[i];
                    turnaround_time[i] = total_time;
                    waiting_time[i] = turnaround_time[i] - burst_time[i];
                    
                    completion_time[i] = total_time;
                    burst_time_cpy[i] = 0;
                }
            }
        }
        
        if(flag == 0)
            break;
    }
    
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\tCompletion Time\n");
    for(i=0;i<num_processes;i++)
    {
        printf("P[%d]\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i], completion_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    printf("\nAverage Waiting Time : %.2f", (avg_waiting_time/num_processes));
    printf("\nAverage Turnaround Time : %.2f", (avg_turnaround_time/num_processes));
    
    return 0;
}