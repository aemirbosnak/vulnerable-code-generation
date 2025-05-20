//FormAI DATASET v1.0 Category: System boot optimizer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_processes; //Number of processes in the system
    int *priority; //Array of priorities for each process
    int *burst_time; //Array of burst times for each process
    int quantum; //Time quantum for round robin scheduling
    int i, j; //Loop variables

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    //Dynamically allocate memory for priority and burst_time arrays
    priority = (int*) malloc(num_processes * sizeof(int));
    burst_time = (int*) malloc(num_processes * sizeof(int));

    printf("Enter the priority values of the processes: ");
    for(i=0; i<num_processes; i++)
    {
        scanf("%d", &priority[i]);
    }

    printf("Enter the burst time values of the processes: ");
    for(i=0; i<num_processes; i++)
    {
        scanf("%d", &burst_time[i]);
    }

    printf("Enter the time quantum for round robin scheduling: ");
    scanf("%d", &quantum);

    //Round robin scheduling algorithm
    int time = 0; //Current time
    int *remaining_time; //Array to store remaining burst time for each process
    remaining_time = (int*) malloc(num_processes * sizeof(int));
    for(i=0; i<num_processes; i++)
    {
        remaining_time[i] = burst_time[i];
    }

    int flag = 0; //Flag variable to check if all processes are completed
    while(flag == 0)
    {
        flag = 1;
        for(i=0; i<num_processes; i++)
        {
            if(remaining_time[i] > 0)
            {
                flag = 0;
                if(remaining_time[i] <= quantum)
                {
                    time += remaining_time[i];
                    remaining_time[i] = 0;
                }
                else
                {
                    time += quantum;
                    remaining_time[i] -= quantum;
                }
            }
        }
    }

    //Calculate turnaround time and waiting time for each process
    float *turnaround_time;
    float *waiting_time;
    turnaround_time = (float*) malloc(num_processes * sizeof(float));
    waiting_time = (float*) malloc(num_processes * sizeof(float));
    for(i=0; i<num_processes; i++)
    {
        turnaround_time[i] = time;
        waiting_time[i] = time - burst_time[i];
    }

    //Calculate average turnaround time and waiting time for the system
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    for(i=0; i<num_processes; i++)
    {
        avg_turnaround_time += turnaround_time[i];
        avg_waiting_time += waiting_time[i];
    }
    avg_turnaround_time /= num_processes;
    avg_waiting_time /= num_processes;

    printf("Average turnaround time: %.2f\n", avg_turnaround_time);
    printf("Average waiting time: %.2f\n", avg_waiting_time);

    //Free allocated memory
    free(priority);
    free(burst_time);
    free(remaining_time);
    free(turnaround_time);
    free(waiting_time);

    return 0;
}