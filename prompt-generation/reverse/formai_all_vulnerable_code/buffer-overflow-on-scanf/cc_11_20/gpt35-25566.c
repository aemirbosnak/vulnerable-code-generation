//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: funny
#include<stdio.h>

// A funny program to demonstrate the Round Robin CPU Scheduling Algorithm 

int main()
{
     printf("Welcome to the Round Robin CPU Scheduling Simulator!\n");
     printf("We are going to make sure your tasks are done in a fair, fun way!\n");

     int n,i,quantum,wait_time=0,tat_time=0,at[10],bt[10],rt[10];

     printf("Enter the number of tasks to be done (up to 10): ");
     scanf("%d",&n);

     printf("Enter the time quantum (in milliseconds):");
     scanf("%d",&quantum);

     for(i=0;i<n;i++)
     {
          printf("Enter the arrival time for task %d:",i+1);
          scanf("%d",&at[i]);
          printf("Enter the burst time for task %d:",i+1);
          scanf("%d",&bt[i]);
          rt[i]=bt[i];
     }

     printf("\nTask\t Arrival Time \t Burst Time \t Waiting Time\t Turnaround Time\n");

     int time=0,flag=0;
     i=0;
     while(1)
     {
          if(rt[i]<=quantum && rt[i]>0)
          {
               time+=rt[i];
               rt[i]=0;
               flag=1;
          }
          else if(rt[i]>0)
          {
               rt[i]-=quantum;
               time+=quantum;
          }

          if(rt[i]==0 && flag==1)
          {
               wait_time+=time-at[i]-bt[i];
               tat_time+=time-at[i];
               printf("\n%d\t\t %d\t\t %d\t\t %d\t\t %d",i+1,at[i],bt[i],time-at[i]-bt[i],time-at[i]);
               flag=0;
          }

          if(i==n-1)
          {
               i=0;
          }
          else if(at[i+1]<=time)
          {
               i++;
          }
          else
          {
               i=0;
          }

          if(time>10000)  // Just in case someone leaves the program running for too long
          {
                printf("\nOh no, sorry, CPU is overheated... Simulation terminated!");
                break;
          }
     }

     float avg_wait_time,avg_tat_time;
     avg_wait_time=(float)wait_time/n;
     avg_tat_time=(float)tat_time/n;

     printf("\n\nAverage waiting time is %.2f milliseconds",avg_wait_time);
     printf("\nAverage turnaround time is %.2f milliseconds",avg_tat_time);

     printf("\nYay! All your tasks are done in a fair and efficient way, thanks for watching!");
     return 0;
}