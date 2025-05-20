//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include<stdio.h>

int main()
{
    int n, i, j, time_slice, total = 0;
    int wait_time = 0, turn_around_time = 0;
    int arrival_time[10], burst_time[10], temp_burst_time[10];
    float avg_wait_time, avg_turn_around_time;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter the arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process[%d]\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp_burst_time[i] = burst_time[i];
    }

    printf("Enter the time slice: ");
    scanf("%d", &time_slice);

    printf("\nProcess\t\tTurnaround Time\t\tWaiting Time\n");

    for(total = 0, i = 0; n != 0;)
    {
        if(temp_burst_time[i] <= time_slice && temp_burst_time[i] > 0)
        {
            total += temp_burst_time[i];
            temp_burst_time[i] = 0;
            j = 1;
        }
        else if(temp_burst_time[i] > 0)
        {
            temp_burst_time[i] -= time_slice;
            total += time_slice;
        }

        if(temp_burst_time[i] == 0 && j == 1)
        {
            n--;
            printf("Process[%d]\t\t%d\t\t\t%d\n", i+1, total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
            wait_time += total - arrival_time[i] - burst_time[i];
            turn_around_time += total - arrival_time[i];
            j = 0;
        }

        if(i == n - 1)
            i = 0;
        else if(arrival_time[i+1] <= total)
            i++;
        else
            i = 0;
    }

    avg_wait_time = (float)wait_time/10;
    avg_turn_around_time = (float)turn_around_time/10;
    printf("Average Waiting Time: %f\n", avg_wait_time);
    printf("Average Turnaround Time: %f", avg_turn_around_time);

    return 0;
}