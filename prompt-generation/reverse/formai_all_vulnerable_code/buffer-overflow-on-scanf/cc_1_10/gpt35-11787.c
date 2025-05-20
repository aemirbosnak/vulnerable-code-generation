//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: automated
#include <stdio.h>

//implementing round-robin scheduling algorithm
int main()
{
    int n, q, i, j, count=0, time=0, flag=0;
    int arrival_time[50], burst_time[50], rem_bt[50];
    float total_tat=0, total_wt=0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter time quantum: ");
    scanf("%d", &q);

    printf("Enter the arrival times of the processes: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arrival_time[i]);
    }

    printf("Enter the burst times of the processes: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &burst_time[i]);
        rem_bt[i]=burst_time[i];
    }

    //implementing the algorithm
    while(count!=n)
    {
        for(i=0; i<n; i++)
        {
            if(rem_bt[i]>0)
            {
                flag=1;

                if(rem_bt[i]>q)
                {
                    time+=q;
                    rem_bt[i]-=q;
                }
                else
                {
                    time+=rem_bt[i];
                    arrival_time[i]=time-burst_time[i];
                    rem_bt[i]=0;
                    count++;
                }
            }
        }

        if(flag==0)
        {
            break;
        }
    }

    printf("\nPROCESS\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME");

    for(i=0; i<n; i++)
    {
        float tat = (float)time - arrival_time[i];
        float wt = (float)tat - burst_time[i];

        printf("\nP[%d]\t\t %d\t\t %d\t\t %0.2f\t\t %0.2f",
                i+1, arrival_time[i], burst_time[i], wt, tat);

        total_wt+=wt;
        total_tat+=tat;
    }

    printf("\n\nAverage waiting time: %0.2f", total_wt/n);
    printf("\nAverage turnaround time: %0.2f\n\n", total_tat/n);

    return 0;
}