//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: accurate
#include<stdio.h>
#define N 5 // Number of Processes


// Function to find the waiting time for each process using SJF Algorithm
void SJF(int bt[], int wt[], int n)
{
    int tat[n];
    int temp_bt[n];
    int min, shortest;
    int time = 0;
    float total_wt = 0, total_tat = 0;

    // Copying Burst Time
    for (int i = 0; i < n; i++)
        temp_bt[i] = bt[i];

    //Printing Initial Output: Header Row
    printf("\n\n");
    printf("#########################################################\n");
    printf("#\t Process \t Burst Time \t Waiting Time \t#\n");
    printf("#########################################################\n");

    //Calculating Waiting Time
    while (1)
    {
        min = 9999, shortest = -1;

        //Finding Shortest Process
        for (int i = 0; i < n; i++)
        {
            //Finding Minimum Burst Time
            if (temp_bt[i] < min && temp_bt[i] > 0)
            {
                min = temp_bt[i];
                shortest = i;
            }
        }

        // Process not found, end the loop
        if (shortest == -1)
            break;

        //Update Time and Waiting Time
        time += temp_bt[shortest];
        wt[shortest] = time - bt[shortest];

        //Calculating Turnaround Time
        tat[shortest] = time;

        //Updating Burst Time
        temp_bt[shortest] = 0;

        //Updating Total Waiting and Total Turnaround Time
        total_wt += wt[shortest];
        total_tat += tat[shortest];

        //Printing Process Details
        printf("#\t P%d \t\t %d \t\t %d \t\t#\n", shortest + 1, bt[shortest], wt[shortest]);
    }
    printf("#########################################################\n");

    //Printing Average Waiting Time and Average Turnaround Time
    printf("\n\nAverage Waiting Time = %.2f\n", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);
}

int main()
{
    int burst_time[N], waiting_time[N];

    //Inputting Burst Time
    printf("Enter burst time for %d processes:\n", N);
    for (int i = 0; i < N; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    //Calculating Waiting Time using SJF Algorithm
    SJF(burst_time, waiting_time, N);

    return 0;
}