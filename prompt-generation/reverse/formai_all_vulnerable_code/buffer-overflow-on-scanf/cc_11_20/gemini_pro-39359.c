//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int pid;
  int arrival_time;
  int burst_time;
  int remaining_time;
  int priority;
} process;

int main() {
  int n, i, j, time = 0, completed = 0;
  float avg_waiting_time = 0, avg_turnaround_time = 0;
  process processes[100];

  // Get the number of processes
  printf("Enter the number of processes: ");
  scanf("%d", &n);

  // Get the details of each process
  for (i = 0; i < n; i++) {
    printf("Enter the pid, arrival time, burst time, and priority of process %d: ", i + 1);
    scanf("%d %d %d %d", &processes[i].pid, &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    processes[i].remaining_time = processes[i].burst_time;
  }

  // Sort the processes by arrival time
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (processes[j].arrival_time > processes[j + 1].arrival_time) {
        process temp = processes[j];
        processes[j] = processes[j + 1];
        processes[j + 1] = temp;
      }
    }
  }

  // Run the SJF (shortest job first) scheduling algorithm
  while (completed < n) {
    int min_remaining_time = 999999, min_index = -1;

    // Find the process with the shortest remaining time
    for (i = 0; i < n; i++) {
      if (processes[i].remaining_time < min_remaining_time && processes[i].arrival_time <= time) {
        min_remaining_time = processes[i].remaining_time;
        min_index = i;
      }
    }

    // If no process is found, increase the time by 1
    if (min_index == -1) {
      time++;
      continue;
    }

    // Execute the process
    processes[min_index].remaining_time--;
    time++;

    // If the process is completed, calculate its waiting time and turnaround time
    if (processes[min_index].remaining_time == 0) {
      completed++;
      int waiting_time = time - processes[min_index].arrival_time - processes[min_index].burst_time;
      int turnaround_time = time - processes[min_index].arrival_time;
      avg_waiting_time += waiting_time;
      avg_turnaround_time += turnaround_time;
    }
  }

  // Print the results
  printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for (i = 0; i < n; i++) {
    printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].arrival_time - processes[i].burst_time - processes[i].remaining_time, time - processes[i].arrival_time);
  }

  printf("Average Waiting Time: %.2f\n", avg_waiting_time / n);
  printf("Average Turnaround Time: %.2f\n", avg_turnaround_time / n);

  return 0;
}