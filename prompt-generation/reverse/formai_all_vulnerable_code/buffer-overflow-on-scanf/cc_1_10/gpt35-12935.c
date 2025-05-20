//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include<stdio.h>

struct process {
   int process_id;
   int burst_time;
   int waiting_time;
   int turnaround_time;
};

int main() {
   int i, j, n, time_slice;
   int time_slots = 0, total_waiting_time = 0, total_turnaround_time = 0;
   float average_waiting_time, average_turnaround_time;

   printf("Enter the number of processes: ");
   scanf("%d", &n);

   struct process a[n];
   int remaining_time[n];

   for(i = 0; i < n; i++) {
      printf("Enter the burst time of process %d: ", i+1);
      scanf("%d", &a[i].burst_time);
      remaining_time[i] = a[i].burst_time;
      a[i].process_id = i+1;
   }

   printf("Enter the time slice: ");
   scanf("%d", &time_slice);

   // Implementing Round Robin Scheduling
   i = 0;
   while(i < n) {
      if(remaining_time[i] <= time_slice && remaining_time[i] > 0) {
         time_slots += remaining_time[i];
         remaining_time[i] = 0;
         a[i].waiting_time = time_slots - a[i].burst_time;
         a[i].turnaround_time = a[i].waiting_time + a[i].burst_time;
         total_waiting_time += a[i].waiting_time;
         total_turnaround_time += a[i].turnaround_time;
         i++;
      }
      else if(remaining_time[i] > 0) {
         time_slots += time_slice;
         remaining_time[i] -= time_slice;
      }
      else {
         i++;
      }
   }

   average_waiting_time = (float)total_waiting_time / n;
   average_turnaround_time = (float)total_turnaround_time / n;

   printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
   for(i = 0; i < n; i++) {
      printf("%d\t\t%d\t\t%d\t\t%d\n", a[i].process_id, a[i].burst_time, a[i].waiting_time, a[i].turnaround_time);
   }
   printf("\nAverage Waiting Time: %0.2f\n", average_waiting_time);
   printf("Average Turnaround Time: %0.2f\n", average_turnaround_time);

   return 0;
}