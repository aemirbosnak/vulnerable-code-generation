//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>

int main() {
  printf("Welcome to CPU Scheduling Algorithm Example Program\n");

  int n, total_time = 0, burst_time[20], waiting_time[20], turnaround_time[20], min, temp; 
  float avg_waiting_time, avg_turnaround_time;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  printf("\nEnter Burst Time for Each Process:\n");
  for (int i = 0; i < n; i++) {
    printf("Process [%d]: ", i+1);
    scanf("%d", &burst_time[i]);
  }

  // Bubble Sort for sorting the processes in ascending order
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (burst_time[i] > burst_time[j]) {
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;
      }
    }
  }

  waiting_time[0] = 0;
  for (int i = 1; i < n; i++) {
    waiting_time[i] = 0;
    for (int j = 0; j < i; j++) {
      waiting_time[i] += burst_time[j];
    }
    total_time += waiting_time[i];
  }

  avg_waiting_time = (float)total_time / n;
  total_time = 0;

  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (int i = 0; i < n; i++) {
    turnaround_time[i] = burst_time[i] + waiting_time[i];
    total_time += turnaround_time[i];
    printf("Process [%d]\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], waiting_time[i], turnaround_time[i]);
  }

  avg_turnaround_time = (float)total_time / n;

  printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
  printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

  return 0;
}