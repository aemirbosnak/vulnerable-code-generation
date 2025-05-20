//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: complex
#include <stdio.h>

int main() {
  int burst_time[20], waiting_time[20], turnaround_time[20], sum_waiting_time = 0, sum_turnaround_time = 0;
  int num_processes, i, j, temp, arrival_time[20];
  float avg_waiting_time=0, avg_turnaround_time=0;

  printf("Enter number of processes: ");
  scanf("%d", &num_processes);

  for(i=0; i<num_processes; i++) {
    printf("Enter arrival time and burst time for process %d: ", i+1);
    scanf("%d%d", &arrival_time[i], &burst_time[i]);
  }

  for(i=0; i<(num_processes-1); i++) {
    for(j=0; j<(num_processes-i-1); j++) {
      if(burst_time[j] > burst_time[j+1]) {
        temp = burst_time[j];
        burst_time[j] = burst_time[j+1];
        burst_time[j+1] = temp;

        temp = arrival_time[j];
        arrival_time[j] = arrival_time[j+1];
        arrival_time[j+1] = temp;
      }
    }
  }

  waiting_time[0] = 0;
  for(i=1; i<num_processes; i++) {
    waiting_time[i] = 0;
    for(j=0; j<i; j++) {
      waiting_time[i] += burst_time[j];
    }
    sum_waiting_time += waiting_time[i];
  }

  avg_waiting_time = (float)sum_waiting_time/num_processes;
  printf("\nAverage waiting time: %.2f", avg_waiting_time);

  turnaround_time[0] = burst_time[0];
  for(i=1; i<num_processes; i++) {
    turnaround_time[i] = 0;
    for(j=0; j<i; j++) {
      turnaround_time[i] += burst_time[j];
    }
    sum_turnaround_time += turnaround_time[i];
  }

  avg_turnaround_time = (float)sum_turnaround_time/num_processes;
  printf("\nAverage turnaround time: %.2f", avg_turnaround_time);

  return 0;
}