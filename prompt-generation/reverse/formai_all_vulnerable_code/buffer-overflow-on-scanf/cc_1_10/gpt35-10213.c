//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>

int main() {
   int processes[20];
   int burstTime[20];
   int waitingTime[20];
   int arrivalTime[20];
   int n,total=0,pos,temp;
   float avg_waitingTime,avg_turnAroundTime;
   printf("Enter number of processes:");
   scanf("%d",&n);
 
   printf("\nEnter Arrival Time and Burst Time:\n");
   for(int i=0;i<n;i++)
   {
       printf("\nP[%d]:",i+1);
       printf("\nArrival Time:");
       scanf("%d",&arrivalTime[i]);
       printf("Burst Time:");
       scanf("%d",&burstTime[i]);
       processes[i]=i+1;
   }
 
   for(int i=0;i<n;i++)
   {
       pos=i;
       for(int j=i+1;j<n;j++)
       {
           if(arrivalTime[j]<arrivalTime[pos])
               pos = j;
       }
 
       temp=arrivalTime[i];
       arrivalTime[i]=arrivalTime[pos];
       arrivalTime[pos]=temp;
 
       temp=burstTime[i];
       burstTime[i]=burstTime[pos];
       burstTime[pos]=temp;
 
       temp=processes[i];
       processes[i]=processes[pos];
       processes[pos]=temp;
   }
 
   waitingTime[0]=0;            
 
   for(int i=1;i<n;i++)
   {
       waitingTime[i]=0;
       for(int j=0;j<i;j++)
           waitingTime[i]+=burstTime[j];
 
       total+=waitingTime[i];
   }
 
   avg_waitingTime=(float)total/n;      
   total=0;
 
   printf("\nProcess\t    Arrival Time    \tBurst Time\tWaiting Time\tTurnaround Time");
   for(int i=0;i<n;i++)
   {
       int turnAroundTime=burstTime[i]+waitingTime[i];     
       total+=turnAroundTime;
       printf("\nP[%d]\t\t  %d\t\t\t %d\t\t %d\t\t %d",processes[i],arrivalTime[i],burstTime[i],waitingTime[i],turnAroundTime);
   }
 
   avg_turnAroundTime=(float)total/n;     
   printf("\n\nAverage Waiting Time: %f",avg_waitingTime);
   printf("\nAverage Turnaround Time: %f\n",avg_turnAroundTime);
 
   return 0;
}