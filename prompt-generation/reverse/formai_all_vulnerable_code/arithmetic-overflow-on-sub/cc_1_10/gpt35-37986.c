//FormAI DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a process
typedef struct process {
  int pid; // process ID
  int burst_time; // execution time
  int priority; // priority number
  int waiting_time; // time needed for waiting
  int turnaround_time; // turnaround time (waiting time + burst time)
} process;

// Function to sort processes by their priority
void sort_by_priority(process* p, int n) {
  int i, j;
  process temp;
  for (i = 0; i < n-1; i++) {
    for (j = i+1; j < n; j++) {
      if (p[i].priority > p[j].priority) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }
}

// Function to calculate waiting and turnaround times for processes
void calculate_times(process* p, int n) {
  int i, total_waiting_time = 0, total_turnaround_time = 0;
  p[0].waiting_time = 0;
  p[0].turnaround_time = p[0].burst_time;
  for (i = 1; i < n; i++) {
    p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
    total_waiting_time += p[i].waiting_time;
    p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    total_turnaround_time += p[i].turnaround_time;
  }
  printf("Average waiting time: %f\n", (float)total_waiting_time/n);
  printf("Average turnaround time: %f\n", (float)total_turnaround_time/n);
}

// Function to implement the Priority Scheduling Algorithm
void priority_scheduling(process* p, int n) {
  sort_by_priority(p, n);
  calculate_times(p, n);
}

int main() {
  int n, i;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  process* p = (process*)malloc(n*sizeof(process));
  // Input process details from user
  for (i = 0; i < n; i++) {
    printf("Enter details for process %d:\n", i+1);
    printf("Process ID: ");
    scanf("%d", &p[i].pid);
    printf("Burst Time: ");
    scanf("%d", &p[i].burst_time);
    printf("Priority: ");
    scanf("%d", &p[i].priority);
  }
  priority_scheduling(p, n);
  free(p);
  return 0;
}