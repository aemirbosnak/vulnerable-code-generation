//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: random
#include<stdio.h> // standard input/output library
#include<stdlib.h> // standard library
#include<time.h> // for random time generation
 
int main()
{
    int n, bt[20], wt[20], tat[20], avgwt = 0, avgtat = 0, i, j;
    srand(time(NULL)); // srand() is used to initialize the random generator
    printf("Enter total number of proceses(maximum 20):"); // getting the number of processes from user
    scanf("%d", &n);
 
    // generating random burst time for the processes
    for(i = 0; i < n; i++)
    {
        printf("\nProcess %d\n",i+1);
        bt[i] = rand() % 20;
        printf("Burst Time = %d",bt[i]);
    }
 
    // sorting the processes based on their burst time using bubble sort
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(bt[j] > bt[j+1])
            {
                int temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }
 
    // waiting time calculation
    for(i = 0; i < n; i++)
    {
        wt[i] = 0;
        for(j = 0; j < i; j++)
            wt[i] += bt[j];
 
        avgwt += wt[i];
    }
 
    // turnaround time calculation
    for(i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avgtat += tat[i];
    }
 
    // printing the table with results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i = 0; i < n; i++)
        printf("\nP[%d]\t%d\t\t%d\t\t%d", i+1, bt[i], wt[i], tat[i]);
 
    // calculating and printing the average waiting time and average turnaround time
    avgwt /= i;
    avgtat /= i;
    printf("\n\nAverage Waiting Time:%d", avgwt);
    printf("\nAverage Turnaround Time:%d", avgtat);
 
    return 0;
}