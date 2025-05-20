//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>

struct process {
   int process_id;
   int arrival_time;
   int burst_time;
   int waiting_time;
   int completion_time;
   int turnaround_time;
};

void roundRobin(struct process *p, int n, int time_quantum) {
   int remaining_burst_time[n];
   for(int i=0; i<n; i++) {
      remaining_burst_time[i] = p[i].burst_time;
   }
   int curr_time = 0;
   while(1) {
      int done = 1;
      for (int i=0; i<n; i++) {
         if (remaining_burst_time[i] > 0) {
            done = 0;
            if (remaining_burst_time[i] > time_quantum) {
               curr_time += time_quantum;
               remaining_burst_time[i] -= time_quantum;
            } else {
               curr_time += remaining_burst_time[i];
               p[i].completion_time = curr_time;
               p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
               p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
               remaining_burst_time[i] = 0;
            }
         }
      }
      if (done == 1) {
         break;
      }
   }
}

void print_avg_times(struct process *p, int n) {
   float avg_waiting_time = 0.0;
   float avg_turnaround_time = 0.0;
   printf("\nProcessID\tArrivalTime\tBurstTime\tWaitingTime\tCompletionTime\tTurnaroundTime\n");
   for (int i=0; i<n; i++) {
      avg_waiting_time += (float)p[i].waiting_time;
      avg_turnaround_time += (float)p[i].turnaround_time;
      printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", p[i].process_id, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].completion_time, p[i].turnaround_time);
   }
   avg_waiting_time /= (float)n;
   avg_turnaround_time /= (float)n;
   printf("\nAverage Waiting Time : %.2f", avg_waiting_time);
   printf("\nAverage Turnaround Time : %.2f\n", avg_turnaround_time);
}

int main() {
   printf("Enter the Total Number of Processes : ");
   int n;
   scanf("%d", &n);

   struct process p[n];

   for (int i=0; i<n; i++) {
      p[i].process_id = i+1;
      printf("\nProcess %d :\n", p[i].process_id);
      printf("Enter the Arrival Time : ");
      scanf("%d", &p[i].arrival_time);
      printf("Enter the Burst Time : ");
      scanf("%d", &p[i].burst_time);
   }

   int time_quantum;
   printf("\nEnter Time Quantum : ");
   scanf("%d", &time_quantum);

   roundRobin(p, n, time_quantum);
   print_avg_times(p, n);

   return 0;
}