//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

typedef struct process 
{
    int process_id;
    int burst_time;
    int priority;
} Process;

Process processes[MAX_PROCESSES];
int n;

void get_processes()
{
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter details for process %d: \n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].process_id);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }
}

void print_processes()
{
    printf("Process ID\tBurst Time\tPriority\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].priority);
    }
}

// First Come First Serve (FCFS) Algorithm
void fcfs()
{
    printf("\nFCFS Algorithm\n");
    int waiting_time = 0;
    printf("Process ID\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, waiting_time);
        waiting_time += processes[i].burst_time;
    }
}

// Shortest Job First (SJF) Algorithm
void sjf()
{
    printf("\nSJF Algorithm\n");
    int waiting_time = 0;
    // Sort processes by burst time
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (processes[i].burst_time > processes[j].burst_time)
            {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    printf("Process ID\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, waiting_time);
        waiting_time += processes[i].burst_time;
    }
}

// Priority Scheduling Algorithm
void priority_scheduling()
{
    printf("\nPriority Scheduling Algorithm\n");
    int waiting_time = 0;
    // Sort processes by priority
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (processes[i].priority > processes[j].priority)
            {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    printf("Process ID\tBurst Time\tPriority\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, processes[i].burst_time, processes[i].priority, waiting_time);
        waiting_time += processes[i].burst_time;
    }
}

int main()
{
    get_processes();
    print_processes();
    
    fcfs();
    sjf();
    priority_scheduling();

    return 0;
}