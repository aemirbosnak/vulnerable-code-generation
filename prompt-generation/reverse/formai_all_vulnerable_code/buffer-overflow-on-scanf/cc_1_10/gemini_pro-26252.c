//GEMINI-pro DATASET v1.0 Category: CPU Scheduling Algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int burst_time;
  int arrival_time;
} Process;

typedef struct {
  int start_time;
  int end_time;
  int turnaround_time;
  int waiting_time;
  int response_time;
} Result;

void print_table(Process *processes, int n, Result *results) {
  printf("+-----+-------------+-------------+-------------+-------------+\n");
  printf("| PID | Burst Time  | Arrival Time | Turnaround Time | Waiting Time |\n");
  printf("+-----+-------------+-------------+-------------+-------------+\n");
  for (int i = 0; i < n; i++) {
    printf("| %3d | %10d | %13d | %15d | %13d |\n",
           i + 1, processes[i].burst_time, processes[i].arrival_time,
           results[i].turnaround_time, results[i].waiting_time);
  }
  printf("+-----+-------------+-------------+-------------+-------------+\n");
}

void fcfs(Process *processes, int n) {
  Result *results = malloc(sizeof(Result) * n);
  int current_time = 0;
  for (int i = 0; i < n; i++) {
    results[i].start_time = current_time;
    current_time += processes[i].burst_time;
    results[i].end_time = current_time;
    results[i].turnaround_time = results[i].end_time - processes[i].arrival_time;
    results[i].waiting_time = results[i].turnaround_time - processes[i].burst_time;
    results[i].response_time = results[i].start_time - processes[i].arrival_time;
  }
  print_table(processes, n, results);
  free(results);
}

int main() {
  int n;
  printf("Enter the number of processes: ");
  scanf("%d", &n);
  Process *processes = malloc(sizeof(Process) * n);
  for (int i = 0; i < n; i++) {
    printf("Enter the burst time for process %d: ", i + 1);
    scanf("%d", &processes[i].burst_time);
    printf("Enter the arrival time for process %d: ", i + 1);
    scanf("%d", &processes[i].arrival_time);
  }
  fcfs(processes, n);
  free(processes);
  return 0;
}