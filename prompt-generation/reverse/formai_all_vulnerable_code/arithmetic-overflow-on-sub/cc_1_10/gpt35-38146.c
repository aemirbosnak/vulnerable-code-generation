//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Process structure */
struct process
{
    int pid;    /* Process ID */
    int burst;  /* CPU burst time */
    int priority;   /* Process priority */
};

/* Swap function for sorting */
void swap(struct process* a, struct process* b)
{
    struct process temp = *a;
    *a = *b;
    *b = temp;
}

/* Bubble sort algorithm to sort the processes based on their priority */
void bubble_sort(struct process arr[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(arr[j].priority > arr[j+1].priority)
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* Round Robin algorithm for CPU scheduling */
void round_robin(int quantum, struct process arr[], int n)
{
    int i, j, time=0, sum_burst=0;
    float avg_turnaround=0, avg_waiting=0;
    printf("Round Robin Algorithm\n");
    printf("Quantum: %d\n", quantum);
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    printf("--------------------------------------------------------------\n");
    for(i=0; i<n; i++)
    {
        sum_burst += arr[i].burst;
    }
    while(sum_burst > 0)
    {
        for(i=0; i<n; i++)
        {
            if(arr[i].burst > 0)
            {
                if(arr[i].burst > quantum)
                {
                    time += quantum;
                    arr[i].burst -= quantum;
                    sum_burst -= quantum;
                }
                else
                {
                    time += arr[i].burst;
                    sum_burst -= arr[i].burst;
                    arr[i].burst = 0;
                }
                printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", arr[i].pid, arr[i].burst, arr[i].priority, 
                    time-arr[i].burst, time);
            }
        }
    }
    for(i=0; i<n; i++)
    {
        avg_waiting += time - arr[i].burst;
        avg_turnaround += time;
    }
    avg_waiting /= n;
    avg_turnaround /= n;
    printf("\nAverage Waiting Time = %0.2f\n", avg_waiting);
    printf("Average Turnaround Time = %0.2f\n\n", avg_turnaround);
}

/* Priority Scheduling algorithm for CPU scheduling */
void priority_scheduler(struct process arr[], int n)
{
    int i, j, time=0, sum_burst=0;
    float avg_turnaround=0, avg_waiting=0;
    printf("Priority Scheduling Algorithm\n");
    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    printf("--------------------------------------------------------------\n");

    bubble_sort(arr, n); /* Sort the array based on priority */

    for(i=0; i<n; i++)
    {
        sum_burst += arr[i].burst;
    }
    for(i=0; i<n; i++)
    {
        time += arr[i].burst;
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n", arr[i].pid, arr[i].burst, 
            arr[i].priority, time-arr[i].burst, time);
    }
    for(i=0; i<n; i++)
    {
        avg_waiting += time - arr[i].burst;
        avg_turnaround += time;
    }
    avg_waiting /= n;
    avg_turnaround /= n;
    printf("\nAverage Waiting Time = %0.2f\n", avg_waiting);
    printf("Average Turnaround Time = %0.2f\n\n", avg_turnaround);
}

/* Main function */
int main()
{
    int num_processes, i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    struct process arr[num_processes];
    srand(time(0)); /* Seed for random number generation */
    for(i=0; i<num_processes; i++)
    {
        arr[i].pid = i+1;
        arr[i].burst = rand()%10 + 1; /* Generate a random CPU burst time */
        arr[i].priority = rand()%10 + 1; /* Generate a random priority */
    }

    printf("\nCPU Scheduling Algorithms Simulation\n");
    printf("------------------------------------\n");
    printf("Processes generated with random burst time and priority.\n\n");

    priority_scheduler(arr, num_processes);

    printf("\nEnter the quantum time for Round Robin scheduling: ");
    scanf("%d", &quantum);
    round_robin(quantum, arr, num_processes);

    return 0;
}