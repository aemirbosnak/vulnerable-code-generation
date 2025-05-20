//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

struct Process {
    int pid;
    int bt;//burst time
    int at;//arrival time
    int wt;//wait time
    int tt;//turnaround time
};

void RoundRobin(struct Process proc[], int n, int tq) {
  
  int count, time, remain, flag = 0, time_q;
  remain = n;
  time = 0;
  printf("\n\nPID\t\tBurst Time\tWaiting Time\tTurnaround Time");

  for(count = 0; remain!=0;) {
    if(proc[count].bt <= tq && proc[count].bt > 0) {
      time += proc[count].bt;
      proc[count].bt = 0;
      flag = 1;
    } else if(proc[count].bt > 0) {
      proc[count].bt -= tq;
      time += tq;
    }
    if(proc[count].bt == 0 && flag == 1) {
      remain--;
      printf("\n%d\t\t%d\t\t%d\t\t%d", proc[count].pid, proc[count].at, time - proc[count].at - proc[count].wt, time - proc[count].at);
      proc[count].wt = time - proc[count].at - proc[count].tt;
      flag = 0;
    }
    if(count == n-1) {
      count = 0;
    } else if(proc[count+1].at <= time) {
      count++;
    } else {
      count = 0;
    }
  }
}

int main() {
  int i, n, tq, total_wt = 0, total_tt = 0;
  struct Process proc[10];
  printf("Enter the number of processes:");
  scanf("%d", &n);
  printf("Enter Time quantum:");
  scanf("%d", &tq);

  for(i = 0; i < n; i++) {
    printf("\nEnter Process ID, Arrival Time, Burst Time:");
    scanf("%d %d %d", &proc[i].pid, &proc[i].at, &proc[i].bt);
    proc[i].wt = 0;
    proc[i].tt = 0;
  }

  RoundRobin(proc, n, tq);
  return 0;
}