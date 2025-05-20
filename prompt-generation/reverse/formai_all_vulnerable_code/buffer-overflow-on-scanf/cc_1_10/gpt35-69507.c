//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: systematic
#include <stdio.h>

int main() {
  int n, bt[20], wt[20], tat[20], avwt = 0, avtat = 0, i, j, temp;
  float total_wt = 0, total_tat = 0;

  printf("Enter number of processes: ");
  scanf("%d", &n);

  printf("\nEnter Burst Time:\n");
  for(i = 0; i < n; i++) {
    printf("P[%d]: ", i+1);
    scanf("%d", &bt[i]);
  }

  // Sorting burst time in ascending order using selection sort
  for(i = 0; i < n-1; i++) {
    for(j = i+1; j < n; j++) {
      if(bt[i] > bt[j]) {
        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;
      }
    }
  }

  // Calculating waiting time and turnaround time
  for(i = 0; i < n; i++) {
    wt[i] = 0;
    tat[i] = bt[i] + wt[i];
    for(j = 0; j < i; j++)
      wt[i] += bt[j];
    tat[i] = wt[i] + bt[i];
    total_wt += wt[i];
    total_tat += tat[i];
  }

  // Calculating average waiting time and average turnaround time
  avwt = total_wt / n;
  avtat = total_tat / n;

  printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");

  for(i = 0; i < n; i++)
    printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i+1, bt[i], wt[i], tat[i]);

  printf("\n\nAverage Waiting Time: %d", avwt);
  printf("\nAverage Turnaround Time: %d", avtat);

  return 0;
}