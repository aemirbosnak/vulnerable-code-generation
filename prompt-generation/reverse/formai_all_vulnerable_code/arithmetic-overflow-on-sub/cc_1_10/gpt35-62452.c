//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: curious
#include <stdio.h>

int main() {
  int processes[10], burst_time[10], q, n, i, total_time = 0, temp;
  float avg_wait_time = 0, avg_turnaround_time = 0;

  printf("Enter number of processes (max 10): ");
  scanf("%d", &n);

  printf("Enter the burst time for each process: ");
  for(i = 0; i < n; i++) {
    scanf("%d", &burst_time[i]);
    processes[i] = i;
  }

  printf("Enter time quantum: ");
  scanf("%d", &q);

  printf("\nResult\n");
  printf("===== \n");
  printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
  
  for(total_time = 0, i = 0; n != 0;) {
    if(burst_time[i] <= q && burst_time[i] > 0) {
      total_time += burst_time[i];
      burst_time[i] = 0;
      temp = 1;
    } else if(burst_time[i] > 0) {
      burst_time[i] -= q;
      total_time += q;
    }

    if(burst_time[i] == 0 && temp == 1) {
      n--;
      printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i+1, burst_time[i], total_time - burst_time[i], total_time);
      avg_wait_time += total_time - burst_time[i]; 
      avg_turnaround_time += total_time;
      temp = 0;
    }

    if(i == n - 1) {
      i = 0;
    } else if(total_time >= burst_time[i + 1]) {
      i++;
    } else {
      i = 0;
    }
  }

  printf("\nAverage Waiting Time: %f", avg_wait_time / n);
  printf("\nAverage Turnaround Time: %f", avg_turnaround_time / n);
  
  return 0;
}