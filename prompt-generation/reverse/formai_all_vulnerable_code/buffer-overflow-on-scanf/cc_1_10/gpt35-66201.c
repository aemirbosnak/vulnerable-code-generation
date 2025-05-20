//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#define MAX_PROCESS 20 // Maximum number of processes
#define MAX_ARRIVAL 10 // Maximum arrival time
#define MAX_BURST   10 // Maximum burst time

typedef struct process
{
    int pid;        // Process ID
    int burst;      // Burst time
    int arrival;    // Arrival time
    int priority;   // Priority of the process
    int wait;       // Waiting time
    int tat;        // Turn around time
    int completed;  // If process has completed or not
} process;

// Get total waiting time of all processes
int total_waiting_time(process proc[], int n)
{
    int i, twt = 0;
    for(i=0; i<n; i++)
        twt += proc[i].wait;
    return twt;
}

// Get total turn around time of all processes
int total_turnaround_time(process proc[], int n)
{
    int i, ttat = 0;
    for(i=0; i<n; i++)
        ttat += proc[i].tat;
    return ttat;
}

// Get process with highest priority
int get_highest_priority(process proc[], int n)
{
    int i, hp = 0;
    for(i=0; i<n; i++)
        if(!proc[i].completed && proc[i].priority < proc[hp].priority)
            hp = i;
    return hp;
}

// Execute processes using Priority Scheduling
void priority_scheduling(process proc[], int n)
{
    printf("\nExecuting processes using Priority Scheduling...\n\n");
    int i, j, tn = 0, cpid;
    for(i=0; i<n; i++)
    {
        cpid = get_highest_priority(proc, n); // Get highest priority process
        proc[cpid].wait = tn - proc[cpid].arrival; // Calculate waiting time
        proc[cpid].tat = proc[cpid].wait + proc[cpid].burst; // Calculate turn around time
        tn += proc[cpid].burst; // Increase total time
        proc[cpid].completed = 1; // Mark process as completed
        printf("Process %d with priority %d executed from %d to %d\n", proc[cpid].pid, proc[cpid].priority,
                tn - proc[cpid].burst, tn); // Print process execution details
    }
    printf("\nTotal Waiting Time: %d\nTotal Turn Around Time: %d\n", total_waiting_time(proc, n),
            total_turnaround_time(proc, n)); // Print total waiting time and turn around time
}

// Driver code
int main()
{
    int n, i;
    process proc[MAX_PROCESS];
    printf("Enter number of processes: ");
    scanf("%d", &n); // Get number of processes
    for(i=0; i<n; i++)
    {
        proc[i].pid = i+1; // Assigning process IDs
        printf("\nEnter Arrival Time, Burst Time and Priority of Process %d (seperated by spaces): ", i+1);
        scanf("%d %d %d", &proc[i].arrival, &proc[i].burst, &proc[i].priority); // Get process details
        proc[i].completed = 0;
    }
    priority_scheduling(proc, n); // Execute processes using Priority Scheduling
    return 0;
}