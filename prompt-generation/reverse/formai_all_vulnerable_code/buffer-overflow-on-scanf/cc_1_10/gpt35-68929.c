//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESSES 100
#define MAX_TIME_SLICE 25

typedef struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completed_time;
    bool is_completed;
} Process;

int main()
{
    int num_processes, time_slice, total_burst_time = 0, total_completed_time = 0;
    Process processes[MAX_PROCESSES];
    srand(time(NULL)); // Initialize random seed

    // Take input from user
    printf("Enter the number of processes to schedule: ");
    scanf("%d", &num_processes);

    printf("Enter the time slice for Round Robin scheduling: ");
    scanf("%d", &time_slice);

    printf("Generating random arrival and burst times for each process...\n");

    // Generate arrival time and burst time for each process randomly
    for(int i = 0; i < num_processes; i++)
    {
        processes[i].pid = i+1;
        processes[i].arrival_time = rand() % 100;
        processes[i].burst_time = rand() % 50 + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed_time = 0;
        processes[i].is_completed = false;
        total_burst_time += processes[i].burst_time;
    }

    // Sort the processes by arrival time in descending order
    for(int i = 0; i < num_processes-1; i++)
    {
        for(int j = i+1; j < num_processes; j++)
        {
            if(processes[i].arrival_time < processes[j].arrival_time)
            {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int current_time = 0;

    printf("Starting Round Robin scheduling...\n\n");
    printf("Process ID\tArrival Time\tBurst Time\tCompleted Time\n");

    while(total_completed_time < total_burst_time)
    {
        for(int i = 0; i < num_processes; i++)
        {
            if(!processes[i].is_completed && processes[i].arrival_time <= current_time)
            {
                if(processes[i].remaining_time <= time_slice)
                {
                    current_time += processes[i].remaining_time;
                    total_completed_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].is_completed = true;
                    processes[i].completed_time = current_time;
                    printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completed_time);
                }
                else
                {
                    current_time += time_slice;
                    total_completed_time += time_slice;
                    processes[i].remaining_time -= time_slice;
                }
            }
        }
    }

    printf("\nAll processes completed.\n");

    return 0;
}