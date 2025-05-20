//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: medieval
#include<stdio.h>

int main()
{
    int arrival_time[50], burst_time[50], waiting_time[50], turnaround_time[50], temp1[50], temp2[50];
    int n, i, j, total = 0, position, temp, key;

    printf("Enter the total number of processes: ");
    scanf("%d", &n);

    printf("\nEnter the Arrival Time and Burst Time of the processes:\n");
    for(i=0; i<n; i++)
    {
        printf("\nProcess[%d]\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &arrival_time[i]);
        printf("Burst Time: ");
        scanf("%d", &burst_time[i]);
        temp1[i] = burst_time[i];
    }

    printf("\nEnter the time quantum: ");
    scanf("%d", &key);

    printf("\nMedieval Round Robin Scheduling\n");
    printf("\n\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\t Turnaround Time");

    for(total=0, i=0; n!=0;)
    {
        if(temp1[i] <= key && temp1[i]>0)
        {
            total += temp1[i];
            temp1[i] = 0;
            position = 1;
        }
        else if(temp1[i]>0)
        {
            temp1[i] -= key;
            total += key;
        }

        if(temp1[i]==0 && position == 1)
        {
            n--;
            printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\t\t%d", i+1, arrival_time[i], burst_time[i], total-arrival_time[i]-burst_time[i], total-arrival_time[i]);
            waiting_time[i] = total - arrival_time[i] - burst_time[i];
            turnaround_time[i] = total - arrival_time[i];
            position = 2;
        }

        if(i==n-1)
            i=0;
        else if(arrival_time[i+1] <= total)
            i++;
        else
            i=0;
    }

    printf("\n\nProcess\t\tWaiting Time\tTurnaround Time");
    for(i=0; i<n; i++)
    {
        printf("\nProcess[%d]\t\t%d\t\t%d", i+1, waiting_time[i], turnaround_time[i]);
    }

    return 0;
}