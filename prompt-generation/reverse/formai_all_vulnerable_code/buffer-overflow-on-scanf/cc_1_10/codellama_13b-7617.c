//Code Llama-13B DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: secure
/* CPU Scheduling Algorithm Example Program in a Secure Style */

#include <stdio.h>
#include <stdlib.h>

#define NUM_PROCESSES 10

typedef struct {
  int pid;
  int arrival_time;
  int burst_time;
  int priority;
  int wait_time;
  int turnaround_time;
} Process;

void schedule(Process processes[], int n) {
  int i, j, min_index, temp;
  for (i = 0; i < n; i++) {
    min_index = i;
    for (j = i + 1; j < n; j++) {
      if (processes[j].arrival_time < processes[min_index].arrival_time) {
        min_index = j;
      }
    }
    temp = processes[i].arrival_time;
    processes[i].arrival_time = processes[min_index].arrival_time;
    processes[min_index].arrival_time = temp;
  }
}

int main() {
  Process processes[NUM_PROCESSES];
  int i, n;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
    scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
  }

  schedule(processes, n);

  for (i = 0; i < n; i++) {
    processes[i].wait_time = processes[i].arrival_time - processes[i].burst_time;
    processes[i].turnaround_time = processes[i].burst_time + processes[i].wait_time;
    printf("Process %d: arrival time = %d, burst time = %d, priority = %d, wait time = %d, turnaround time = %d\n",
           i + 1, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, processes[i].wait_time, processes[i].turnaround_time);
  }

  return 0;
}