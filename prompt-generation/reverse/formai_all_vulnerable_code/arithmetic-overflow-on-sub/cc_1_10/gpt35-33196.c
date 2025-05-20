//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: inquisitive
#include<stdio.h>

typedef struct Process
{
    int process_ID;
    int burst_time;
}Process;

void sort(Process *processes, int n)
{
    int i, j;
    for(i = 0; i < n - 1; i++)
        for(j = 0; j < n - i - 1; j++)
            if(processes[j].burst_time > processes[j+1].burst_time)
            {
                Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
}

void main()
{
    int n, i, total_wait_time = 0, total_turnaround_time = 0;
    float avg_wait_time, avg_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[n], temp;

    for(i = 0; i < n; i++)
    {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_ID = i+1;
    }

    sort(processes, n);

    printf("\nOrder of Execution: \n");
    for(i = 0; i < n; i++)
        printf("P%d ", processes[i].process_ID);

    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

    for(i = 0; i < n; i++)
    {
        int j;
        temp = processes[i];
        int wait_time = 0, turnaround_time = 0;

        for(j = 0; j < i; j++)
            wait_time += processes[j].burst_time;

        for(j = 0; j <= i; j++)
            turnaround_time += processes[j].burst_time;

        printf("\n%d\t\t%d\t\t%d\t\t%d", temp.process_ID, temp.burst_time, wait_time, turnaround_time);
        total_wait_time += wait_time;
        total_turnaround_time += turnaround_time;
    }

    avg_wait_time = (float) total_wait_time / n;
    avg_turnaround_time = (float) total_turnaround_time / n;

    printf("\n\nAverage Waiting Time: %.2f", avg_wait_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
}