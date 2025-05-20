//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>

typedef struct Process
{
    int arrival_time;
    int burst_time;
    int pid;
}Process;

int main()
{
    int n, i;
    float total_wait_time = 0, total_turnaround_time = 0, avg_wait_time, avg_turnaround_time;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process *processes = (Process*)malloc(n*sizeof(Process));

    for(i=0; i<n; i++)
    {
        printf("\nEnter arrival time of process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);

        printf("Enter burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);

        processes[i].pid = i+1;
    }

    //Sort processes based on arrival time
    for(int i=0; i<n-1; i++)  
    {  
        for(int j=i+1; j<n; j++)  
        {   
            if(processes[i].arrival_time > processes[j].arrival_time)  
            {  
                Process temp = processes[i];  
                processes[i] = processes[j];  
                processes[j] = temp;  
            }  
        }  
    }  

    int *completion_time = (int*)malloc(n*sizeof(int));
    int *turnaround_time = (int*)malloc(n*sizeof(int));
    int *waiting_time = (int*)malloc(n*sizeof(int));
    int *remaining_time = (int*)malloc(n*sizeof(int));
    int start_time=0, finish_time=0, shortest_job_index;

    //Initialize remaining_time array
    for(i=0; i<n; i++)
    {
        remaining_time[i] = processes[i].burst_time;
    }

    while(1)
    {
        int flag=0;
        for(i=0; i<n; i++)
        {
            if(remaining_time[i]>0 && processes[i].arrival_time<=finish_time)
            {
                flag = 1;
                if(remaining_time[i]<remaining_time[shortest_job_index] || remaining_time[shortest_job_index]<=0)
                {
                    shortest_job_index = i;
                }
            }
        }

        if(flag==0)
        {
            break;
        }

        remaining_time[shortest_job_index]--;
        finish_time++;

        if(remaining_time[shortest_job_index]==0)
        {
            completion_time[shortest_job_index] = finish_time;
            turnaround_time[shortest_job_index] = completion_time[shortest_job_index] - processes[shortest_job_index].arrival_time;
            waiting_time[shortest_job_index] = turnaround_time[shortest_job_index] - processes[shortest_job_index].burst_time;

            total_wait_time += waiting_time[shortest_job_index];
            total_turnaround_time += turnaround_time[shortest_job_index];

            shortest_job_index=-1;
        }
    }

    printf("\nScheduling complete!\n");

    avg_wait_time = total_wait_time/(float)n;
    avg_turnaround_time = total_turnaround_time/(float)n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time");

    for(i=0; i<n; i++)
    {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    printf("\n\nAverage Turnaround Time: %0.2f", avg_turnaround_time);
    printf("\nAverage Waiting Time: %0.2f", avg_wait_time);

    free(processes);
    free(completion_time);
    free(turnaround_time);
    free(waiting_time);
    free(remaining_time);

    return 0;
}