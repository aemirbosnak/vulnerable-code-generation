//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: shocked
#include<stdio.h>

int main() {
  int n, i, j, k, l, m; //n is the number of processes, i, j, k, l, m are loop variables
  float wtavg = 0, tatavg = 0; //variables for average waiting time and turnaround time
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int burst_time[n], wait_time[n], turnaround_time[n], process[n];

  //take user input for burst times of processes
  for(i=0;i<n;i++){
      printf("Enter burst time for process %d: ", i+1);
      scanf("%d", &burst_time[i]);
      process[i] = i+1;
  }

  //bubble sort to sort burst times in ascending order
  for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
          if(burst_time[i] > burst_time[j]){
              int temp = burst_time[i];
              burst_time[i] = burst_time[j];
              burst_time[j] = temp;

              temp = process[i];
              process[i] = process[j];
              process[j] = temp;
          }
      }
  }

  //calculate waiting time for processes
  for(i=0;i<n;i++){
      wait_time[i] = 0;
      for(j=0;j<i;j++){
          wait_time[i] += burst_time[j];
      }
      wtavg += wait_time[i];
  }

  wtavg = wtavg/n; //average waiting time calculation

  //calculate turnaround time for processes
  for(i=0;i<n;i++){
      turnaround_time[i] = wait_time[i] + burst_time[i];
      tatavg += turnaround_time[i];
  }

  tatavg = tatavg/n; //average turnaround time calculation

  //display process details
  printf("\nPROCESS       BURST TIME      WAITING TIME        TURNAROUND TIME\n");
  for(i=0;i<n;i++){
      printf("P%d\t\t%d\t\t%d\t\t%d\n", process[i], burst_time[i], wait_time[i], turnaround_time[i]);
  }

  //display average waiting time and turnaround time
  printf("\nAverage Waiting Time: %f", wtavg);
  printf("\nAverage Turnaround Time: %f", tatavg);

  return 0;
}