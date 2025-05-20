//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: active
#include<stdio.h>

// Defining a struct to hold the process details
struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
};

int main()
{
    // Total number of processes
    int n;
    
    // Taking user input for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    // Defining an array of struct processes
    struct process p[n];
    
    // Taking user input for process details
    for(int i=0; i<n; i++)
    {
        printf("Enter process %d details: \n", i+1);
        printf("Process ID: ");
        scanf("%d", &p[i].pid);
        printf("Burst Time: ");
        scanf("%d", &p[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &p[i].arrival_time);
        printf("Priority: ");
        scanf("%d", &p[i].priority);
    }
    
    // Sorting the array in increasing order of arrival time using Bubble Sort
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(p[j].arrival_time > p[j+1].arrival_time)
            {
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    
    // Defining a variable to hold the current time and initializing it to the arrival time of first process
    int current_time = p[0].arrival_time;
    
    // Defining an array to hold the completion time of each process
    int completion_time[n];
    
    // Initializing completion time array to -1 for each process
    for(int i=0; i<n; i++)
    {
        completion_time[i] = -1;
    }
    
    // Defining a variable to hold the index of the process with highest priority at any given time
    int highest_priority_index;
    
    // Defining a variable to hold the time left for the current process to finish executing
    int time_left;
    
    // Defining a variable to calculate the total waiting time of each process
    int total_waiting_time = 0;
    
    while(1)
    {
        // Setting highest priority index to -1
        highest_priority_index = -1;
        
        // Finding the process with highest priority at the current time
        for(int i=0; i<n; i++)
        {
            if(p[i].arrival_time <= current_time && completion_time[i] == -1)
            {
                if(highest_priority_index == -1 || p[i].priority <= p[highest_priority_index].priority)
                {
                    highest_priority_index = i;
                }
            }
        }
        
        // If no process with highest priority is found, increment the current time and continue to next iteration of while loop
        if(highest_priority_index == -1)
        {
            current_time++;
            continue;
        }
        
        // Set the time left for process with highest priority
        time_left = p[highest_priority_index].burst_time;
        
        // Update the completion time array
        completion_time[highest_priority_index] = current_time + time_left;
        
        // Update the total waiting time
        total_waiting_time += current_time - p[highest_priority_index].arrival_time;
        
        // Update the current time
        current_time = completion_time[highest_priority_index];
        
        // If all processes have been completed, break the while loop
        int all_processes_completed = 1;
        for(int i=0; i<n; i++)
        {
            if(completion_time[i] == -1)
            {
                all_processes_completed = 0;
                break;
            }
        }
        
        if(all_processes_completed)
            break;
    }
    
    // Printing the completion time for each process
    printf("\n\nProcess Details: \n");
    printf("PID\tBurst Time\tArrival Time\tPriority\tCompletion Time\tWaiting Time\n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst_time, p[i].arrival_time, p[i].priority, completion_time[i], completion_time[i]-p[i].burst_time-p[i].arrival_time);
    }
    
    // Printing the average waiting time
    printf("\n\nAverage Waiting Time: %.2f\n", (float)total_waiting_time/n);
    return 0;
}