//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include<stdio.h>

int main()
{
  int arrivalTime[10], burstTime[10], waitingTime[10], turnaroundTime[10];
  int i, j, n, temp, total = 0, position;
  float waitingAvg, turnaroundAvg;

  printf("\nEnter the number of processes:\n");
  scanf("%d", &n);

  printf("\nEnter the arrival time and burst time of the processes:\n");
  for(i = 0; i < n; i++)
  {
    printf("\nProcess[%d]\n", i + 1);
    printf("Arrival Time:\t");
    scanf("%d", &arrivalTime[i]);
    printf("Burst Time:\t");
    scanf("%d", &burstTime[i]);
  }

  // Bubble sort based on arrival time
  for(i = 0; i < n; i++)
  {
    position = i;
    for(j = i + 1; j < n; j++)
    {
      if(arrivalTime[j] < arrivalTime[position])
      {
        position = j;
      }
    }

    temp = arrivalTime[i];
    arrivalTime[i] = arrivalTime[position];
    arrivalTime[position] = temp;

    temp = burstTime[i];
    burstTime[i] = burstTime[position];
    burstTime[position] = temp;
  }

  // Calculate waiting time
  for(i = 1; i < n; i++)
  {
    waitingTime[i] = 0;
    for(j = 0; j < i; j++)
    {
      waitingTime[i] += burstTime[j];
    }

    total += waitingTime[i];
  }

  waitingAvg = (float)total / n;
  total = 0;
  
  printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time");

  for(i = 0; i < n; i++)
  {
    turnaroundTime[i] = burstTime[i] + waitingTime[i];
    total += turnaroundTime[i];

    printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, arrivalTime[i], burstTime[i], waitingTime[i], turnaroundTime[i]);
  }

  turnaroundAvg = (float)total / n;

  printf("\n\nAverage Waiting Time: %f", waitingAvg);
  printf("\nAverage Turnaround Time: %f", turnaroundAvg);

  return 0;
}