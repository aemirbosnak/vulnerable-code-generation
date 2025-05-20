//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: introspective
#include <stdio.h>

int main() {

  int n, burstTime[20], waitingTime[20], turnAroundTime[20], avgWaitingTime = 0, avgTurnAroundTime = 0;

  printf("Enter total number of processes: ");
  scanf("%d", &n);

  // Accept burst time of all processes
  printf("\nEnter burst time for each process:\n");
  for (int i = 0; i < n; i++) {
    printf("Process %d: ", i + 1);
    scanf("%d", &burstTime[i]);
  }

  // Sort burst time in ascending order using Selection sort
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < n; j++) {
      if (burstTime[j] < burstTime[minIndex]) {
        minIndex = j;
      }
    }
    int temp = burstTime[minIndex];
    burstTime[minIndex] = burstTime[i];
    burstTime[i] = temp;
  }

  // Calculate waiting time and turn around time for each process
  waitingTime[0] = 0; // Waiting time for first process is zero
  for (int i = 1; i < n; i++) {
    waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
  }
  for (int i = 0; i < n; i++) {
    turnAroundTime[i] = waitingTime[i] + burstTime[i];
  }

  // Calculate average waiting time and turn around time
  for (int i = 0; i < n; i++) {
    avgWaitingTime += waitingTime[i];
    avgTurnAroundTime += turnAroundTime[i];
  }
  avgWaitingTime /= n;
  avgTurnAroundTime /= n;

  // Display results
  printf("\nProcess\tBurst Time\tWaiting Time\tTurn Around Time\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burstTime[i], waitingTime[i], turnAroundTime[i]);
  }
  printf("\nAverage waiting time: %d\n", avgWaitingTime);
  printf("Average turn around time: %d\n", avgTurnAroundTime);

  return 0;
}