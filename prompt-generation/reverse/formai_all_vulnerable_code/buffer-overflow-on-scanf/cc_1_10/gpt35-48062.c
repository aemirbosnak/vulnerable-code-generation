//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

/* Define a process struct */
struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
};

/* Define a function to swap two processes */
void swap(struct process* a, struct process* b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

/* Define a function to sort processes by arrival time */
void sortByArrivalTime(struct process* processes, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)      
    {
        for (j = 0; j < n - i - 1; j++)  
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

/* Define a function to sort processes by priority */
void sortByPriority(struct process* processes, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)      
    {
        for (j = 0; j < n - i - 1; j++)  
        {
            if (processes[j].priority < processes[j + 1].priority)
            {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }
}

/* Define a function to implement First-Come-First-Serve algorithm */
void fcfs(struct process* processes, int n)
{
    int i, wt[n], total_wt = 0;
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = processes[i - 1].burst_time + wt[i - 1];
        total_wt += wt[i];
    }
    printf("FCFS:\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, wt[i]);
    }
    printf("Average waiting time = %.2f\n\n", (float)total_wt / (float)n);
}

/* Define a function to implement Priority Scheduling algorithm */
void priorityScheduling(struct process* processes, int n)
{
    sortByPriority(processes, n);
    int i, wt[n], total_wt = 0;
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = processes[i - 1].burst_time + wt[i - 1];
        total_wt += wt[i];
    }
    printf("Priority Scheduling:\n");
    printf("Process ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, wt[i]);
    }
    printf("Average waiting time = %.2f\n\n", (float)total_wt / (float)n);
}

/* Define a function to implement Round Robin algorithm */
void roundRobin(struct process* processes, int n)
{
    int time_quantum = 2, i, wt[n], total_wt = 0, j, flag = 0;
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
    }
    do
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int temp_burst_time = processes[i].burst_time;
            if (temp_burst_time > time_quantum)
            {
                temp_burst_time -= time_quantum;
                flag = 1;
            }
            else if (temp_burst_time <= time_quantum && temp_burst_time > 0)
            {
                flag = 1;
                processes[i].burst_time = 0;
                wt[i] = (total_wt - processes[i].arrival_time);
                total_wt += temp_burst_time;
            }
            if (flag == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (processes[j].arrival_time <= total_wt && processes[j].burst_time > 0 && processes[j].priority > processes[i].priority)
                    {
                        swap(&processes[i], &processes[j]);
                    }
                }
            }
        }
    } while (flag == 1);
    printf("Round Robin:\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, wt[i]);
    }
    printf("Average waiting time = %.2f\n\n", (float)total_wt / (float)n);
}

int main()
{
    int choice, i, n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process processes[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter details of process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].pid);
        printf("Arrival time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst time: ");
        scanf("%d", &processes[i].burst_time);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }
    printf("Choose the scheduling algorithm:\n");
    printf("1. FCFS\n");
    printf("2. Priority Scheduling\n");
    printf("3. Round Robin\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
            sortByArrivalTime(processes, n);
            fcfs(processes, n);
            break;
        case 2:
            priorityScheduling(processes, n);
            break;
        case 3:
            sortByArrivalTime(processes, n);
            roundRobin(processes, n);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }
    return 0;
}