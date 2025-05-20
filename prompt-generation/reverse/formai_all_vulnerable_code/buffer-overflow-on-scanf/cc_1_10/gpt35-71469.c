//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: cheerful
//Hello there! Welcome to my CPU Scheduling Algorithms example program.

#include<stdio.h>
#include<stdlib.h>

//Function to calculate average waiting time and turnaround time
void avgTime(int *bt, int *at, int n)
{
    int wt[n], tt[n], total_wt=0, total_tt=0;

    //Calculating waiting time
    wt[0] = 0;
    for(int i=1;i<n;i++)
    {
        wt[i] = bt[i-1] + wt[i-1] - at[i] + at[i-1];
        if(wt[i] < 0)
        {
            wt[i] = 0;
        }
    }

    //Calculating turnaround time
    for(int i=0;i<n;i++)
    {
        tt[i] = bt[i] + wt[i];
    }

    //Calculating total waiting time and total turnaround time
    for(int i=0;i<n;i++)
    {
        total_wt += wt[i];
        total_tt += tt[i];
    }

    //Printing the results
    printf("Average waiting time = %f\nAverage turnaround time = %f\n",(float)total_wt/(float)n,(float)total_tt/(float)n);
}

//Function to implement First Come First Serve (FCFS) Scheduling Algorithm
void fcfs(int *bt, int *at, int n)
{
    int ct[n];
    ct[0] = at[0] + bt[0];

    //Calculating completion time
    for(int i=1;i<n;i++)
    {
        ct[i] = ct[i-1] + bt[i];
    }

    //Printing the order and completion time of processes
    printf("\nFCFS Scheduling Order:\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d:\tCompletion Time = %d\n",i+1,ct[i]);
    }

    //Calculating and printing the average waiting time and turnaround time
    avgTime(bt,at,n);
}

//Function to implement Round Robin Scheduling Algorithm
void rr(int *bt, int *at, int n, int tq)
{
    int ct[n], rem_bt[n];
    int t=0, total_wt=0, total_tt=0;

    //Initialising remaining burst time as original burst time and completion time as arrival time
    for(int i=0;i<n;i++)
    {
        rem_bt[i] = bt[i];
        ct[i] = at[i];
    }

    //Executing processes until all are completed
    while(1)
    {
        int flag = 1; //To check whether all processes are completed or not

        //Iterating through all the processes
        for(int i=0;i<n;i++)
        {
            if(rem_bt[i] > 0)
            {
                flag = 0; //Process is not completed
                if(rem_bt[i] > tq) //If the process takes longer than time quantum
                {
                    t += tq;
                    rem_bt[i] -= tq;
                }
                else //If the process takes shorter time than time quantum
                {
                    t += rem_bt[i];
                    total_wt += t - at[i] - bt[i];
                    total_tt += t - at[i];
                    rem_bt[i] = 0;
                    ct[i] = t;
                }
            }
        }

        if(flag == 1) //All processes are completed
        {
            break;
        }
    }

    //Printing the order and completion time of processes
    printf("\nRound Robin Scheduling Order:\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d:\tCompletion Time = %d\n",i+1,ct[i]);
    }

    //Calculating and printing the average waiting time and turnaround time
    printf("Average waiting time = %f\nAverage turnaround time = %f\n",(float)total_wt/(float)n,(float)total_tt/(float)n);
}

int main()
{
    int n,tq;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int bt[n], at[n];
    printf("\nEnter the burst time and arrival time of the processes:\n");
    for(int i=0;i<n;i++)
    {
        printf("Process %d:\nBurst Time = ",i+1);
        scanf("%d",&bt[i]);
        printf("Arrival Time = ");
        scanf("%d",&at[i]);
    }

    printf("\nEnter the time quantum for Round Robin Scheduling Algorithm: ");
    scanf("%d",&tq);
    printf("\n");

    fcfs(bt,at,n);
    rr(bt,at,n,tq);

    return 0;
}