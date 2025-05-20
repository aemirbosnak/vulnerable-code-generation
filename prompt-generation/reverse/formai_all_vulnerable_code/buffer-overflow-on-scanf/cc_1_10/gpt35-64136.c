//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct process
{
   int pid; 
   int burst_time;
   int arrival_time; 
   int waiting_time;
   int turnaround_time; 
   int priority;
   int executed; 
};

int main()
{
   int n, i, j;
   float avg_wt = 0, avg_tat = 0;
   printf("Enter the number of processes:");
   scanf("%d", &n);
   struct process p[n];
   printf("Enter process details - PID, arrival time, burst time, and priority:\n");
   for(i = 0; i < n; i++)
   {
      scanf("%d%d%d%d", &p[i].pid, &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
      p[i].executed = 0; 
   }
   int time = 0, min_priority;
   printf("Gantt Chart:\n");
   printf("0|");
   for(i = 0; i < n; )
   {
      min_priority = 9999;
      for(j = 0; j < n; j++)
      {
         if(p[j].arrival_time <= time && p[j].executed == 0)
         {
            if(p[j].priority < min_priority)
            {
               min_priority = p[j].priority;
               i = j;
            }
         }
      }
      printf(" P%d (%d)|", p[i].pid, time + p[i].burst_time - p[i].arrival_time);
      time += p[i].burst_time;
      p[i].turnaround_time = time - p[i].arrival_time;
      p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
      avg_wt += p[i].waiting_time;
      avg_tat += p[i].turnaround_time;
      p[i].executed = 1; 
   }
   printf("\n\nProcess\t Arrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");


   for(i = 0; i < n; i++)
   {
      printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].waiting_time, p[i].turnaround_time);
   }
   printf("Average waiting time: %.2f\n", avg_wt / n);
   printf("Average turnaround time: %.2f\n", avg_tat / n);

   return 0;
}