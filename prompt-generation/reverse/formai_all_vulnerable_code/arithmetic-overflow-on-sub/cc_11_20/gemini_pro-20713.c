//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

typedef struct process {
  int pid;
  int arrival_time;
  int burst_time;
  int priority;
} process;

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  process *processes = malloc(sizeof(process) * n);
  for (int i = 0; i < n; i++) {
    printf("Enter the details of process %d:\n", i + 1);
    printf("PID: ");
    scanf("%d", &processes[i].pid);
    printf("Arrival time: ");
    scanf("%d", &processes[i].arrival_time);
    printf("Burst time: ");
    scanf("%d", &processes[i].burst_time);
    printf("Priority: ");
    scanf("%d", &processes[i].priority);
  }

  // Sort the processes by arrival time
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (processes[j].arrival_time > processes[j + 1].arrival_time) {
        process temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }

  // Run the scheduling algorithm
  int current_time = 0;
  int completed_processes = 0;
  int waiting_time = 0;
  int turnaround_time = 0;
  while (completed_processes < n) {
    // Find the next process to run
    int next_process = -1;
    for (int i = 0; i < n; i++) {
      if (processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
        if (next_process == -1 || processes[i].priority > processes[next_process].priority) {
          next_process = i;
        }
      }
    }

    // If there are no processes to run, wait for one
    if (next_process == -1) {
      current_time++;
      continue;
    }

    // Run the next process
    current_time += processes[next_process].burst_time;
    waiting_time += current_time - processes[next_process].arrival_time - processes[next_process].burst_time;
    turnaround_time += current_time - processes[next_process].arrival_time;
    completed_processes++;
    processes[next_process].burst_time = 0;
  }

  // Print the results
  printf("Average waiting time: %.2f\n", (float)waiting_time / n);
  printf("Average turnaround time: %.2f\n", (float)turnaround_time / n);

  return 0;
}