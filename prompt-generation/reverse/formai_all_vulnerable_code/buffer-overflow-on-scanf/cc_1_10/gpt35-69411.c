//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

// Process structure
typedef struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

// Function to calculate average waiting and turnaround time
void calculateAverageTime(Process P[], int n)
{
    int total_waiting_time = 0, total_turnaround_time = 0;
    int i;

    // Calculate waiting and turnaround time for each process
    for (i = 0; i < n; i++)
    {
        P[i].turnaround_time = P[i].burst_time + P[i].waiting_time;
        total_waiting_time += P[i].waiting_time;
        total_turnaround_time += P[i].turnaround_time;
    }

    // Print average waiting and turnaround time
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
}

// Function to implement FCFS scheduling algorithm
void fcfs(Process P[], int n)
{
    int i, current_time = 0;

    // Set initial waiting time for first process to 0
    P[0].waiting_time = 0;

    // Calculate waiting time for each process
    for (i = 1; i < n; i++)
    {
        current_time += P[i-1].burst_time;
        P[i].waiting_time = current_time - P[i].arrival_time;
        if (P[i].waiting_time < 0)
            P[i].waiting_time = 0;
    }

    // Calculate average waiting and turnaround time
    calculateAverageTime(P, n);
}

// Function to implement SJF scheduling algorithm
void sjf(Process P[], int n)
{
    int i, j, shortest, current_time = 0;

    // Sort processes by arrival time
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (P[i].arrival_time > P[j].arrival_time)
            {
                Process temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }

    // Calculate waiting time for each process
    for (i = 0; i < n; i++)
    {
        shortest = i;
        for (j = i + 1; j < n; j++)
        {
            if (P[j].burst_time < P[shortest].burst_time && P[j].arrival_time <= current_time)
                shortest = j;
        }

        // Swap processes
        Process temp = P[i];
        P[i] = P[shortest];
        P[shortest] = temp;

        // Calculate waiting time
        P[i].waiting_time = current_time - P[i].arrival_time;
        if (P[i].waiting_time < 0)
            P[i].waiting_time = 0;

        // Update current time
        current_time += P[i].burst_time;
    }

    // Calculate average waiting and turnaround time
    calculateAverageTime(P, n);
}

int main()
{
    int i, n;
    Process P[MAX_PROCESSES];

    // Get number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Get process details
    for (i = 0; i < n; i++)
    {
        P[i].pid = i + 1;
        printf("Process %d\n", P[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &P[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &P[i].burst_time);
        printf("\n");
    }

    // Call scheduling algorithms
    printf("Average Waiting Time and Turnaround Time for FCFS:\n");
    fcfs(P, n);

    printf("Average Waiting Time and Turnaround Time for SJF:\n");
    sjf(P, n);

    return 0;
}