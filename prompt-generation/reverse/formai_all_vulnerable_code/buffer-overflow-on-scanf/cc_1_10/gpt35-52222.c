//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct Process
{
    int pid, burst_time, arrival_time, wait_time, turnaround_time, completion_time;
    int priority, flag, remaining_time, response_time;
};

void swap(struct Process *p1, struct Process *p2)
{
    struct Process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort_processes(struct Process *processes, int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(processes[j].arrival_time > processes[j+1].arrival_time)
            {
                swap(&processes[j], &processes[j+1]);
            }
            if(processes[j].arrival_time == processes[j+1].arrival_time && processes[j].priority > processes[j+1].priority)
            {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void round_robin(struct Process *processes, int n)
{
    int time_quantum;
    printf("Enter time quantum for Round Robin scheduling algorithm : ");
    scanf("%d", &time_quantum);

    int i, total_time = 0, completed = 0;
    for(i=0; i<n; i++)
    {
        total_time += processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int current_time = 0;
    while(current_time < total_time)
    {
        for(i=0; i<n; i++)
        {
            if(processes[i].remaining_time > 0)
            {
                if(processes[i].remaining_time > time_quantum)
                {
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                }
                else
                {
                    current_time += processes[i].remaining_time;
                    processes[i].completion_time = current_time;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].wait_time = processes[i].turnaround_time - processes[i].burst_time;
                    processes[i].response_time = current_time - processes[i].burst_time - processes[i].arrival_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }

    int total_wait_time = 0, total_turnaround_time = 0, total_response_time = 0;
    printf("\nPId\tBT\tAT\tWT\tTT\tCT\tRT\n");
    for(i=0; i<n; i++)
    {
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].wait_time, processes[i].turnaround_time, processes[i].completion_time, processes[i].response_time);
    }
    printf("Average Wait Time : %f\n", (float) total_wait_time / n);
    printf("Average Turnaround Time : %f\n", (float) total_turnaround_time / n);
    printf("Average Response Time : %f\n", (float) total_response_time / n);

}


void priority_preemptive(struct Process *processes, int n)
{
    int current_time = processes[0].arrival_time;
    int completed = 0, i, prev = 0;

    while(completed != n)
    {
        int min_priority = 9999;
        int index = -1;
        for(i=0; i<n; i++)
        {
            if(processes[i].arrival_time <= current_time && processes[i].flag == 0)
            {
                if(processes[i].priority < min_priority)
                {
                    min_priority = processes[i].priority;
                    index = i;
                }
            }
        }

        if(index == -1)
        {
            current_time++;
            continue;
        }
        
        if(prev != index)
        {
            processes[index].response_time = current_time - processes[index].arrival_time;
        }
        processes[index].wait_time += current_time - processes[index].completion_time;
        processes[index].remaining_time--;
        current_time++;
        
        if(processes[index].remaining_time == 0)
        {
            processes[index].flag = 1;
            processes[index].completion_time = current_time;
            processes[index].turnaround_time = processes[index].completion_time - processes[index].arrival_time;
            completed++;
        }

        prev = index;

    }

    int total_wait_time = 0, total_turnaround_time = 0, total_response_time = 0;
    printf("\nPId\tBT\tAT\tWT\tTT\tCT\tRT\n");
    for(i=0; i<n; i++)
    {
        total_wait_time += processes[i].wait_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].burst_time, processes[i].arrival_time, processes[i].wait_time, processes[i].turnaround_time, processes[i].completion_time, processes[i].response_time);
    }
    printf("Average Wait Time : %f\n", (float) total_wait_time / n);
    printf("Average Turnaround Time : %f\n", (float) total_turnaround_time / n);
    printf("Average Response Time : %f\n", (float) total_response_time / n);

}

int main()
{
    int i, n, choice;
    struct Process processes[MAX];
    printf("Enter number of processes : ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        processes[i].pid = i+1;
        printf("Enter arrival time of process %d : ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time of process %d : ", i+1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter priority of process %d : ", i+1);
        scanf("%d", &processes[i].priority);
        processes[i].flag = 0;
        processes[i].response_time = -1;
        processes[i].wait_time = 0;
    }

    sort_processes(processes, n);

    printf("\nSelect Scheduling Algorithm : \n");
    printf("1. Round Robin Scheduling Algorithm\n");
    printf("2. Priority Preemptive Scheduling Algorithm\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1 : round_robin(processes, n);
                 break;
        case 2 : priority_preemptive(processes, n);
                 break;
        default : printf("Invalid choice.");
                  break;
    }

    return 0;
}