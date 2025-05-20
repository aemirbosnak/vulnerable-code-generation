//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: relaxed
#include<stdio.h>

int main(){
  int n, burst_time[20], waiting_time[20], turnaround_time[20], i, j, avg_waiting_time=0, avg_turnaround_time=0;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  printf("Enter Burst Time for each process:\n");
  for(i=0;i<n;i++){
    printf("Burst Time of process %d: ",i+1);
    scanf("%d",&burst_time[i]);
  }
  // First Come First Serve Scheduling Algorithm
  waiting_time[0]=0;
  for(i=1; i<n; i++){
    waiting_time[i]=0;
    for(j=0; j<i; j++){
      waiting_time[i] += burst_time[j];
    }
  }
  printf("\nFCFS Scheduling:\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
  for(i=0; i<n; i++){
    turnaround_time[i] = burst_time[i] + waiting_time[i];
    avg_waiting_time += waiting_time[i];
    avg_turnaround_time += turnaround_time[i];
    printf("\nP%d\t\t%d\t\t%d\t\t%d",i+1,burst_time[i],waiting_time[i],turnaround_time[i]);
  }
  avg_waiting_time/=i;
  avg_turnaround_time/=i;
  printf("\n\nAverage Waiting Time: %d",avg_waiting_time);
  printf("\nAverage Turnaround Time: %d",avg_turnaround_time);
  
  // Shortest Job First Scheduling Algorithm
  int temp, p[20], t=0;
  float avg_waiting=0.0, avg_turnaround=0.0;
  printf("\n\n");  
  printf("\nSJF Scheduling:\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
  for (i=0;i<n;i++){
    p[i]=burst_time[i];
  }
  burst_time[9]=9999;
  for(t=0;t<n;t++){
    int min = 9;
    for(i=0;i<n;i++){
      if(burst_time[i]<burst_time[min] && p[i]!=0){
        min=i;
      }
    }
    p[min]--;
    if(p[min]==0){
      p[min]=9999;
    }
    for(i=0;i<n;i++){
      if(p[i]<burst_time[min] && p[i]!=0){
        waiting_time[i]++;
      }
    }
    if(p[min]==9999){
      turnaround_time[min] = t+1;
      avg_waiting += waiting_time[min];
      avg_turnaround += turnaround_time[min];
      printf("\nP%d\t\t%d\t\t%d\t\t%d",min+1,burst_time[min],waiting_time[min],turnaround_time[min]);
    }
  }
  avg_waiting/=i;
  avg_turnaround/=i;
  printf("\n\nAverage Waiting Time: %f",avg_waiting);
  printf("\nAverage Turnaround Time: %f\n\n",avg_turnaround);
  
  return 0;
}