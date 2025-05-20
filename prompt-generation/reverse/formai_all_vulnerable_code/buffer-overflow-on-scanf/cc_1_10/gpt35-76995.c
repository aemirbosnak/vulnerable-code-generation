//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#define MAX_PROC 10
#define TIME_QUANTUM 2

// structure for process
struct process{
   int pid; // process ID
   int burst_time; // process burst time
   int arrival_time; // process arrival time
   int waiting_time; // process waiting time
   int turnaround_time; // process turnaround time
   int remaining_time; // process remaining burst time
   int response_time; // process response time
};

// function to calculate waiting time, turnaround time, and response time
void calc_time(struct process p[], int n) {
   int i;
   for(i = 0; i < n; i++) {
      p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
      p[i].response_time = p[i].waiting_time;
   }
}

// function to implement Round Robin CPU scheduling algorithm
void RR(struct process p[], int n) {
   int time = 0, count = 0, remaining_time_sum = 0, i;
   int flag[MAX_PROC];
   int waiting_time_sum = 0;

   // initialize remaining time and flag for all processes
   for(i = 0; i < n; i++) {
      p[i].remaining_time = p[i].burst_time;
      flag[i] = 0;
   }

   // loop until all processes are executed
   while(count < n) {
      remaining_time_sum = 0;
      // traverse through all processes
      for(i = 0; i < n; i++) {
         // if process is ready
         if(p[i].arrival_time <= time && p[i].remaining_time > 0) {
            // if process is running for the first time
            if(flag[i] == 0) {
               p[i].waiting_time = time - p[i].arrival_time;
               flag[i] = 1;
            }
            // if process has already started running
            else {
               p[i].waiting_time += time - p[i].arrival_time;
            }
            // if process can complete within time quantum
            if(p[i].remaining_time <= TIME_QUANTUM) {
               time += p[i].remaining_time;
               remaining_time_sum += p[i].remaining_time;
               p[i].remaining_time = 0;
               count++;
            }
            // if process cannot complete within time quantum
            else {
               time += TIME_QUANTUM;
               remaining_time_sum += TIME_QUANTUM;
               p[i].remaining_time -= TIME_QUANTUM;
            }
         }
      }
      // if no process is ready or all processes have remaining time greater than 0
      if(remaining_time_sum == 0) {
         time++;
      }
   }
   calc_time(p, n);

   // calculate and display average waiting time, turnaround time, and response time
   for(i = 0; i < n; i++) {
      waiting_time_sum += p[i].waiting_time;
   }
   printf("Average Waiting Time: %.2f\n", (float) waiting_time_sum / n);
   waiting_time_sum = 0;
   for(i = 0; i < n; i++) {
      waiting_time_sum += p[i].turnaround_time;
   }
   printf("Average Turnaround Time: %.2f\n", (float) waiting_time_sum / n);
   waiting_time_sum = 0;
   for(i = 0; i < n; i++) {
      waiting_time_sum += p[i].response_time;
   }
   printf("Average Response Time: %.2f\n", (float) waiting_time_sum / n);
}

// main function
int main() {
   int n, i;
   struct process p[MAX_PROC];
   printf("Enter the number of processes: ");
   scanf("%d", &n);
   printf("Enter the process ID, burst time, and arrival time:\n");
   for(i = 0; i < n; i++) {
       scanf("%d %d %d", &p[i].pid, &p[i].burst_time, &p[i].arrival_time);
   }
   RR(p, n);
   return 0;
}