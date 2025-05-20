//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: rigorous
#include<stdio.h>

int main() {
   int n, i, j, temp, wt[10], bt[10], tat[10], p[10], priority[10], sum = 0, total_time = 0;
   float avg_tat, avg_wt;
   
   printf("Enter the number of processes: ");
   scanf("%d", &n);
   
   printf("\nEnter the Burst time and Priority of processes:\n");
   
   for(i = 0; i < n; i++) {
      printf("\nProcess %d\nBurst time: ", i+1);
      scanf("%d", &bt[i]);
      printf("Priority: ");
      scanf("%d", &priority[i]);
      p[i] = i+1;          
   }
   
   for(i = 0; i < n; i++) {
      for(j = i+1; j < n; j++) {
         if(priority[i] < priority[j]) {
            temp = priority[i];
            priority[i] = priority[j];
            priority[j] = temp;
            
            temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;
            
            temp = p[i];
            p[i] = p[j];
            p[j] = temp;
         }
      }
   }
   
   wt[0] = 0;
   
   for(i = 1; i < n; i++) {
      wt[i] = 0;
      for(j = 0; j < i; j++)
         wt[i] += bt[j];
   }
   
   for(i = 0; i < n; i++) {
      sum += wt[i];
      tat[i] = wt[i] + bt[i];
      total_time += tat[i];
   }
   
   avg_tat = (float) total_time / n;
   avg_wt = (float) sum / n;
   
   printf("\nProcess\t Burst Time \t Priority \tWaiting Time\tTurnaround Time");
   
   for(i = 0; i < n; i++) {
      printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], bt[i], priority[i], wt[i], tat[i]);
   }
   
   printf("\nAverage Waiting time = %.2f", avg_wt);
   printf("\nAverage Turn Around time = %.2f", avg_tat);
   
   return 0;
}