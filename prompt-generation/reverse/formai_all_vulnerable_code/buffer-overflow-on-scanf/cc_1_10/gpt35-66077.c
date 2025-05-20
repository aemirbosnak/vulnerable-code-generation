//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

// defining a process structure with 4 variables
struct process {
    int pid, priority, burst_time, waiting_time;
} queue[10];

int num_processes, total_waiting_time = 0, total_burst_time = 0;

// function to swap two processes in the queue
void swap(struct process *p1, struct process *p2) 
{
    struct process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// function to sort the queue based on priority
void priority_sort() 
{
    int i, j;
    for(i = 0; i < num_processes-1; i++) 
    {
        for(j = i+1; j < num_processes; j++) 
        {
            if(queue[i].priority > queue[j].priority) 
            {
                swap(&queue[i], &queue[j]);
            }
        }
    }
}

// function to sort the queue based on burst time
void burst_time_sort() 
{
    int i, j;
    for(i = 0; i < num_processes-1; i++) 
    {
        for(j = i+1; j < num_processes; j++) 
        {
            if(queue[i].burst_time > queue[j].burst_time) 
            {
                swap(&queue[i], &queue[j]);
            }
        }
    }
}

// function to calculate waiting time for each process
void calculate_waiting_time() 
{
    int i, prev_waiting_time = 0;
    for(i = 0; i < num_processes; i++) 
    {
        queue[i].waiting_time = prev_waiting_time;
        prev_waiting_time += queue[i].burst_time;
        total_waiting_time += queue[i].waiting_time;
    }
}

// function to print results of each process
void print_results() 
{
    int i;
    printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\n");
    for(i = 0; i < num_processes; i++) 
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", queue[i].pid, queue[i].priority, queue[i].burst_time, queue[i].waiting_time);
    }
    printf("\nAverage Waiting Time: %.2f\n", (float)total_waiting_time/num_processes);
}

int main() 
{
    int i;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter priority and burst time for each process:\n");

    for(i = 0; i < num_processes; i++) 
    {
        queue[i].pid = i+1;
        printf("Process %d:\n", queue[i].pid);
        printf("Priority: ");
        scanf("%d", &queue[i].priority);
        printf("Burst Time: ");
        scanf("%d", &queue[i].burst_time);
        total_burst_time += queue[i].burst_time;
    }

    // sorting queue based on priority
    priority_sort();

    // calculating waiting time for each process
    calculate_waiting_time();

    // printing output
    printf("\nResults based on priority:\n");
    print_results();

    // sorting queue based on burst time
    burst_time_sort();

    // calculating waiting time for each process
    calculate_waiting_time();

    // printing output
    printf("\nResults based on burst time:\n");
    print_results();

    return 0;
}