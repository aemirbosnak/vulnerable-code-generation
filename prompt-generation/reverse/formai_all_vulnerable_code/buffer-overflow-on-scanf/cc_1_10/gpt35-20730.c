//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: unmistakable
#include <stdio.h>

struct process {
   int process_id;
   int arrival_time;
   int burst_time;
   int waiting_time;
   int turnaround_time;
   int priority;
   int completed;
};

int main() {
   int number_of_processes, time_quantum, completion_time = 0, minimum_priority = 99999, current_process = 0;
   float total_waiting_time = 0, total_turnaround_time = 0;

   printf("Enter the number of processes: ");
   scanf("%d", &number_of_processes);

   struct process queue[number_of_processes], completed_processes[number_of_processes];

   for(int i = 0; i < number_of_processes; i++) {
      printf("\n");
      printf("Enter the arrival time for process %d: ", i+1);
      scanf("%d", &queue[i].arrival_time);
      printf("Enter the burst time for process %d: ", i+1);
      scanf("%d", &queue[i].burst_time);
      printf("Enter the priority for process %d: ", i+1);
      scanf("%d", &queue[i].priority);
      queue[i].waiting_time = queue[i].turnaround_time = queue[i].completed = 0;
      queue[i].process_id = i+1;
   }

   printf("\nEnter the time quantum for the algorithm: ");
   scanf("%d", &time_quantum);

   while(1) {
      int flag = 1;
      for(int i = 0; i < number_of_processes; i++) {
        if(queue[i].arrival_time <= completion_time && queue[i].completed == 0) {
            flag = 0;

            if(queue[i].priority < minimum_priority) {
                minimum_priority = queue[i].priority;
                current_process = i;
            }
        }
      }

      if(flag)break;

      int remaining_time = queue[current_process].burst_time;

      if(remaining_time > time_quantum) {
         remaining_time -= time_quantum;
         completion_time += time_quantum;
      }
      else {
         completion_time += remaining_time;
         remaining_time = 0;
         queue[current_process].completed = 1;
         completed_processes[current_process] = queue[current_process];
         completed_processes[current_process].turnaround_time = completion_time - completed_processes[current_process].arrival_time;
         completed_processes[current_process].waiting_time = completed_processes[current_process].turnaround_time - completed_processes[current_process].burst_time;
         total_waiting_time += completed_processes[current_process].waiting_time;
         total_turnaround_time += completed_processes[current_process].turnaround_time;
         minimum_priority = 99999;
      }
      queue[current_process].burst_time = remaining_time;
  }

  printf("\nPID     AT      BT      PT      WT      TT");
  for(int i = 0; i < number_of_processes; i++) {
      printf("\n%d      %d      %d      %d      %d      %d", completed_processes[i].process_id, completed_processes[i].arrival_time, completed_processes[i].burst_time, completed_processes[i].priority, completed_processes[i].waiting_time, completed_processes[i].turnaround_time);
   }

   printf("\n\nAverage waiting time: %0.2f", total_waiting_time/number_of_processes);
   printf("\nAverage turnaround time: %0.2f", total_turnaround_time/number_of_processes);

   return 0;
}