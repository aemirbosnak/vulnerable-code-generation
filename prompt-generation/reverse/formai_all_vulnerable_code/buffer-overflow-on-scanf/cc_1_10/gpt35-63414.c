//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
   int n, i, j, c =0,k=0, qt;
   float avg_wt,avg_tat;
   printf("Enter number of processess: ");
   scanf("%d",&n);
   int arrival_time[n], burst_time[n], remaining_time[n], turnaround_time[n], waiting_time[n];
   for(i=0;i<n;i++)
   {
       printf("Enter arrival time and burst time for process P%d : ",i+1);
       scanf("%d%d",&arrival_time[i],&burst_time[i]);
       remaining_time[i]=burst_time[i];   // initialize the remaining time with burst time
   }
   printf("Enter time quantum: ");
   scanf("%d",&qt);
   printf("\n");

   // Implementing Round Robin Scheduling Algorithm
   printf("Round Robin Scheduling Algorithm\n\n");
   while (1)
   {
       int flag=0;   // for implementation of completion of whole process or not
       for(i=0;i<n;i++)
       {
           if(remaining_time[i]>0)
           {
               flag=1;
               if(remaining_time[i]>qt)   // condition to execute process for time quantum only
               {
                   c+=qt;
                   remaining_time[i]-=qt;
               }
               else
               {
                   c+=remaining_time[i];
                   turnaround_time[i]=c-arrival_time[i];
                   waiting_time[i]=turnaround_time[i]-burst_time[i];
                   remaining_time[i]=0;
               }
           }
       }
       if(flag==0)   // all processes are completed
           break;
   }
   printf("Process\t   Arrival Time  \tBurst Time  \tWaiting Time  \tTurnaround Time\n");
   for(i=0;i<n;i++)
   {   // Calculate the turnaround time and waiting time for each process
       printf("P%d\t\t  %d\t\t\t%d\t\t\t%d\t\t\t%d\n",i+1,arrival_time[i],burst_time[i],waiting_time[i],turnaround_time[i]);
       avg_wt+=waiting_time[i];
       avg_tat+=turnaround_time[i];   
   }
   printf("\n");
   printf("Average Waiting Time: %f\n",avg_wt/n);
   printf("Average Turnaround Time: %f",avg_tat/n);
   printf("\n\n");
   return 0;
}