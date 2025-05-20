//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: beginner-friendly
#include<stdio.h>

int main(){
  int n,i,j,temp,avg_turnaround_time=0,avg_waiting_time=0;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  int process[n],burst_time[n],waiting_time[n],turnaround_time[n];

  for(i=0;i<n;i++){
    printf("Enter the burst time of process %d: ", i+1);
    scanf("%d",&burst_time[i]);
    process[i]=i+1;
  }

  //Sorting the burst times using bubble sort
  for(i=0;i<n-1;i++){
    for(j=0;j<n-i-1;j++){
      if(burst_time[j]>burst_time[j+1]){
        //Swapping the burst time and process id for sorting
        temp=burst_time[j];
        burst_time[j]=burst_time[j+1];
        burst_time[j+1]=temp;

        temp=process[j];
        process[j]=process[j+1];
        process[j+1]=temp;
      }
    }
  }

  waiting_time[0]=0; //waiting time of first process is 0

  //Calculating waiting time
  for(i=1;i<n;i++){
    waiting_time[i]=0;
    for(j=0;j<i;j++){
      waiting_time[i]+=burst_time[j];
    }
  }

  //Calculating turnaround time
  for(i=0;i<n;i++){
    turnaround_time[i]=burst_time[i]+waiting_time[i];
    avg_turnaround_time+=turnaround_time[i];
    avg_waiting_time+=waiting_time[i];
  }

  avg_turnaround_time=avg_turnaround_time/n;
  avg_waiting_time=avg_waiting_time/n;

  printf("\nProcess\t  Burst Time  \tWaiting Time  \tTurnaround Time");

  for(i=0;i<n;i++){
    printf("\n%d \t\t %d \t\t %d \t\t %d", process[i],burst_time[i],waiting_time[i],turnaround_time[i]);
  }

  printf("\n\nAverage waiting time: %d",avg_waiting_time);
  printf("\nAverage turnaround time: %d",avg_turnaround_time);

  return 0;
}