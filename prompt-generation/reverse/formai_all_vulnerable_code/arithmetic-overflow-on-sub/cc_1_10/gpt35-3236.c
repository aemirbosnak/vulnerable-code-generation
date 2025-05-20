//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Sherlock Holmes
#include<stdio.h>

struct process {
  int pid;
  int burst_time;
  int remaining_time;
};

void swap(struct process* a, struct process* b) {
  struct process temp = *a;
  *a = *b;
  *b = temp;
}

void sort_processes_by_arrival_time(struct process processes[], int n) {
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(processes[j].remaining_time > processes[j+1].remaining_time) {
        swap(&processes[j], &processes[j+1]);
      }
    }
  }
}

int main() {
  int n, quantum;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  struct process processes[n];
  for(int i=0; i<n; i++) {
    printf("\nEnter the Burst Time of process %d: ", i+1);
    scanf("%d", &processes[i].burst_time);
    processes[i].pid = i+1;
    processes[i].remaining_time = processes[i].burst_time;
  }
  printf("\nEnter Time Quantum: ");
  scanf("%d", &quantum);
  sort_processes_by_arrival_time(processes, n);
  int time = 0;
  int turnaround_times[n];
  int waiting_times[n];
  int done = 0;
  while(done < n) {
    for(int i=0; i<n; i++) {
      if(processes[i].remaining_time <= 0) {
        continue;
      }
      if(processes[i].remaining_time <= quantum) {
        time += processes[i].remaining_time;
        processes[i].remaining_time = 0;
        done++;
        waiting_times[i] = time - processes[i].burst_time;
        turnaround_times[i] = time;
      } else {
        time += quantum;
        processes[i].remaining_time -= quantum;
      }
    }
  }
  float avg_waiting_time = 0, avg_turnaround_time = 0;
  printf("\nProcess ID \tBurst Time \tWaiting Time \tTurnaround Time\n");
  for(int i=0; i<n; i++) {
    printf("%d \t\t%d \t\t%d \t\t%d\n", processes[i].pid, processes[i].burst_time, waiting_times[i], turnaround_times[i]);
    avg_waiting_time += waiting_times[i];
    avg_turnaround_time += turnaround_times[i] - processes[i].burst_time;
  }
  printf("\nAverage Waiting Time: %f", avg_waiting_time/n);
  printf("\nAverage Turnaround Time: %f", avg_turnaround_time/n);

  return 0;
}