//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//Function to find the minimum arrival time and create an array of arrival time
int findMinArrivalTime(int arrival[], int n)
{
    int minArrival = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(arrival[i] < minArrival)
            minArrival = arrival[i];
    }
    return minArrival;
}

//Function to find the maximum completion time and create an array of completion time
int findMaxCompletionTime(int arrival[], int burst[], int n)
{
    int completion[n];
    int maxCompletion = INT_MIN;
    int timeElapsed = 0;
    for(int i = 0; i < n; i++)
    {
        if(timeElapsed < arrival[i])
            timeElapsed = arrival[i];
        completion[i] = timeElapsed + burst[i];
        timeElapsed = completion[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(completion[i] > maxCompletion)
            maxCompletion = completion[i];
    }

    return maxCompletion;
}

//Function to implement the First Come First Serve scheduling algorithm
void fcfs(int arrival[], int burst[], int n)
{
    int completion[n];
    int turnaround[n];
    int waiting[n];
    int totalWaitTime = 0;
    int totalTurnaroundTime = 0;

    int timeElapsed = findMinArrivalTime(arrival, n);

    for(int i = 0; i < n; i++)
    {
        if(timeElapsed < arrival[i])
            timeElapsed = arrival[i];
        completion[i] = timeElapsed + burst[i];
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        timeElapsed = completion[i];
        totalTurnaroundTime += turnaround[i];
        totalWaitTime += waiting[i];
    }

    float avgWaitTime = (float)totalWaitTime/n;
    float avgTurnaroundTime = (float)totalTurnaroundTime/n;

    printf("\nFirst Come First Serve Scheduling Algorithm");

    printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", i+1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgWaitTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
}

//Function to implement the Shortest Job First scheduling algorithm
void sjf(int arrival[], int burst[], int n)
{
    int completion[n];
    int turnaround[n];
    int waiting[n];
    int totalWaitTime = 0;
    int totalTurnaroundTime = 0;

    int timeElapsed = findMinArrivalTime(arrival, n);
    int timeLeft[n];
    int completed[n];

    for(int i = 0; i < n; i++)
    {
        timeLeft[i] = burst[i];
        completed[i] = 0;
    }

    while(1)
    {
        int shortestJobIndex = -1;
        int shortestJobTime = INT_MAX;

        if(timeElapsed >= findMaxCompletionTime(arrival, burst, n))
            break;

        for(int i = 0; i < n; i++)
        {
            if(arrival[i] <= timeElapsed && completed[i] == 0)
            {
                if(timeLeft[i] < shortestJobTime)
                {
                    shortestJobIndex = i;
                    shortestJobTime = timeLeft[i];
                }
            }
        }

        if(shortestJobIndex == -1)
        {
            timeElapsed++;
            continue;
        }

        completion[shortestJobIndex] = timeElapsed + burst[shortestJobIndex];
        turnaround[shortestJobIndex] = completion[shortestJobIndex] - arrival[shortestJobIndex];
        waiting[shortestJobIndex] = turnaround[shortestJobIndex] - burst[shortestJobIndex];
        totalTurnaroundTime += turnaround[shortestJobIndex];
        totalWaitTime += waiting[shortestJobIndex];
        timeLeft[shortestJobIndex] = 0;
        completed[shortestJobIndex] = 1;
        timeElapsed = completion[shortestJobIndex];
    }

    float avgWaitTime = (float)totalWaitTime/n;
    float avgTurnaroundTime = (float)totalTurnaroundTime/n;

    printf("\nShortest Job First Scheduling Algorithm");

    printf("\nProcess\t Arrival Time\t Burst Time\t Completion Time\t Turnaround Time\t Waiting Time\n");

    for(int i = 0; i < n; i++)
    {
        printf("P%d\t %d\t\t %d\t\t %d\t\t\t %d\t\t\t %d\n", i+1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avgWaitTime);
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime);
}

int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrival[n];
    int burst[n];

    printf("\nEnter the arrival time and burst time for each process:\n");
    for(int i = 0; i < n; i++)
    {
        printf("\nProcess %d:\n", i+1);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);
    }

    fcfs(arrival, burst, n);
    sjf(arrival, burst, n);

    return 0;
}