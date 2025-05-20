//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include <stdio.h>

int main()
{
    int n, i, j, time, sum_wait = 0, sum_turnaround = 0;
    int min, temp, burst_time[20], process[20], wait_time[20], turnaround_time[20];

    float average_wait_time, average_turnaround_time;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the burst times:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
        process[i] = i + 1;
    }

    // Sorting the burst times in ascending order
    for(i = 0; i < n; i++)
    {
        min = i;
        for(j = i + 1; j < n; j++)
        {
            if(burst_time[j] < burst_time[min])
            {
                min = j;
            }
        }

        temp = burst_time[i];
        burst_time[i] = burst_time[min];
        burst_time[min] = temp;

        temp = process[i];
        process[i] = process[min];
        process[min] = temp;
    }

    // Calculating the waiting time for each process
    wait_time[0] = 0;
    for(i = 1; i < n; i++)
    {
        wait_time[i] = 0;
        for(j = 0; j < i; j++)
        {
            wait_time[i] += burst_time[j];
        }
        sum_wait += wait_time[i];
    }

    // Calculating the turnaround time for each process
    for(i = 0; i < n; i++)
    {
        turnaround_time[i] = burst_time[i] + wait_time[i];
        sum_turnaround += turnaround_time[i];
    }

    // Calculating the average waiting time and average turnaround time
    average_wait_time = (float) sum_wait / n;
    average_turnaround_time = (float) sum_turnaround / n;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], wait_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", average_wait_time);
    printf("\nAverage Turnaround Time: %.2f", average_turnaround_time);

    return 0;
}