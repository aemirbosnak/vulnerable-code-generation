//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

//Structure to represent a process
struct process
{
    int pid; //Process ID
    int burst_time; //Burst time
    int arrival_time; //Arrival time
    int priority; //Process priority
};

//Function to swap two processes during sorting
void swap(struct process *a, struct process *b) 
{
    struct process temp = *a; 
    *a = *b; 
    *b = temp; 
}

//FCFS algorithm
void fcfs(struct process processes[], int n) 
{
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;
    waiting_time[0] = 0; //Waiting time for the first process is always zero
    for(int i = 1; i < n; i++) 
    {
        waiting_time[i] = processes[i-1].burst_time + waiting_time[i-1]; //Waiting time for the current process is the sum of burst time of all previous processes
    }
    printf("FCFS Scheduling Algorithm:\n");
    printf("Process ID  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    for(int i = 0; i < n; i++) 
    {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i]; //Turnaround time is the sum of burst time and waiting time
        total_waiting_time += waiting_time[i]; 
        total_turnaround_time += turnaround_time[i]; 
        printf("%-12d%-14d%-12d%-14d%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time/n);
}

//SJF algorithm
void sjf(struct process processes[], int n)
{
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;
    for(int i = 0; i < n-1; i++) //Selection sort to sort processes based on burst time in ascending order
    {
        int minIndex = i;
        for(int j = i+1; j < n; j++)
        {
            if(processes[j].burst_time < processes[minIndex].burst_time)
            {
                minIndex = j;
            }
        }
        swap(&processes[minIndex], &processes[i]);
    }
    waiting_time[0] = 0; //Waiting time for the first process is always zero
    for(int i = 1; i < n; i++) 
    {
        waiting_time[i] = processes[i-1].burst_time + waiting_time[i-1]; //Waiting time for the current process is the sum of burst time of all previous processes
    }
    printf("\nSJF Scheduling Algorithm:\n");
    printf("Process ID  Arrival Time  Burst Time  Waiting Time  Turnaround Time\n");
    for(int i = 0; i < n; i++) 
    {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i]; //Turnaround time is the sum of burst time and waiting time
        total_waiting_time += waiting_time[i]; 
        total_turnaround_time += turnaround_time[i]; 
        printf("%-12d%-14d%-12d%-14d%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time/n);
}

//Priority algorithm
void priority(struct process processes[], int n)
{
    int waiting_time[n], turnaround_time[n], total_waiting_time = 0, total_turnaround_time = 0;
    for(int i = 0; i < n-1; i++) //Selection sort to sort processes based on priority in descending order
    {
        int maxIndex = i;
        for(int j = i+1; j < n; j++)
        {
            if(processes[j].priority > processes[maxIndex].priority)
            {
                maxIndex = j;
            }
        }
        swap(&processes[maxIndex], &processes[i]);
    }
    waiting_time[0] = 0; //Waiting time for the first process is always zero
    for(int i = 1; i < n; i++) 
    {
        waiting_time[i] = processes[i-1].burst_time + waiting_time[i-1]; //Waiting time for the current process is the sum of burst time of all previous processes
    }
    printf("\nPriority Scheduling Algorithm:\n");
    printf("Process ID  Arrival Time  Burst Time  Priority  Waiting Time  Turnaround Time\n");
    for(int i = 0; i < n; i++) 
    {
        turnaround_time[i] = processes[i].burst_time + waiting_time[i]; //Turnaround time is the sum of burst time and waiting time
        total_waiting_time += waiting_time[i]; 
        total_turnaround_time += turnaround_time[i]; 
        printf("%-12d%-14d%-12d%-10d%-14d%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
    }
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time/n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time/n);
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process processes[n];
    for(int i = 0; i < n; i++)
    {
        processes[i].pid = i+1;
        printf("\nEnter the arrival time of process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter the priority of process %d: ", i+1);
        scanf("%d", &processes[i].priority);
    }
    fcfs(processes, n);
    sjf(processes, n);
    priority(processes, n);
    return 0;
}